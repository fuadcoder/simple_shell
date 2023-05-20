#include "shell.h"

/**
 * get_builtin - function that combines builtin commands in the arg
 * @cmd: input
 * Return: pointer of the builtin command
 */
int (*get_builtin(char *cmd))(data_shell *)
{
	builtin_t builtin[] = {
		{ "env", _env },
		{ "exit", exit_shell },
		{ "setenv", _setenv },
		{ "unsetenv", _unsetenv },
		{ "cd", cd_shell },
		{ "help", get_help },
		{ NULL, NULL }
	};
	int j;

	for (j = 0; builtin[j].name; j++)
	{
		if (_strcmp(builtin[j].name, cmd) == 0)
			break;
	}

	return (builtin[j].f);
}
