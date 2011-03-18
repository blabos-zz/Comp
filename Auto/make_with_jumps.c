/*
 * make_with_jumps.c
 *
 *  Created on: Mar 13, 2011
 *      Author: blabos
 */
#include <stdio.h>
#include <string.h>

#include "make_with_jumps.h"


int make_with_jumps(args_t* args, char* outfile) {
    FILE* fp;
    int i, j, count, tr_idx;
    int status = 0;
    char filename[MAX_BUFF];
    
    strncpy(filename, "jumps-", 6);
    strncat(filename, outfile, MAX_BUFF - 6);
    
    if ((fp = fopen(filename, "w")) != NULL) {
        /**
         * Grava no arquivo o início do main do autômato
         */
        SAVE(fp, "int main(int argc, char** argv) {\n");
        SAVE(fp, "    int curr  = -1;\n");
        SAVE(fp, "    char* str = argv[1];\n\n");
        SAVE(fp, "    if (argc != 2) goto error;\n");
        
        /**
         * Itera por todos os estados na tabela de transição
         */
        for (i = 0; i < args->num_states; i++) {
            SAVE(fp, "\n    %s:\n         curr++;\n\n", args->states[i]);
            
            /**
             * Verifica se o estado atual é final, para gerar o código que
             * checa se a string de entrada já acabou, de modo a verificar
             * o caso de sucesso
             */
            if (is_final_state(args, i)) {
                SAVE(fp, "        if (str[curr] == '\\0') ");
                SAVE(fp, "goto success;\n\n");
            }
            
            /**
             * Para cada estado, itera sobre todas as suas possíves transições
             * gerando o código equivalente no autômato
             */
            count = 0;
            
            for (j = 0; j < args->num_symbols; j++) {
                tr_idx = i * args->num_states + j;
                if (args->transitions[tr_idx] >= 0) {
                    if (count > 0) {
                        SAVE(fp, "        else ");
                    }
                    else {
                        SAVE(fp, "             ");
                    }
                    
                    count++;
                    
                    SAVE(fp, "if(str[curr] == '%c') goto %s;\n",
                            args->symbols[j],
                            args->states[args->transitions[tr_idx]]);
                }
            }
            
            if (count > 0) {
                SAVE(fp, "        else ");
            }
            else {
                SAVE(fp, "        ");
            }
            
            SAVE(fp, "goto error;\n");
        }
        
        /**
         * Gera os estados de erro (retorno -1 -> 255) e sucesso (retorno 0)
         */
        SAVE(fp, "\n    error:\n        return -1;\n");
        SAVE(fp, "\n    success:\n        return 0;\n}\n\n");
        
        fclose (fp);
    }
    else {
        fprintf(stderr, "Falha ao tentar criar arquivo de saida '%s'\n",
                outfile);
        status = -2;
    }
    
    return status;
}
