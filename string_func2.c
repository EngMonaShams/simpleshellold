#include "shell.h"

/**
 * _strcmp - a function that compare two strings.
 *
 * @s1 : pointer to destination
 * @s2 : pointer to source
 *
 * Return: -15 (s1 < s2)
 *         0   (s1 = s2)
 *         15  (s1 > s2)
 *
 */

int _strcmp(char *s1, char *s2)
{
	int equal = 0;

	while (*s1)
	{
		if (*s1 != *s2)
		{
			equal = ((int)*s1 - 48) - ((int)*s2 - 48);
			break;
		}
		s1++;
		s2++;
	}
	return (equal);

}

/**
 * _strdup - a function that  fills memory with a constant byte.
 *
 * @str: data
 *
 * Return: pointer m
 */

char *_strdup(char *str)
{
	char *m;
	int size = 0, i;

	if (str == NULL)
		return (NULL);
	for (i = 0; str[size] != '\0'; size++)
		;
	m = malloc(size + 1);
	if (m == 0)
		return (NULL);
	for (i = 0; i < size; i++)
		m[i] = str[i];
	return (m);
	}
