/*
 * 03-scpy.c
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
    char str2[MAX];
    char* str3 = "";
    char* str4 = 0;
    
    int c;
    
    printf("\nTesting void scpy(char* dst, const char* src, int max);\n");
    
    printf("Full buffer to buffer copy:          ");
    scpy(str1, str0, MAX);
    c = scmp(str1, str0, MAX);
    if (c == 0) {
        printf("OK\n");
    }
    else {
        printf("FAIL\n");
        printf("Expected %d, found %d\n", 0, c);
        return -1;
    }
    
    printf("Truncated copy:                      ");
    scpy(str1, str0, 5);
    c = scmp(str1, "xxxx\0", MAX);
    if (c == 0) {
        printf("OK\n");
    }
    else {
        printf("FAIL\n");
        printf("Expected %d, found %d\n", 0, c);
        return -1;
    }
    
    printf("Half buffer to buffer copy:          ");
    scpy(str2, str1, MAX);
    c = scmp(str2, "xxxx\0", MAX);
    if (c == 0) {
        printf("OK\n");
    }
    else {
        printf("FAIL\n");
        printf("Expected %d, found %d\n", 0, c);
        return -1;
    }
    
    printf("Empty string copy:                   ");
    scpy(str1, str3, MAX);
    c = scmp(str1, "", MAX);
    if (c == 0) {
        printf("OK\n");
    }
    else {
        printf("FAIL\n");
        printf("Expected %d, found %d\n", 0, c);
        return -1;
    }
    
    printf("Null string copy:                    ");
    scpy(str1, str4, MAX);
    c = scmp(str1, "", MAX);
    if (c == 0) {
        printf("OK\n");
    }
    else {
        printf("FAIL\n");
        printf("Expected %d, found %d\n", 0, c);
        return -1;
    }
    
    printf("Null destination string copy:        ");
    scpy(str4, str0, MAX);
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
