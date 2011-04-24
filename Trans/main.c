/*
 * main.c
 *
 *  Created on: Apr 23, 2011
 *      Author: blabos isto È um teste
 */

#include <stdlib.h>
#include <stdio.h>

#include "string.h"
#include "reserved_words.h"
#include "identifiers.h"

#define BUFF_SIZE       4096

#define ERR_USAGE       -1
#define ERR_NO_INPUT    -2
#define ERR_NO_OUTPUT   -3
#define ERR_SYNTAX      -4

int main(int argc, char** argv) {
    /**
     * while has input
     * 	read next token
     * 	if token is a reserved word then search on table and print
     * 	else if token is an identifier then put it into table and print
     * 	else print token
     */
    FILE* fpin;
    FILE* fpout;

    char read_buffer[BUFF_SIZE];
    char token[BUFF_SIZE];

    int beg, idx;
    int status = 0;
    char curr_char;

    if (argc != 3) {
        fprintf(stderr, "Usage:\n    %s input.file output.file\n", argv[0]);
        return ERR_USAGE;
    }

    if ((fpin = fopen(argv[1], "r")) != NULL) {
        fprintf(stderr, "Cannot open file '%s' for input\n", argv[1]);
        return ERR_NO_INPUT;
    }

    if ((fpout = fopen(argv[2], "w")) != NULL) {
        fprintf(stderr, "Cannot open file '%s' for output\n", argv[2]);
        return ERR_NO_OUTPUT;
    }

    /**
     * Comece a processar o arquivo
     */
    goto read_data;

    /**
     * Leia a próxima linha do arquivo.
     */
    read_data: beg = idx = 0;
    if (fgets(buffer, BUFF_SIZE, fpin)) {
        goto begin;
    } else {
        goto end;
    }

    /**
     * Processe o primeiro caracter para verificar qual o estado atual
     */
    begin: curr_char = buffer[idx++];
    if (is_alpha(curr_char)) {
        beg = idx - 1;

        goto alpha;
    } else if (is_number(curr_char)) {
        beg = idx - 1;

        goto number;
    } else if (is_space(curr_char)) {
        goto space;
    } else if (is_symbol(curr_char)) {
        beg = idx - 1;

        goto symbol;
    } else if (is_null(curr_char)) {
        goto read_data;
    } else {
        goto error;
    }

    /**
     * Caractere corrente é alfabético (inicia variável ou palavra reservada)
     * Os próximos caracteres válidos são:
     *   a) letras, números (continue);
     *   b) espaços, símbolos, null (grave o token alfanumérico;
     * Qualquer outro é erro
     */
    alpha: curr_char = buffer[idx++];
    if (is_alnum(curr_char)) {
        goto alpha;
    } else if (is_space(curr_char)) {
        subs(token, buffer, beg, idx - beg);
        save_alnum_token(fpout, token);

        goto space;
    } else if (is_symbol(curr_char)) {
        subs(token, buffer, beg, idx - beg);
        save_alnum_token(fpout, token);
        beg = idx - 1;

        goto symbol;
    } else if (is_null(curr_char)) {
        subs(token, buffer, beg, idx - beg);
        save_alnum_token(fpout, token);

        goto read_data;
    } else {
        goto error;
    }

    /**
     * Caracter corrente é um número
     * Os próximos caracteres válidos são:
     *   a) outros números (continue);
     *   b) espaços, símbolos, null (grave o token numérico);
     * Qualquer outro é erro;
     */
    number: curr_char = buffer[idx++];
    if (is_number(curr_char)) {
        goto number;
    } else if (is_space(curr_char)) {
        subs(token, buffer, beg, idx - beg);
        fprintf(fpout, "N(%s) ", token);

        goto space;
    } else if (is_symbol(curr_char)) {
        subs(token, buffer, beg, idx - beg);
        fprintf(fpout, "N(%s) ", token);

        goto symbol;
    } else if (is_null(curr_char)) {
        subs(token, buffer, beg, idx - beg);
        fprintf(fpout, "N(%s) ", token);

        goto read_data;
    } else {
        goto error;
    }

    /**
     * Caracter corrente é um 'espaço' (\n, \t, " ")
     * Ignore e vá para o próximo
     */
    space: curr_char = buffer[idx++];
    if (is_alpha(curr_char)) {
        beg = idx - 1;

        goto alpha;
    } else if (is_number(curr_char)) {
        beg = idx - 1;

        goto number;
    } else if (is_space(curr_char)) {
        goto space;
    } else if (is_symbol(curr_char)) {
        beg = idx - 1;

        goto symbol;
    } else if (is_null(curr_char)) {
        goto read_data;
    } else {
        goto error;
    }

    /**
     * Caracter corrente é um símbolo
     * Os próximos caracteres válidos são:
     *   a) outros símbolos (continue);
     *   b) letras, números, espaços, null (grave o token diretamente);
     * Qualquer outro é erro;
     */
    symbol: curr_char = buffer[idx++];
    if (is_alpha(curr_char)) {
        subs(token, buffer, beg, idx - beg);
        fprintf(fpout, "%s ", token);

        beg = idx - 1;
        goto alpha;
    } else if (is_number(curr_char)) {
        subs(token, buffer, beg, idx - beg);
        fprintf(fpout, "%s ", token);

        beg = idx - 1;
        goto number;
    } else if (is_space(curr_char)) {
        subs(token, buffer, beg, idx - beg);
        fprintf(fpout, "%s ", token);

        goto space;
    } else if (is_symbol(curr_char)) {
        goto symbol;
    } else if (is_null(curr_char)) {
        subs(token, buffer, beg, idx - beg);
        fprintf(fpout, "%s ", token);

        goto read_data;
    } else {
        goto error;
    }
    
    error: status = ERR_SYNTAX;

    end: beg = idx = 0;
    fclose(fpin);
    fclose(fpout);

    return EXIT_SUCCESS;
}
