#include "monty.h"

/**
 * is_number - validate if it's a number unsigned
 *
 * @string: string to validate
 * Return: true if it's number else false
 */
bool is_number(char *string)
{
	/*validate eggs case*/
	if (string == NULL)
		return (false);

	/*base case end string*/
	if (*string == '\0')
		return (true);

	/*validate each character if it's number*/
	if (*string >= '0' && *string <= '9')
		return (is_number(string + 1));

	return (false);
}
