/*
 * identifiers.c
 *
 *  Created on: Apr 23, 2011
 *      Author: blabos
 */

#include "identifiers.h"
#include "string.h"
#include <stdio.h>


#define MAX_IDS     4096
#define MAX_STR     31


static char id_table[MAX_IDS][MAX_STR];
static int curr_ident = 0;


void print_id_table() {
    int i;
    
    printf("Identifiers Table:\n\n");
    for (i = 0; i < curr_ident; i++) {
        printf("[%04d]:[%30s]\n", i, id_table[i]);
    }
}

void save_id_table(char* filename) {
    int i;
    char buffer[MAX_STR];
    FILE* fp;
    
    scpy(buffer, filename, MAX_STR);
    scat(buffer, ".ident", MAX_STR);
    
    if (fp = fopen(buffer,"w")) {
        fprintf(fp, "Identifiers Table:\n\n");
        for (i = 0; i < curr_ident; i++) {
            fprintf(fp, "[%04d]:[%30s]\n", i, id_table[i]);
        }
        
        fclose(fp);
    }
}

int index_of_identifier(char* identifier) {
    int i;
    
    for (i = 0; i < curr_ident; i++) {
        if (scmp(identifier, id_table[i], MAX_STR) == 0) return i;
    }
    
    if (curr_ident < MAX_IDS) {
        scpy(id_table[curr_ident], identifier, MAX_STR);
        curr_ident++;
        return curr_ident - 1;
    }
    else {
        return -1;
    }
}
