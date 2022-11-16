#include "shell.h"

/**
* test_path - checks whether path is valid
* @path: tokenized path
* @command: user entered command
*
* Return: path appended with command on success
* NULL on failure
*/
char *test_path(char **path, char *command)
{
	int i = 0;
	char *output;

	do {
		output = path_to_command(path[i], command);
		if (access(output, F_OK | X_OK) == 0)
			return (output);
		if (output)
			free(output);

		i++;
	} while (path[i]);
	return (NULL);
}
