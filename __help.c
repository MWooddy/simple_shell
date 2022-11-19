#include "builtins.h"

/**
 * __help - show help for builtins commands
 * @info: shell info
 * Return: status
 */
int __help(struct info *info)
{
	const builtin_t *bp = NULL;
	char * const *args = info->tokens + 1;
	const char *desc = NULL;
	size_t len = 0;
  int rc;

	if (*args)
	{
		info->status = EXIT_FAILURE;
		while (*args)
		{
			bp = get_builtin(*args);
			if (bp)
			{
        do { rc = write(STDOUT_FILENO, bp->name, _strlen(bp->name)); } while(rc == -1 && errno == EINTR);
				/*write(STDOUT_FILENO, bp->name, _strlen(bp->name));*/
        do { rc = write(STDOUT_FILENO, ": ", 2); } while(rc == -1 && errno == EINTR);
				/*write(STDOUT_FILENO, ": ", 2);*/
        do { rc = write(STDOUT_FILENO, bp->help, _strlen(bp->help)); } while(rc == -1 && errno == EINTR);
				/*write(STDOUT_FILENO, bp->help, _strlen(bp->help));*/
        do { rc = write(STDOUT_FILENO, "\n", 1); } while(rc == -1 && errno == EINTR);
				/*write(STDOUT_FILENO, "\n", 1);*/
				for (desc = bp->desc; (len = _strlen(desc)); desc += len + 1)
				{
					do { rc = write(STDOUT_FILENO, "    ", 4); } while(rc == -1 && errno == EINTR);
          /*write(STDOUT_FILENO, "    ", 4);*/
          do { rc = write(STDOUT_FILENO, desc, len); } while(rc == -1 && errno == EINTR);
					/*write(STDOUT_FILENO, desc, len);*/
          do { rc = write(STDOUT_FILENO, "\n", 1); } while(rc == -1 && errno == EINTR);
					/*write(STDOUT_FILENO, "\n", 1);*/
				}
				info->status = EXIT_SUCCESS;
			}
			args += 1;
		}
		if (info->status == EXIT_FAILURE)
			perrorl_default(*info->argv, info->lineno, "No topics match",
					*info->tokens, *(args - 1), NULL);
		return (info->status);
	}
	info->status = EXIT_SUCCESS;
	for (bp = get_builtins(); bp->name; bp += 1)
	{
    do { rc = write(STDOUT_FILENO, bp->help, _strlen(bp->help)); } while(rc == -1 && errno == EINTR);
		/*write(STDOUT_FILENO, bp->help, _strlen(bp->help));*/
    do { rc = write(STDOUT_FILENO, "\n", 1); } while(rc == -1 && errno == EINTR);
		/*write(STDOUT_FILENO, "\n", 1);*/
	}
	return (info->status);
}
