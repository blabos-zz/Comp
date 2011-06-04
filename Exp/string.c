/*
 * string.c
 *
 *  Created on: Apr 23, 2011
 *      Author: blabos
 */

#include "string.h"
#include <stdio.h>

int slen(const char* str) {
    int count = 0;
    while (str && str[count])
        count++;
    return count;
}

int scmp(const char* first, const char* second, int max) {
    int diff, i;
    diff = i = -1;

    if (max <= 0 || first == 0 || second == 0)
        return 0;

    do {
        i++;
        diff = first[i] - second[i];
    } while (first[i] && second[i] && !diff && i < max);

    return diff;
}

void scpy(char* dst, const char* src, int max) {
    int i = 0;

    if (dst == 0)
        return;

    while (src && src[i] && i < max - 1) {
        dst[i] = src[i];
        i++;
    }

    dst[i] = '\0';
}

void scat(char* dst, const char* src, int max) {
    if (!src || !dst)
        return;

    int dstlen = slen(dst);
    int srclen = slen(src);

    int i = dstlen;
    int j = 0;

    while ((i < (max - 1)) && (j < srclen)) {
        dst[i++] = src[j++];
    }
    dst[i] = '\0';
}

void subs(char* sub, const char* orig, int from, int count) {
    if (!sub || !orig || from < 0 || count <= 0)
        return;

    int i = 0;
    int j = from;
    int olen = slen(orig);

    int max = olen - from;
    max = count > max ? max : count;

    while (i < max && j < olen) {
        sub[i++] = orig[j++];
    }

    sub[i] = '\0';
}

void erase(char* str, int pos, int count) {
    if (!str)
        return;

    int len = slen(str);
    int i = pos;
    int j = pos + count;

    i = i >= 0 ? i : 0;
    i = i < len ? i : len;
    j = j >= 0 ? j : 0;

    while ((str[j] != '\0') && (j < len)) {
        str[i] = str[j];
        i++;
        j++;
    }

    str[i] = '\0';
}

void lower(char* str) {
    while (*str) {
        if (*str >= 65 && *str <= 90)
            *str += 32;
        str++;
    }
}

int is_alpha(unsigned char c) {
    return ((c >= 65 && c <= 90) || (c >= 97 && c <= 122));
}

int is_number(unsigned char c) {
    return (c >= 48 && c <= 57);
}

int is_alnum(unsigned char c) {
    return (is_alpha(c) || is_number(c));
}

int is_space(unsigned char c) {
    return (c >= 1 && c <= 32);
}

int is_null(unsigned char c) {
    return (c == 0);
}

int is_del(unsigned char c) {
    return (c == 127);
}

int is_comment(unsigned char c) {
    return c == '%';
}

int is_new_line(unsigned char c) {
    return c == '\n';
}

int is_symbol(unsigned char c) {
    return !(is_alnum(c) || is_space(c) || is_null(c) || is_del(c));
}

int is_open_parentesis(unsigned char c) {
    return c == '(';
}

int is_close_parentesis(unsigned char c) {
    return c == ')';
}

int is_operator(unsigned char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}
