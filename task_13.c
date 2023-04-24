#include "main.h"
#include <string.h>
#include <unistd.h>
/**
 * rev_string - reverses a string with refrance
 * @s: char pointer
 * Return: the length *s
 */
int rev_string(va_list args)
{
	int len, i;
	char swap;
	char *dest, *s;

	s = va_arg(args, char*);
	if(s == NULL)
		return (0);
	dest = malloc(strlen(s) * sizeof(char) + 1);
	if(!dest)
		return (0);
	
	s = strcpy(dest, s);
	if(s == NULL)
		return (0);
	
	len = strlen(s) - 1;
	for (i = 0; i <= len / 2; i++)
	{
		swap = s[i];
		s[i] = s[len - i];
		s[len - i] = swap;
	}
	write(STDOUT_FILENO, s, len + 1);
	free(dest);
	return(len + 1);
}
