#include "shell.h"
/**
* main - reads input from user in interactive mode or from
*        the piped input, then execute and output accordingly
* @argc: argument count
* @argv: argument vector
* @env_v: environment vector
* Return: Always 0
*/
int main(int argc, char **argv, char *env_v[])
{
	char *line = NULL, *path = NULL, *path_command = NULL;
	ssize_t line_count = 0;
	size_t buffer_size = 0;
	char **command = NULL, **paths = NULL;
	(void)env_v, (void)argv;
	if (argc < 1)
		return (-1);

	signal(SIGINT, handle_signal);
	do {
		free_buffers(command);
		free_buffers(paths);
		free(path_command);
		display_shell_prompt();
		line_count = getline(&line, &buffer_size, stdin);
		if (line_count < 0)
			break;
		info.ln_count++;
		if (line[line_count - 1] == '\n')
			line[line_count - 1] = '\0';
		command = get_line_tokens(line);
		if (*command == NULL || **command == '\0' || command == NULL)
			continue;
		if (is_builtin(command, line))
			continue;
		path = get_path();
		paths = get_line_tokens(path);
		path_command = test_path(paths, command[0]);
		if (!path_command)
			print_error(argv[0]);
		else
			interpret(path_command, command);
	} while (true);

	if (line_count < 0 && flags.interactive)
		write(STDERR_FILENO, "\n", 1);
	if (line)
		free(line);

	return (0);
}
