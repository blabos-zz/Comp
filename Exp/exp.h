/*
 * exp.h
 *
 *  Created on: May 18, 2011
 *      Author: blabos
 */

#ifndef EXP_H_
#define EXP_H_

#define STACK_LEN   1024

int eval(char* expr, int len);
int stack_push();
int stack_pop();

#endif /* EXP_H_ */
