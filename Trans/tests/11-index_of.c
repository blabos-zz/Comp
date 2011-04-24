/*
 * 11-index_of.c
 *
 *  Created on: Apr 23, 2011
 *      Author: blabos
 */


#include <stdio.h>
#include "../reserved_words.h"

int main(int argc, char** argv) {
    int index;
    
    printf("\nTesting void erase(char* str, int pos, int count);\n");
    
    printf("Finding 'else':                      ");
    index = index_of("else");
    if (index == 0) {
        printf("OK\n");
    }
    else {
        printf("FAIL\n");
        printf("Expected %d, found %d\n", 0, index);
        return -1;
    }
    
    printf("Finding 'to':                        ");
    index = index_of("to");
    if (index == 6) {
        printf("OK\n");
    }
    else {
        printf("FAIL\n");
        printf("Expected %d, found %d\n", 6, index);
        return -1;
    }
    
    printf("Finding 'bla':                       ");
    index = index_of("bla");
    if (index == -1) {
        printf("OK\n");
    }
    else {
        printf("FAIL\n");
        printf("Expected %d, found %d\n", -1, index);
        return -1;
    }
    
    printf("Finding 'ELSE':                      ");
    index = index_of("ELSE");
    if (index == -1) {
        printf("OK\n");
    }
    else {
        printf("FAIL\n");
        printf("Expected %d, found %d\n", -1, index);
        return -1;
    }
    
    return 0;
}
