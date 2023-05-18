#include "shell.h"

/**
 * _strdup - it will duplicate a string in the heap memory
 * @s: the type char pointer string
 * Return: the duplicated string
 */

char *_strdup(const char *s)
{
	char *new;
	size_t len;

	len = _strlen(s);
	new = malloc(sizeof(char) * (len + 1));
	if (new == NULL)
		return (NULL);
	_memcpy(new, s, len + 1);
	return (new);
}

/**
 * _strlen - it will return the length of a string
 * @s: the type char pointer
 * Return: 0 Always
 */

int _strlen(const char *s)
{
	int len;

	for (len = 0; s[len] != 0; len++)
	{
	}
	return (len);
}

/**
 * cmp_chars - it will compare the chars of a strings
 * @str: the input string
 * @delim: the delimiter
 * Return: 1 if equal, Otherwise 0
 */

int cmp_chars(char str[], const char *delim)
{
	unsigned int a, b, c;

	for (a = 0, c = 0; str[a]; a++)
	{
		for (b = 0; delim[b]; b++)
		{
			if (str[a] == delim[b])
			{
				c++;
				break;
			}
		}
	}
	if (a == c)
		return (1);
	return (0);
}

/**
 * _strtok - it will split a string by some delimiter
 * @str: the input string
 * @delim: the delimiter
 * Return: the splited string
 */

char *_strtok(char str[], const char *delim)
{
	static char *splitted, *str_end;
	char *str_start;
	unsigned int index, bool;

	if (str != NULL)
	{
		if (cmp_chars(str, delim))
			return (NULL);
		splitted = str; /*Stores first address*/
		index = _strlen(str);
		str_end = &str[index]; /*Stores last address*/
	}
	str_start = splitted;
	if (str_start == str_end) /* it will reach the end*/
		return (NULL);

	for (bool = 0; *splitted; splitted++)
	{
		/*Breaking loop then finding the next token*/
		if (splitted != str_start)
			if (*splitted && *(splitted - 1) == '\0')
				break;
		/*Replacing the delimiter for null char*/
		for (index = 0; delim[index]; index++)
		{
			if (*splitted == delim[index])
			{
				*splitted = '\0';
				if (splitted == str_start)
					str_start++;
				break;
			}
		}
		if (bool == 0 && *splitted) /*Str != Delim*/
			bool = 1;
	}
	if (bool == 0) /*Str == Delim*/
		return (NULL);
	return (str_start);
}

/**
 * _isdigit - this defines if the string passed is a number
 * @s: the input string
 * Return: 1 if string is a number, Otherwise 0
 */

int _isdigit(const char *s)
{
	unsigned int index;

	for (index = 0; s[index]; index++)
	{
		if (s[index] < 48 || s[index] > 57)
			return (0);
	}
	return (1);
}
