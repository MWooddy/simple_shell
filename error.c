#include "error.h"

/**
  * perrorl - print a formatted message to standard error
  * @msg: error message
  * @...: NULL-terminated list of context strings to prepend
  */
void perrorl(const char *msg, ...)
{
	const char *str;
	va_list context;
  int rc;
  
	va_start(context, msg);
	while ((str = va_arg(context, char *)))
	{
    do { rc = write(STDERR_FILENO, str, _strlen(str)); } while(rc == -1 && errno == EINTR);
    do { rc = write(STDERR_FILENO, ": ", 2); } while(rc == -1 && errno == EINTR);
		/*write(STDERR_FILENO, str, _strlen(str));
		write(STDERR_FILENO, ": ", 2);*/
	}
	va_end(context);

	if (msg)
		{
      
      do { rc = write(STDERR_FILENO, msg, _strlen(msg)); } while(rc == -1 && errno == EINTR);/*write(STDERR_FILENO, msg, _strlen(msg));*/}
  do { rc = write(STDERR_FILENO, "\n", 1); } while(rc == -1 && errno == EINTR);
	/*write(STDERR_FILENO, "\n", 1);*/
}


/**
  * perrorl_default - print a formatted message to standard error
  * @arg0: argument vector
  * @lineno: line number
  * @msg: error message
  * @...: NULL-terminated list of context strings to prepend
  */
void perrorl_default(const char *arg0, size_t lineno, const char *msg, ...)
{
	char *linenostr = num_to_str(lineno);
	const char *str = NULL;
	va_list ap;
  int rc;

	if (arg0)
		{
      do { rc = write(STDERR_FILENO, arg0, _strlen(arg0)); } while(rc == -1 && errno == EINTR);
      /*write(STDERR_FILENO, arg0, _strlen(arg0));*/}
  do { rc = write(STDERR_FILENO, ": ", 2); } while(rc == -1 && errno == EINTR);
	/*write(STDERR_FILENO, ": ", 2);*/

	if (linenostr)
		{
      do { rc = write(STDERR_FILENO, linenostr, _strlen(linenostr)); } while(rc == -1 && errno == EINTR);
      /*write(STDERR_FILENO, linenostr, _strlen(linenostr));*/}
	do { rc = write(STDERR_FILENO, ": ", 2); } while(rc == -1 && errno == EINTR);
  /*write(STDERR_FILENO, ": ", 2);*/

	va_start(ap, msg);
	while ((str = va_arg(ap, char *)))
	{
    do { rc = write(STDERR_FILENO, str, _strlen(str)); } while(rc == -1 && errno == EINTR);
		/*write(STDERR_FILENO, str, _strlen(str));*/
    do { rc = write(STDERR_FILENO, ": ", 2); } while(rc == -1 && errno == EINTR);
		/*write(STDERR_FILENO, ": ", 2);*/
	}
	va_end(ap);

	if (msg)
		{
      do { rc = write(STDERR_FILENO, msg, _strlen(msg)); } while(rc == -1 && errno == EINTR);
      /*write(STDERR_FILENO, msg, _strlen(msg));*/}
	do { rc = write(STDERR_FILENO, "\n", 1); } while(rc == -1 && errno == EINTR);
  /*write(STDERR_FILENO, "\n", 1);*/
	free(linenostr);
}
