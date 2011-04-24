/*
 * 02-scmp.c
 *
 *  Created on: Apr 23, 2011
 *      Author: blabos
 */

#include <stdio.h>
#include "../string.h"

#define MAX 10

int main(int argc, char** argv) {
    char* str1 = "";
    char* str2 = "";
    char* str3 = "abc";
    char* str4 = "ABC";
    char* str5 = "abcd";
    char* str6 = "abce";
    char* str7 = 0;
    
    int l1 = 3;
    
    int c;
    
    printf("\nTesting int scmp(const char* first, const char* second, "
            "int max);\n");
    
    printf("Empty strings:                       ");
    c = scmp(str1, str2, l1);
    if (c == 0) {
        printf("OK\n");
    }
    else {
        printf("FAIL\n");
        printf("Expected %d, found %d\n", 0, c);
        return -1;
    }
    
    printf("Zero length strings:                 ");
    c = scmp(str1, str2, 0);
    if (c == 0) {
        printf("OK\n");
    }
    else {
        printf("FAIL\n");
        printf("Expected %d, found %d\n", 0, c);
        return -1;
    }
    
    printf("Null strings #1:                     ");
    c = scmp(str7, str1, l1);
    if (c == 0) {
        printf("OK\n");
    }
    else {
        printf("FAIL\n");
        printf("Expected %d, found %d\n", 0, c);
        return -1;
    }
    
    printf("Null strings #2:                     ");
    c = scmp(str1, str7, l1);
    if (c == 0) {
        printf("OK\n");
    }
    else {
        printf("FAIL\n");
        printf("Expected %d, found %d\n", 0, c);
        return -1;
    }
    
    printf("Same strings:                        ");
    c = scmp(str3, str3, l1);
    if (c == 0) {
        printf("OK\n");
    }
    else {
        printf("FAIL\n");
        printf("Expected %d, found %d\n", 0, c);
        return -1;
    }
    
    printf("Truncated strings:                   ");
    c = scmp(str5, str5, l1);
    if (c == 0) {
        printf("OK\n");
    }
    else {
        printf("FAIL\n");
        printf("Expected %d, found %d\n", 0, c);
        return -1;
    }
    
    printf("Diferent strings #1 (a < b):         ");
    c = scmp(str5, str6, MAX);
    if (c == -1) {
        printf("OK\n");
    }
    else {
        printf("FAIL\n");
        printf("Expected %d, found %d\n", -1, c);
        return -1;
    }
    
    printf("Diferent strings #2 (a > b):         ");
    c = scmp(str6, str5, MAX);
    if (c == 1) {
        printf("OK\n");
    }
    else {
        printf("FAIL\n");
        printf("Expected %d, found %d\n", 1, c);
        return -1;
    }
    
    printf("Diferent strings #3 (a > B):         ");
    c = scmp(str3, str4, MAX);
    if (c == 32) {
        printf("OK\n");
    }
    else {
        printf("FAIL\n");
        printf("Expected %d, found %d\n", 32, c);
        return -1;
    }
    
    printf("Diferent strings #4 (A < b):         ");
    c = scmp(str4, str3, MAX);
    if (c == -32) {
        printf("OK\n");
    }
    else {
        printf("FAIL\n");
        printf("Expected %d, found %d\n", -32, c);
        return -1;
    }
    
    return 0;
}

