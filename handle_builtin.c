#include "shell.h"

/**
* handle_builtin - handles interpret of builtin functions
* @command: tokenized commands
* @line: input read from stdin
*
* Return: 1 if executed, 0 if not
*/
int handle_builtin(char **command, char *line)
{
	struct builtin builtin = {"env", "exit"};

	if (str_compare(*command, builtin.env) == true)
	{
		print_env();
		return (1);
	}
	else if (str_compare(*command, builtin.exit) == true)
	{
		handle_exit(command, line);
		return (1);
	}
	return (0);
}
