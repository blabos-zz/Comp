/*
 * exp.c
 *
 *  Created on: May 18, 2011
 *      Author: blabos
 */

#include "exp.h"

static int __my_stack__[STACK_LEN];
static int __my_stack_pointer__ = 0;

int eval(char* expr, int len) {
    int pos = -1;

    do {
        pos++;
    } while (is_space(expr[pos]));

    if (is_number(expr[pos])) {
        goto number;
    } else if (is_open_parentesis(expr[pos])) {
        goto push;
    } else if (is_null(expr[pos])) {
        goto end;
    } else {
        goto error;
    }

    number: do {
        pos++;
    } while (is_space(expr[pos]));

    if (is_operator(expr[pos])) {
        goto operator;
    } else if (is_null(expr[pos])) {
        goto end;
    } else {
        goto error;
    }

    operator: do {
        pos++;
    } while (is_space(expr[pos]));

    if (is_number(expr[pos])) {
        goto number;
    } else if (is_open_parentesis(expr[pos])) {
        goto push;
    } else {
        goto error;
    }

    push: do {
        pos++;
    } while (is_space(expr[pos]));

    if (!stack_push()) {
        goto error;
    } else if (is_number(expr[pos])) {
        goto number;
    } else if (is_operator(expr[pos])) {
        goto operator;
    } else if (is_space(expr[pos])) {
        goto space;
    } else if (is_open_parentesis(expr[pos])) {
        goto push;
    } else {
        goto error;
    }

    pop: pos++;
    if (!stack_pop()) {
        goto error;
    } else if (is_operator(expr[pos])) {
        goto operator;
    } else if (is_space(expr[pos])) {
        goto space;
    } else if (is_close_parenteis(expr[pos])) {
        goto pop;
    } else {
        goto error;
    }
}

int stack_push() {
    int status = 0;

    if (__my_stack_pointer__ < STACK_LEN) {
        __my_stack__[__my_stack_pointer__] = 1;
        __my_stack_pointer__++;
        status = 1;
    }

    return status;
}

int stack_pop() {
    int status = 0;

    if (__my_stack_pointer__ > 0) {
        __my_stack_pointer__--;
        __my_stack__[__my_stack_pointer__] = 0;
        status = 1;
    }

    return 0;
}

