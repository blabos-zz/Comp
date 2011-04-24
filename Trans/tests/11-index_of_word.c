/*
 * 11-index_of_word.c
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
    index = index_of_word("else");
    if (index == 0) {
        printf("OK\n");
    }
    else {
        printf("FAIL\n");
        printf("Expected %d, found %d\n", 0, index);
        return -1;
    }
    
    printf("Finding 'to':                        ");
    index = index_of_word("to");
    if (index == 9) {
        printf("OK\n");
    }
    else {
        printf("FAIL\n");
        printf("Expected %d, found %d\n", 9, index);
        return -1;
    }
    
    printf("Finding 'bla':                       ");
    index = index_of_word("bla");
    if (index == -1) {
        printf("OK\n");
    }
    else {
        printf("FAIL\n");
        printf("Expected %d, found %d\n", -1, index);
        return -1;
    }
    
    printf("Finding 'ELSE':                      ");
    index = index_of_word("ELSE");
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
