/*
 * 01-slen.c
 *
 *  Created on: Apr 23, 2011
 *      Author: blabos
 */

#include <stdio.h>
#include "../string.h"

int main(int argc, char** argv) {
    char* str1 = "";
    char* str2 = "Hello World!!!";
    char* str3 = 0;
    
    int s;
    
    printf("\nTesting int slen(const char* str);\n");
    
    printf("Empty string:                        ");
    s = slen(str1);
    if (s == 0) {
        printf("OK\n");
    }
    else {
        printf("FAIL\n");
        printf("Expected %d, found %d\n", 0, s);
        return -1;
    }
    
    printf("Normal string:                       ");
    s = slen(str2);
    if (s == 14) {
        printf("OK\n");
    }
    else {
        printf("FAIL\n");
        printf("Expected %d, found %d\n", 14, s);
        return -1;
    }
    
    printf("Null string:                         ");
    s = slen(str3);
    if (s == 0) {
        printf("OK\n");
    }
    else {
        printf("FAIL\n");
        printf("Expected %d, found %d\n", 0, s);
        return -1;
    }
    
    return 0;
}
