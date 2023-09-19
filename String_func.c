#include "shell.h"

/**
 * _strlen - a function that updates the value it points to to 98.
 *
 * @s : pointer to int
 *
 * Return: count (length of string)
 */

int _strlen(char *s)
{
	int count = 0;

	while (*s != '\0')
	{
		count++;
		s++;
	}
	return (count);
}

/**
 * _strcpy - a function that updates the value it points to to 98.
 *
 * @dest : destination
 * @src : source
 *
 * Return: dest (pointer)
 */

char *_strcpy(char *dest, char *src)
{
	int i = -1;

	do {
		i++;
		dest[i] = src[i];
	} while (src[i] != '\0');
	return (dest);
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: on success 1
 *	   on error -1
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - a function that updates the value it points to to 98.
 *
 * @str : pointer to int
 *
 */

void _puts(char *str)
{
	while (*str != '\0')
	{
		putchar(*str);
		str++;
	}
	putchar('\n');
}

/**
 * *_strcat - a function that concatenates two strings.
 *
 * @dest : pointer to destination
 * @src : pointer to source
 *
 * Return: pointer to string
 *
 */

char *_strcat(char *dest, char *src)
{
	int c1 = 0, c2;

	while (dest[c1])
		c1++;
	for (c2 = 0; src[c2]; c2++)
		dest[c1++] = src[c2];
	return (dest);
}
