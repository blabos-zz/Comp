/*
 * 05-subs.c
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
    
    printf("\nTesting void subs(char* sub, const char* orig, int from, "
            "int count);\n");
    
    printf("Single substring:                    ");
    subs(str1, str0, 3, 3);
    c = scmp(str1, "def", MAX);
    if (c == 0) {
        printf("OK\n");
    }
    else {
        printf("FAIL\n");
        printf("Expected %d, found %d\n", 0, c);
        return -1;
    }
    
    printf("Out of bounds substring #1:          ");
    subs(str1, str0, 8, 3);
    c = scmp(str1, "i", MAX);
    if (c == 0) {
        printf("OK\n");
    }
    else {
        printf("FAIL\n");
        printf("Expected %d, found %d\n", 0, c);
        return -1;
    }
    
    printf("Out of bounds substring #2:          ");
    subs(str1, str0, 20, 3);
    c = scmp(str1, "", MAX);
    if (c == 0) {
        printf("OK\n");
    }
    else {
        printf("FAIL\n");
        printf("Expected %d, found %d\n", 0, c);
        return -1;
    }
    
    printf("Out of bounds substring #3:          ");
    subs(str1, str0, 5, 20);
    c = scmp(str1, "fghi", MAX);
    if (c == 0) {
        printf("OK\n");
    }
    else {
        printf("FAIL\n");
        printf("Expected %d, found %d\n", 0, c);
        return -1;
    }
    
    printf("Out of bounds substring #4:          ");
    scpy(str1, "", MAX);
    subs(str1, str0, -1, MAX);
    c = scmp(str1, "", MAX);
    if (c == 0) {
        printf("OK\n");
    }
    else {
        printf("FAIL\n");
        printf("Expected %d, found %d\n", 0, c);
        return -1;
    }
    
    printf("Out of bounds substring #5:          ");
    scpy(str1, "", MAX);
    subs(str1, str0, 0, -1);
    c = scmp(str1, "", MAX);
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
