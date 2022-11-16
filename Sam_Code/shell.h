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
#define BUFF_SIZE 1024
#define PROMPT "$ "
/* error messages */
#define EINVAL "Invalid argument"
#define ENOMEM "Out of memory"
#define ERROR "Error"
#define WRONG "Something went wrong"
#define END "exit"

typedef struct built_in
{
	char *bi;
	int (*f)();
} builtin_t;

typedef struct list_s
{
	char *str;
	unsigned int len;
	struct list_s *next;
} list_t;


int main(int ac, char **av);
int interactive(info_t *info);
int is_delim(char c, char *delim);
int _atoi(char *s);
int _myexit(info_t *info);
int _mycd(info_t *info);
int _myhelp(info_t *info);
int _myhistory(info_t *info);
int unset_alias(info_t *info, char *str);
int set_alias(info_t *info, char *str);
int print_alias(list_t *node);
int _myalias(info_t *info);
int _myenv(info_t *info);
char *_getenv(info_t *info, const char *name);
int _mysetenv(info_t *info);
int _myunsetenv(info_t *info);
int populate_env_list(info_t *info);
void _eputs(char *str);
int _eputchar(char c);
int _putfd(char c, int fd);
int _putfd(char *str, int fd);
int _erratoi(char *s);
void print_error(info_t *info, char *estr);
int print_d(int input, int fd);
char *convert_number(long int num, int base, int flags);
void remove_comments(char *buf);
char *_strncpy(char *dest, char *src, int n);
char *_strchr(char *s, char c);
char **get_environ(info_t *info);
int _unsetenv(info_t *info, char *var);
int _setenv(info_t *info, char *var, char *value);
void clear_info(info_t *info);
void set_info(info_t *info, char **av);
void free_info(info_t *info, int all);
ssize_t input_buf(info_t *info, char **buf, size_t *len);
int _getline(info_t *info, char **ptr, size_t *length);
void siginHandler(__attribute__((unused))int sig_num);
char *get_history_file(info_t *info);
int write_history(info_t *info);
int read_history(info_t *info);
list_t *add_node(list_t **head, const char *str, int num);
list_t *add_node_end(list_t **head, const char *str, int num);
size_t print_list_str(const list_t *h);
int delete_node_at_index(list_t **head, unsigned int index);
void free_list(list_t **head_ptr);
size list_len(const list_t *h);
char **list_to_strings(list_t *head);
size_t print_list(const list_t *h);
list_t *node_starts_with(list_t *node, char *prefix, char c);
ssize_t get_node_index(list_t *head, list_t *node);
int bfree(void **ptr);
int is_cmd(info_t *info, char *path);
char *dup_chars(char *pathstr, int start, int stop);
char *find_path(info_t *info, char *pathstr, char *cmd);
char *_memset(char *s, char b, unsigned int n);
void ffree(char **pp);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

#endif
