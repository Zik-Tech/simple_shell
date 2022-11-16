#ifndef SHELL_H
#define SHELL_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <time.h>
#include <stdbool.h>

#include <errno.h>
#include <math.h>
#include <ctype.h>
#include <libgen.h>
#include <signal.h>

/* environment variables */
extern __sighandler_t signal(int __sig, __sighandler_t __handler);
extern char **environ;

int is_builtin(char **cmd, char *buf);
void display_shell_prompt(void);
void handle_signal(int m);
char **get_line_tokens(char *line);
char *test_path(char **path, char *command);
char *path_to_command(char *path, char *command);
int handle_builtin(char **command, char *line);
void handle_exit(char **command, char *line);

void print_env(void);
void print_error(char *str);
int print_string(char *s);

int str_length(char *s);
int str_compare(char *s1, char *s2);
int str_compare_n(char *s1, char *s2, int n);
char *str_duplicate(char *s);
char *str_find_chr(char *s, char c);

void interpret(char *cp, char **cmd);
char *get_path(void);

void free_buffers(char **buf);

/**
 * struct info - Defines a `info` structure
 * @final_exit: param
 * @ln_count: param
 **/
struct info
{
	int final_exit;
	int ln_count;
} info;

/**
 * struct builtin - Defines a `builtin` structure
 * @env: param
 * @exit: param
 **/
struct builtin
{
	char *env;
	char *exit;
} builtin;

/**
 * struct flags - Defines a `flags` structure
 * @interactive: param
 **/
struct flags
{
	bool interactive;
} flags;

#endif
