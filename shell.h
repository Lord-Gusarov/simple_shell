#ifndef _SHELL_H_
#define _SHELL_H_
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

#include "_string.h"
/*==================================*/

/*External Enviroment variable*/
extern char **environ;
/*======================*/


/*Our getline*/
size_t _getline(char **lineptr, size_t *n, FILE *stream);

/*Our realloc*/
void *_realloc(void *ptr, size_t size);

/*Obtain our command*/
int getcommand(char ***);
/*append frst succesful path to input command*/
int appendCommandPath(char **input);
int locateEmptyDir(char *str);
/*determines if the first token read from user input is a 'builin' command*/
int builtin(char *);

/*OUR getenv()*/
char *_getenv(const char *name);
/*handles printing error message when command not found*/
void commandNotFound(char *str1, unsigned int cnt, char *str2);

/*+++SIGNAL HANDLING FUNCTIONS+++*/
void catch_c_c(int sig);
void catch_c_d(int sig);
/*===============================*/



/*========Builtins=========*/
int execBuiltIn(char*, char **, unsigned int);
void env(void);
int _exit_(char *, char **, unsigned int);

#endif
