#include "shell.h"

/**
* get_path - finds the path from the global enviroment
* Return: NULL if path is not found or path if path is found.
*/
char *get_path(void)
{
	int x = 0;
	char **env = environ, *path = NULL;

	while (*env)
	{
		if (str_compare_n(*env, "PATH=", 5) == 0)
		{
			path = *env;
			while (*path && x < 5)
			{
				path++;
				x++;
			}
			return (path);
		}
		env++;
	}
	return (NULL);
}
