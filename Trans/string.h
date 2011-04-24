/*
 * string.h
 *
 *  Created on: Apr 23, 2011
 *      Author: blabos
 */

#ifndef _STRING_H
#define _STRING_H_


int slen(const char* str);
int scmp(const char* first, const char* second, int max);
void scpy(char* dst, const char* src, int max);
void scat(char* dst, const char* src, int max);
void subs(char* sub, const char* orig, int from, int count);
void erase(char* str, int pos, int count);
void lower(char* str);


#endif /* STRING_H_ */
