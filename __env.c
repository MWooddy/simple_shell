#include "builtins.h"

/**
  * __env - displays environment
  * @info: arguments passed
  * Return: int
  */
int __env(info_t *info)
{
	env_t *var;
  int rc;
	info->status = EXIT_SUCCESS;

	for (var = info->env; var; var = var->next)
	{
		if (var->key)
		{
			do 
			{
				rc = write(STDOUT_FILENO, var->key, _strlen(var->key));
			}while(rc == -1 && errno == EINTR);
			/*write(STDOUT_FILENO, var->key, _strlen(var->key));*/}
		do
		{
			rc = write(STDOUT_FILENO, "=", 1);
		}while(rc == -1 && errno == EINTR);
		/*write(STDOUT_FILENO, "=", 1);*/
		if (var->val)
		{
			do
			{
				rc =  write(STDOUT_FILENO, var->val, _strlen(var->val));
			}while(rc == -1 && errno == EINTR);
			/*write(STDOUT_FILENO, var->val, _strlen(var->val));*/}
		do
		{
			rc = write(STDOUT_FILENO, "\n", 1);
		}while(rc == -1 && errno == EINTR);
		/*write(STDOUT_FILENO, "\n", 1);*/}
	return (info->status);
}
