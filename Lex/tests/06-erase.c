/*
 * 06-erase.c
 *
 *  Created on: Apr 23, 2011
 *      Author: blabos
 */


#include <stdio.h>
#include "../string.h"

#define MAX 10

int main(int argc, char** argv) {
    char str0[MAX] = {'a','b','c','d','e','f','g','h','i','\0'};
    char str1[MAX];
    
    int c;
    
    printf("\nTesting void erase(char* str, int pos, int count);\n");
    
    printf("Single erase:                        ");
    scpy(str1, str0, MAX);
    erase(str1, 3, 3);
    c = scmp(str1, "abcghi", MAX);
    if (c == 0) {
        printf("OK\n");
    }
    else {
        printf("FAIL\n");
        printf("Expected %d, found %d\n", 0, c);
        return -1;
    }
    
    printf("Erasing before first char:           ");
    scpy(str1, str0, MAX);
    erase(str1, -3, 7);
    c = scmp(str1, "efghi", MAX);
    if (c == 0) {
        printf("OK\n");
    }
    else {
        printf("FAIL\n");
        printf("Expected %d, found %d\n", 0, c);
        return -1;
    }
    
    printf("Erasing after last char:             ");
    scpy(str1, str0, MAX);
    erase(str1, 5, 7);
    c = scmp(str1, "abcde", MAX);
    if (c == 0) {
        printf("OK\n");
    }
    else {
        printf("FAIL\n");
        printf("Expected %d, found %d\n", 0, c);
        return -1;
    }
    
    printf("Erasing out of bounds:               ");
    scpy(str1, str0, MAX);
    erase(str1, 20, 11);
    c = scmp(str1, str0, MAX);
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
