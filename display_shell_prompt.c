
#include "shell.h"

/**
* display_shell_prompt - prints :) to let user know the program is
* ready to take their input
* prints the prompt if the shell is in interactive mode
* Return: no return
*/
void display_shell_prompt(void)
{
	if ((isatty(STDIN_FILENO) == 1) && (isatty(STDOUT_FILENO) == 1))
	{
		flags.interactive = true;
	}
	if (flags.interactive)
	{
		write(STDERR_FILENO, ":) ", 3);
	}
}
