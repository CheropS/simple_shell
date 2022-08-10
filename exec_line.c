#include "main.h"

/**
 * exec_line - finds commands and builtins
 * @dayta: data relevant
 * Return: 1 on success.
 */

int exec_line(data_shell *dayta)
{
	int (*builtin)(data_shell *dayta);

	if (dayta->args[0] == NULL)
		return (1);

	builtin = get_builtin(dayta->args[0]);

	if (builtin != NULL)
		return (builtin(dayta));

	return (cmd_exec(dayta));
}
