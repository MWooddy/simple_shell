#include "shell.h"

/**
  * _sigint - reprompts
  * @signal: signal passed
  */
void _sigint(int signal __attribute__((unused)))
{
  int rc;
  
	fflush(STDIN_FILENO);
  do { rc = write(STDERR_FILENO, "\n$ ", 3); } while(rc == -1 && errno == EINTR);
	/*write(STDERR_FILENO, "\n$ ", 3);*/
}
