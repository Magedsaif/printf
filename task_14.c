#include "main.h"
#include <string.h>
#include <unistd.h>

/**
 * rot13 - encodes a string into  rot13.
 * @src: string refrance
 * Return: *src encodd string into  rot13.
 */
char *rot13(char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		while (((src[i] >= 'a') && (src[i] <= 'z'))
		|| ((src[i] >= 'A') && (src[i] <= 'Z')))
		{
			if (((src[i] >= 'a') && (src[i] <= 'm'))
			|| ((src[i] >= 'A') && (src[i] <= 'M')))
			{
				src[i] = src[i] + 13;
				break;
			}
			src[i] = src[i] - 13;
			break;
		}
		i++;
	}
	return (src);
}

/**
 * rev_rot13 - encodes a string into  rot13.
 * @args: variadic arguments
 * Return: *src encodd string into  rot13.
 */
int rev_rot13(va_list args)
{
	int len;
	char *dest, *s;

	s = va_arg(args, char*);
	if (s == NULL)
		return (0);
	dest = malloc(strlen(s) * sizeof(char) + 1);
	if (!dest)
		return (0);

	s = _strcpy(dest, s);
	if (s == NULL)
		return (0);
	rot13(s);
	len = strlen(s);
	write(STDOUT_FILENO, s, len);
	free(dest);
	return (len);
}
