#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
/**
 * struct specifier - Struct specifier
 *
 * @s: specifier char
 * @f: function to deal with this specifier
 */
typedef struct specifier
{
	char s;
	int (*f)(va_list args);
} specifier_t;
int _printf(const char *format, ...);
#endif /* MAIN_H */
