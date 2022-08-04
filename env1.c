#include "main.h"

/**
 * cmp_env_name - compares env variables names
 * @nenv: name of the environment variable
 * @name: name passed
 * Return: 0 if not equal. Another value if they are.
 */

int cmp_env_name(const char *nenv, const char *name)
{
	int i;

	for (i = 0; nenv[i] != '='; i++)
	{
		if (nenv[i] != name[i])
		{
			return (0);
		}
	}

	return (i + 1);
}

/**
 * _getenv - get env variable
 * @name: name of the env variable
 * @_environ: env variable
 * Return: value of environment, otherwise NULL.
 */

char *_getenv(const char *name, char **_environ)
{
	char *ptr_env;
	int i, mov;

	ptr_env = NULL;
	mov = 0;

	for (i = 0; _environ[i]; i++)
	{
		mov = cmp_env_name(_environ[i], name);
		if (mov)
		{
			ptr_env = _environ[i];
			break;
		}
	}

	return (ptr_env + mov);
}

/**
 * _env - prints the environment variable
 * @dayta: data relevant.
 * Return: 1 on success.
 */

int _env(data_shell *dayta)
{
	int i, j;

	for (i = 0; dayta->_environ[i]; i++)
	{
		for (j = 0; dayta->_environ[i][j]; j++)
			;
		write(STDOUT_FILENO, dayta->_environ[i], j);
		write(STDOUT_FILENO, "\n", 1);
	}
	dayta->status = 0;

	return (1);
}