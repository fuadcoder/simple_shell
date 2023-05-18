#include "shell.h"

/**
 * rev_string - it reverses the string
 * @s: the input string
 * Return: no return
 */

void rev_string(char *s)
{
	int count = 0, a, b;
	char *str, temp;

	while (count >= 0)
	{
		if (s[count] == '\0')
			break;
		count++;
	}
	str = s;

	for (a = 0; a < (count - 1); a++)
	{
		for (b = a + 1; b > 0; b--)
		{
			temp = *(str + b);
			*(str + b) = *(str + (b - 1));
			*(str + (b - 1)) = temp;
		}
	}
}
