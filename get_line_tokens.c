#include "shell.h"
/**
* get_line_tokens - extract tokens from given input
* @line: to be tokenized
* Return: array of strings
*/
char **get_line_tokens(char *line)
{
	char *buf = NULL, *delimiters = " :\t\r\n", *bufp = NULL, *token = NULL;
	char **tokens = NULL;
	int token_size = 1;
	size_t index = 0, flag = 0;

	buf = str_duplicate(line);
	if (!buf)
		return (NULL);
	bufp = buf;

	while (*bufp)
	{
		if (str_find_chr(delimiters, *bufp) != NULL && flag == 0)
		{
			token_size++;
			flag = 1;
		}
		else if (str_find_chr(delimiters, *bufp) == NULL && flag == 1)
			flag = 0;
		bufp++;
	}
	tokens = malloc(sizeof(char *) * (token_size + 1));
	token = strtok(buf, delimiters);
	while (token)
	{
		tokens[index] = str_duplicate(token);
		if (tokens[index] == NULL)
		{
			if (tokens)
				free(tokens);
			return (NULL);
		}
		token = strtok(NULL, delimiters);
		index++;
	}
	tokens[index] = '\0';
	if (buf)
		free(buf);
	return (tokens);
}
