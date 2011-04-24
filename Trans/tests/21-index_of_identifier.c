/*
 * 21-index_of_identifier.c
 *
 *  Created on: Apr 23, 2011
 *      Author: blabos
 */


#include <stdio.h>
#include "../identifiers.h"

int main(int argc, char** argv) {
    int index;
    
    printf("\nTesting void print_id_table();\n");
    
    printf("Finding 'foo' #1:                    ");
    index = index_of_identifier("foo");
    if (index == 0) {
        printf("OK\n");
    }
    else {
        printf("FAIL\n");
        printf("Expected %d, found %d\n", 0, index);
        return -1;
    }
    
    printf("Finding 'bar' #1:                    ");
    index = index_of_identifier("bar");
    if (index == 1) {
        printf("OK\n");
    }
    else {
        printf("FAIL\n");
        printf("Expected %d, found %d\n", 1, index);
        return -1;
    }
    
    printf("Finding 'etc' #1:                    ");
    index = index_of_identifier("etc");
    if (index == 2) {
        printf("OK\n");
    }
    else {
        printf("FAIL\n");
        printf("Expected %d, found %d\n", 2, index);
        return -1;
    }
    
    printf("Finding 'foo' #2:                    ");
    index = index_of_identifier("foo");
    if (index == 0) {
        printf("OK\n");
    }
    else {
        printf("FAIL\n");
        printf("Expected %d, found %d\n", 0, index);
        return -1;
    }
    
    printf("Finding 'bar' #2:                    ");
    index = index_of_identifier("bar");
    if (index == 1) {
        printf("OK\n");
    }
    else {
        printf("FAIL\n");
        printf("Expected %d, found %d\n", 1, index);
        return -1;
    }
    
    printf("Finding 'etc' #2:                    ");
    index = index_of_identifier("etc");
    if (index == 2) {
        printf("OK\n");
    }
    else {
        printf("FAIL\n");
        printf("Expected %d, found %d\n", 2, index);
        return -1;
    }
    
    print_id_table();
    
    return 0;
}
