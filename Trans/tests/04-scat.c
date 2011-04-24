/*
 * 04-scat.c
 *
 *  Created on: Apr 23, 2011
 *      Author: blabos
 */


#include <stdio.h>
#include "../string.h"

#define MAX 10

int main(int argc, char** argv) {
    char str0[MAX] = {'x','x','x','x','x','x','x','x','x','\0'};
    char str1[MAX];
    char* str2 = "abc";
    char* str3 = "def";
    char* str4 = 0;
    
    int c;
    
    printf("\nTesting void scat(char* dest, const char* src, int max);\n");
    
    printf("Single concatenation:                ");
    scpy(str1, str2, MAX);
    scat(str1, str3, MAX);
    c = scmp(str1, "abcdef", MAX);
    if (c == 0) {
        printf("OK\n");
    }
    else {
        printf("FAIL\n");
        printf("Expected %d, found %d\n", 0, c);
        return -1;
    }
    
    printf("Extra sized concatenation:           ");
    scpy(str1, str2, MAX);
    scat(str1, str0, MAX);
    c = scmp(str1, "abcxxxxxx\0", MAX);
    if (c == 0) {
        printf("OK\n");
    }
    else {
        printf("FAIL\n");
        printf("Expected %d, found %d\n", 0, c);
        return -1;
    }
    
    printf("Null concatenation:                  ");
    scpy(str1, str2, MAX);
    scat(str1, str4, MAX);
    c = scmp(str1, "abc", MAX);
    if (c == 0) {
        printf("OK\n");
    }
    else {
        printf("FAIL\n");
        printf("Expected %d, found %d\n", 0, c);
        return -1;
    }
    
    printf("Null destination:                    ");
    scpy(str1, str2, MAX);
    scat(str4, str1, MAX);
    c = scmp(str4, "", MAX);
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
