#include "shell.h"

/**
 * strcat_cd - the func which concatenates the message for the cd error
 * @datash: the important data (directory)
 * @msg:the message to print out
 * @error: the output message
 * @ver_str: the counter lines
 * Return: the error message (Error)
 */

char *strcat_cd(data_shell *datash, char *msg, char *error, char *ver_str)
{
	char *illegal_flag;

	_strcpy(error, datash->av[0]);
	_strcat(error, ": ");
	_strcat(error, ver_str);
	_strcat(error, ": ");
	_strcat(error, datash->args[0]);
	_strcat(error, msg);
	if (datash->args[1][0] == '-')
	{
		illegal_flag = malloc(3);
		illegal_flag[0] = '-';
		illegal_flag[1] = datash->args[1][1];
		illegal_flag[2] = '\0';
		_strcat(error, illegal_flag);
		free(illegal_flag);
	}
	else
	{
		_strcat(error, datash->args[1]);
	}

	_strcat(error, "\n");
	_strcat(error, "\0");
	return (error);
}

/**
 * error_get_cd - is the error message for the cd command in get_cd
 * @datash: important data (directory)
 * Return: the error message (Error)
 */

char *error_get_cd(data_shell *datash)
{
	int len, len_id;
	char *error, *ver_str, *msg;

	ver_str = aux_itoa(datash->counter);
	if (datash->args[1][0] == '-')
	{
		msg = ": Illegal option ";
		len_id = 2;
	}
	else
	{
		msg = ": can't cd to ";
		len_id = _strlen(datash->args[1]);
	}

	len = _strlen(datash->av[0]) + _strlen(datash->args[0]);
	len += _strlen(ver_str) + _strlen(msg) + len_id + 5;
	error = malloc(sizeof(char) * (len + 1));

	if (error == 0)
	{
		free(ver_str);
		return (NULL);
	}

	error = strcat_cd(datash, msg, error, ver_str);

	free(ver_str);

	return (error);
}

/**
 * error_not_found - the error message for the command that are not found
 * @datash: important data (counter, arguments)
 * Return: the error message (Error)
 */

char *error_not_found(data_shell *datash)
{
	int len;
	char *error;
	char *ver_str;

	ver_str = aux_itoa(datash->counter);
	len = _strlen(datash->av[0]) + _strlen(ver_str);
	len += _strlen(datash->args[0]) + 16;
	error = malloc(sizeof(char) * (len + 1));
	if (error == 0)
	{
		free(error);
		free(ver_str);
		return (NULL);
	}
	_strcpy(error, datash->av[0]);
	_strcat(error, ": ");
	_strcat(error, ver_str);
	_strcat(error, ": ");
	_strcat(error, datash->args[0]);
	_strcat(error, ": not found\n");
	_strcat(error, "\0");
	free(ver_str);
	return (error);
}

/**
 * error_exit_shell - the error message for exit in the get_exit
 * @datash: important data (counter, arguments)
 * Return: the error message (Error)
 */

char *error_exit_shell(data_shell *datash)
{
	int len;
	char *error;
	char *ver_str;

	ver_str = aux_itoa(datash->counter);
	len = _strlen(datash->av[0]) + _strlen(ver_str);
	len += _strlen(datash->args[0]) + _strlen(datash->args[1]) + 23;
	error = malloc(sizeof(char) * (len + 1));
	if (error == 0)
	{
		free(ver_str);
		return (NULL);
	}
	_strcpy(error, datash->av[0]);
	_strcat(error, ": ");
	_strcat(error, ver_str);
	_strcat(error, ": ");
	_strcat(error, datash->args[0]);
	_strcat(error, ": Illegal number: ");
	_strcat(error, datash->args[1]);
	_strcat(error, "\n\0");
	free(ver_str);

	return (error);
}
