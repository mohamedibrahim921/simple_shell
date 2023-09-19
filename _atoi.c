#include "shell.h"

/**
 * interactive - Returns True If shell Is Interactive Mode
 * @info: Struct Address
 *
 * Return: 1 If Interactive Mode, 0 Otherwise
 */
int interactive(info_t *info)
{
return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - Checks If Character Is a Delimeter
 * @c: The Char To Check
 * @Delim: The Delimeter String
 * Return: 1 If True, 0 If False
 */
int is_delim(char c, char *delim)
{
while (*delim)
if (*delim++ == c)
return (1);
return (0);
}

/**
 * _isalpha - Checks For Alphabetic Character
 * @c: The Character to Input
 * Return: 1 If c Is Alphabetic, 0 Otherwise
 */

int _isalpha(int c)
{
if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
return (1);
else
return (0);
}

/**
 * _atoi - Converts a String to an Integer
 * @s: the string to be converted
 * Return: 0 If no Numbers in String, Converted Number Otherwise
 */
int _atoi(char *s)
{
int i, sign = 1, flag = 0, output;
unsigned int result = 0;

for (i = 0; s[i] != '\0' && flag != 2; i++)
{
if (s[i] == '-')
sign *= -1;

if (s[i] >= '0' && s[i] <= '9')
{
flag = 1;
result *= 10;
result += (s[i] - '0');
}
else if (flag == 1)
flag = 2;
}

if (sign == -1)
output = -result;
else
output = result;

return (output);
}
