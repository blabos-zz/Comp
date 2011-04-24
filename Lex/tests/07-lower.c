/*
 * 07-lower.c
 *
 *  Created on: Apr 23, 2011
 *      Author: blabos
 */


#include <stdio.h>
#include "../string.h"

#define MAX 10

int main(int argc, char** argv) {
    char str0[MAX] = {'0','1','A','B','C','\t','\n','D','E','\0'};
    
    int c;
    
    printf("\nTesting void lower(char* str);\n");
    
    printf("Single lower:                        ");
    lower(str0);
    c = scmp(str0, "01abc\t\nde\0", MAX);
    if (c == 0) {
        printf("OK\n");
    }
    else {
        printf("FAIL\n");
        printf("Expected %d, found %d\n", 0, c);
        return -1;
    }
    
    return 0;
}
