/*
 * exp.c
 *
 *  Created on: May 18, 2011
 *      Author: blabos
 */

#include "exp.h"
#include "string.h"
#include <stdio.h>

static int __my_stack__[STACK_LEN];
static int __my_stack_pointer__ = 0;

int eval(char* expr, int len) {
    int pos = -1;

    begin: pos++;
    if (is_space(expr[pos])) {
        goto begin;
    } else if (is_number(expr[pos])) {
        goto number;
    } else if (is_open_parentesis(expr[pos])) {
        goto push;
    } else if (is_null(expr[pos])) {
        goto end;
    } else {
        goto error;
    }

    number: pos++;
    if (is_space(expr[pos])) {
        goto number;
    } else if (is_operator(expr[pos])) {
        goto operator;
    } else if (is_close_parentesis(expr[pos])) {
        goto pop;
    } else if (is_null(expr[pos]) && stack_empty()) {
        goto end;
    } else {
        goto error;
    }

    operator: pos++;
    if (is_space(expr[pos])) {
        goto operator;
    } else if (is_number(expr[pos])) {
        goto number;
    } else if (is_open_parentesis(expr[pos])) {
        goto push;
    } else {
        goto error;
    }

    push:

    if (stack_push()) {
        ignore_spaces_pushing: pos++;
        if (is_space(expr[pos])) {
            goto ignore_spaces_pushing;
        } else if (is_number(expr[pos])) {
            goto number;
        } else if (is_open_parentesis(expr[pos])) {
            goto push;
        } else {
            goto error;
        }
    } else {
        goto error;
    }

    pop: if (stack_pop()) {
        ignore_spaces_poping: pos++;
        if (is_space(expr[pos])) {
            goto ignore_spaces_poping;
        } else if (is_operator(expr[pos])) {
            goto operator;
        } else if (is_close_parentesis(expr[pos])) {
            goto pop;
        } else if (is_null(expr[pos]) && stack_empty()) {
            goto end;
        } else {
            goto error;
        }
    } else {
        goto error;
    }

    end: return 0;

    error: return -1;
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

    return status;
}

int stack_empty() {
    return __my_stack_pointer__ <= 0;
}
