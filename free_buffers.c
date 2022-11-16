#include "shell.h"

/**
* free_buffers - frees buffers
* @buf: buffer to free
*
* Return: Nothing
*/
void free_buffers(char **buf)
{
	int i = 0;

	if (!buf || buf == NULL)
	{
		return;
	}

	while (buf[i])
	{
		if (buf[i])
			free(buf[i]);

		i++;
	}
	if (buf)
		free(buf);
}
