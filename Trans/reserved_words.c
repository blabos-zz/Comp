/*
 * reserved_words.c
 *
 *  Created on: Apr 23, 2011
 *      Author: blabos
 */

#include "reserved_words.h"
#include "string.h"

#define TABLE_SIZE  7
#define WORD_LEN    10

const char* table[TABLE_SIZE + 1] = { "else", "go", "if", "let",
        "print", "then", "to", 0 };

int _find_rw(char* word, int from, int to);

int index_of(char* word) {
    return _find_rw(word, 0, TABLE_SIZE);
}

int _find_rw(char* word, int from, int to) {
    if (from > to)
        return -1;

    int idx = (from + to) / 2;
    int cmp = scmp(word, table[idx], WORD_LEN);

    if (cmp == 0)
        return idx;
    else if (cmp < 0)
        return _find_rw(word, from, idx - 1);
    else
        return _find_rw(word, idx + 1, to);
}
