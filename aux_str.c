#include "shell.h"

/**
 * _strcat - this will concatenate two strings together
 * @dest: the char pointer of the dest of a copied str
 * @src: the const char pointer of the source of str
 * Return: the dest
 */

char *_strcat(char *dest, const char *src)
{
	int a;
	int b;

	for (a = 0; dest[a] != '\0'; a++)
		;

	for (b = 0; src[b] != '\0'; b++)
	{
		dest[a] = src[b];
		a++;
	}

	dest[a] = '\0';
	return (dest);
}

/**
 * _strcpy - this will copy the string pointed to by src
 * @dest: the type char pointer the dest of a copied str
 * @src: the type char pointer of the source of a str
 * Return: the dest
 */

char *_strcpy(char *dest, char *src)
{

	size_t index;

	for (index = 0; src[index] != '\0'; index++)
	{
		dest[index] = src[index];
	}
	dest[index] = '\0';

	return (dest);
}

/**
 * _strcmp - the function that compares two strings
 * @s1: the type str that is being compared
 * @s2: type str that is being compared
 * Return: 0 Always
 */

int _strcmp(char *s1, char *s2)
{
	int index;

	for (index = 0; s1[index] == s2[index] && s1[index]; index++)
		;

	if (s1[index] > s2[index])
		return (1);
	if (s1[index] < s2[index])
		return (-1);
	return (0);
}

/**
 * _strchr - it will locate a character in a string
 * @s: the string
 * @c: the character
 * Return: the pointer to first occurrence of a character c
 */

char *_strchr(char *s, char c)
{
	unsigned int index = 0;

	for (; *(s + index) != '\0'; index++)
		if (*(s + index) == c)
			return (s + index);
	if (*(s + index) == c)
		return (s + index);
	return ('\0');
}

/**
 * _strspn - it will get the length of a prefix substring
 * @s: the initial segment
 * @accept: the bytes accepted
 * Return: the num of bytes accepted
 */

int _strspn(char *s, char *accept)
{
	int a, b, bool;

	for (a = 0; *(s + a) != '\0'; a++)
	{
		bool = 1;
		for (b = 0; *(accept + b) != '\0'; b++)
		{
			if (*(s + a) == *(accept + b))
			{
				bool = 0;
				break;
			}
		}
		if (bool == 1)
			break;
	}
	return (a);
}
