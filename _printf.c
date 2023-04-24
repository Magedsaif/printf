#include "main.h"
#include <string.h>
#include <unistd.h>
/**
*write_string - a function that writes a string to the standard output
 *@args:variadic arguments
 *Return:the number of characters printed
*/
int write_string(va_list args)
{
	int len;
	char *str;

	str = va_arg(args, char*);
	if (str == NULL)
		str = "(null)";
	len = strlen(str);
	write(STDOUT_FILENO, str, len);

	return (len);
}
/**
 *write_char - a function that writes a char to the standard output
 *@args:variadic arguments
 *Return:the number of characters printed
*/
int write_char(va_list args)
{
	char c;

	c = (char) va_arg(args, int);
	write(STDOUT_FILENO, &c, 1);

	return (1);
}
/**
 *write_specifier - a function that writes a specifier to the standard output
 *@args:variadic arguments
 *Return:the number of characters printed
*/
int write_specifier(va_list args)
{
	(void) args;
	write(STDOUT_FILENO, "%", 1);

	return (1);
}
/**
*is_specifier - a function that checks if there is a specifier in the format
 *@spacifiers: array of structs containing different conversion specifiers
 *@format: pointer to an array containing the string of chars to be handled
 *Return: -1 in case of reaching the end of format
 *		  (i) in case of finding a match to the specifier
*/
int is_specifier(specifier_t spacifiers[], char *format)
{
	int i;
	char fchar;

	i = 0;
	if (format[i] == '%')
	{
		
		if (format[i + 1] == '\0')
			return (-1);/*error*/
		fchar = format[i + 1];
		/*select spacifier function*/
		for (i = 0; i < 9; i++)
		{
			if (spacifiers[i].s == fchar)
				return (i);
		}
	}
	/*not found*/
	return (-2);
}
/**
 *_printf - a function to print a string using a format
 *@format: pointer to an array containing the string of chars to be handled
 *Return: count or error upon failing (-1)
 */
int _printf(const char *format, ...)
{
	int i, s_index, write_count;
	va_list args;
	specifier_t spacifiers[] = {
	{'s', write_string}, {'c', write_char}, {'%', write_specifier}
	,{'d', write_decimal},{'i', write_decimal}, {'b', write_binary_number},
	{'r', rev_string},{'R',rev_rot13},{'o',write_binary_number}};

	if (format == NULL)
		return (-1);

	va_start(args, format);
	write_count = 0;
	for (i = 0; (format != NULL) && (format[i] != '\0'); i++)
	{
		s_index = is_specifier(spacifiers, (char *) (format + i));

		if (s_index == -2)
		{
			write(STDOUT_FILENO, (char *) (format + i), 1);
			write_count++;
		}
		else if (s_index == -1)
		{
			return (-1);
		}
		else
		{
			write_count = write_count + spacifiers[s_index].f(args);
			i++;
		}
	}
	va_end(args);
return (write_count);
}
