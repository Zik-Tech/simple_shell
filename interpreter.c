#include "shell.h"

/**
 * interpret - executes commands entered by users
 *@cp: command
 *@cmd:vector array of pointers to commands
 * Return: 0
 */
void interpret(char *cp, char **cmd)
{
	pid_t child_pid;
	int status;
	char **env = environ;

	child_pid = fork();
	if (child_pid < 0)
		print_error(cp);
	if (child_pid == 0)
	{
		execve(cp, cmd, env);
		print_error(cp);
		if (cp)
			free(cp);

		if (cmd)
			free_buffers(cmd);

		exit(98);
	}
	else
		wait(&status);
}
