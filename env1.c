#include "shell.h"

/**
 * cmp_env_name - equate env variables names with the named acknowledged
 * @nenv: input
 * @name: input
 *
 * Return: 0 if they are not equal, Another value if they are
 */
int cmp_env_name(const char *nenv, const char *name)
{
	int k;

	for (k = 0; nenv[k] != '='; k++)
	{
		if (nenv[k] != name[k])
		{
			return (0);
		}
	}

	return (k + 1);
}

/**
 * _getenv - obtain an environment variable
 * @name: input
 * @_environ: input
 *
 * Return: value of the environment variable if is found
 * else, returns NULL
 */
char *_getenv(const char *name, char **_environ)
{
	char *ptr_env;
	int k, mov;

	/* Initialize ptr_env value */
	ptr_env = NULL;
	mov = 0;
	/* Compare all environment variables */
	/* environ is declared in the header file */
	for (k = 0; _environ[k]; k++)
	{
		/* If name and env are equal */
		mov = cmp_env_name(_environ[k], name);
		if (mov)
		{
			ptr_env = _environ[k];
			break;
		}
	}

	return (ptr_env + mov);
}

/**
 * _env - function that prints the evironment variables
 *
 * @datash: data applicable
 * Return: 1 on success
 */
int _env(data_shell *datash)
{
	int k, j;

	for (k = 0; datash->_environ[k]; k++)
	{
		for (j = 0; datash->_environ[k][j]; j++)
			;

		write(STDOUT_FILENO, datash->_environ[k], j);
		write(STDOUT_FILENO, "\n", 1);
	}
	datash->status = 0;

	return (1);
}
