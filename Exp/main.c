/*
 * main.c
 *
 *  Created on: May 18, 2011
 *      Author: blabos
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "exp.h"

int main(int argc, char** argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage:\n\t%s <expression>\n", argv[0]);
        return -1;
    }
    
    return eval(argv[1], strlen(argv[0]));
}
