#include "shell.h"

/**
* handle_exit - handles the exit command
* @command: tokenized command
* @line: input read from stdin
*
* Return: no return
*/
void handle_exit(char **command, char *line)
{
	if (line)
	{
		free(line);
	}

	free_buffers(command);
	exit(0);
}
