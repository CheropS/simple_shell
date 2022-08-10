#include "main.h"


/**
 * exit_shell - exits the shell
 * @datash: data relevant
 * Return: 0 on success
 */

int exit_shell(data_shell *datash)
{
	unsigned int stata;
	int is_digit;
	int str_len;
	int large_number;

	if (datash->args[1] != NULL)
	{
		stata = _atoi(datash->args[1]);
		is_digit = _isdigit(datash->args[1]);
		str_len = _strlen(datash->args[1]);
		large_number = stata > (unsigned int)INT_MAX;
		if (!is_digit || str_len > 10 || large_number)
		{
			get_error(datash, 2);
			datash->status = 2;
			return (1);
		}
		datash->status = (stata % 256);
	}
	return (0);
}
