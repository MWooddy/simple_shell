#ifndef _SHELL_H_
#define _SHELL_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <signal.h>
#include <stdarg.h>
#include <math.h>
#include <locale.h>
#include <errno.h>


/*Shell Gen Funcs*/
int main(int ac, char **av, char **env);
void _shellPrompt(void);
void handle(int signals);
void _EOF(char *buffer);
void free_dp(char **command);
void free_exit(char **command);
void shell_exit(char **command);
int change_dir(const char *path);
/*Execution*/
void execute(char **command, char *name, char **env, int cycles);
void print_env(char **env);
char **_getPATH(char **env);
void msgerror(char *name, int cycles, char **command);

/*Create child and Change Directory*/
void create_child(char **command, char *name, char **env, int cycles);

/*Tokening*/
char **tokening(char *buffer, const char *s);

/*Aux Functions*/
int _strcmp(char *s1, char *s2);
unsigned int _strlen(char *s);
char *_strcpy(char *dest, char *src);
int _atoi(char *s);
char *_strcat(char *dest, char *src);
/*Get Function
*Addtional handlers
*More posible checks
*/
#endif
