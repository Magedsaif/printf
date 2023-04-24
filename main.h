#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
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
int write_decimal(va_list args);
int write_binary_number(va_list args);
int rev_string(va_list args);
char *_strcpy(char *dest,char *src);
int rev_rot13(va_list args);
#endif /* MAIN_H */
