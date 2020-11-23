#ifndef __STRING_H_
#define __STRING_H_
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

/*==================== _string1.c =================*/
/*Lenght of a string*/
int _strlen(char *);
/*returns a pointer to a new string which is a duplicate*/
char *_strdup(char *str);
/*counts sequences of chars separeted by a space, a tab or the '\n' char*/
int _wc(char *str, char *delims);
/*cheks if certain string contains an specific character*/
int strHasChar(char *str, char c);
/*Splits a string into words, returns an array with all the word separated*/
char **_strtok(char *str, char *delims);
/*===================== end ========================*/



/*=================== _string2.c ==================*/
/*add two strings toghether, return pointer to newly allocated memory*/
char *str_concat(char *s1, char *s2);
/*adds and infinte amount of string, retuns a new pointer*/
char *concatenator(unsigned int n, ...);
/*unsigned int to str*/
char *intToStr(unsigned int n);
/*compares to string, return 0 if equals*/
int _strcmp(char *s1, char *s2);
/*==================================================*/

/* ====== strings3.c ========== */
int _atoi(char *s);
int onlyDigits(char *str);
/* ============================ */

/*================= freeSrings.c ===================*/
/*Frees an array of strings*/
void freeStrArr(char **array);
/*safely frees a string, checking for null... then sets it to null*/
void sfree(char **);

#endif
