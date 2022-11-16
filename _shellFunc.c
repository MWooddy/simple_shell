#include "shell.h"

/*TODO: Fix  unsued assigned attribute Error for write*/

void _shellPrompt(void);
void handle(int signals);
void _EOF(char *buffer);
void shell_exit(char **command);
char **tokening(char *buffer, const char *s);

/*TODO: Fix  unsued assigned attribute Error for write*/
/*prints the prompt*/
void _shellPrompt(void)
{
  int rc;
  /*do { rc = write(STDOUT_FILENO, env[i], len); } while(rc == -1 && errno == EINTR);*/
	if (isatty(STDIN_FILENO))
    do {rc = write(STDOUT_FILENO, "#OUR_Shell>>$ ", 13); } while(rc == -1 && errno == EINTR);
		/*write(STDOUT_FILENO, "#OUR_Shell>> ", 13);*/
}

/*TODO: Fix  unsued assigned attribute Error for write*/ 
/* handle Ctr + C signal.*/
void handle(int signals)
{
  int rc;
  /*do { rc = write(STDOUT_FILENO, env[i], len); } while(rc == -1 && errno == EINTR);*/
	(void)signals;
  do {rc = write(STDOUT_FILENO, "\n#OUR_Shell>>$ ", 16); } while(rc == -1 && errno == EINTR);
	/*write(STDOUT_FILENO, "\n#OUR_Shell>> ", 16);*/
}

/*TODO: Fix  unsued assigned attribute Error for write*/
/*checks if buffer is EOF*/
void _EOF(char *buffer)
{
  int rc;
  /*do { rc = write(STDOUT_FILENO, env[i], len); } while(rc == -1 && errno == EINTR);*/
	if (buffer)
	{
		free(buffer);
		buffer = NULL;
	}

	if (isatty(STDIN_FILENO))
      do { rc = write(STDOUT_FILENO, "\n", 1); } while(rc == -1 && errno == EINTR);
		/*write(STDOUT_FILENO, "\n", 1);*/
	free(buffer);
	exit(EXIT_SUCCESS);
}


/*exits the shell.*/
void shell_exit(char **command)
{
	int sta_tus = 0;

	if (command[1] == NULL)
	{
		free_dp(command);
		exit(EXIT_SUCCESS);
	}

	sta_tus = _atoi(command[1]);
	free_dp(command);
	exit(sta_tus);
}

/*split and create a full string command.*/
char **tokening(char *buffer, const char *s)
{
	char *token = NULL, **commands = NULL;
	size_t bufsize = 0;
	int i = 0;

	if (buffer == NULL)
		return (NULL);

	bufsize = _strlen(buffer);
	commands = malloc((bufsize + 1) * sizeof(char *));
	if (commands == NULL)
	{
		perror("Unable to allocate buffer");
		free(buffer);
		free_dp(commands);
		exit(EXIT_FAILURE);
	}

	token = strtok(buffer, s);
	while (token != NULL)
	{
		commands[i] = malloc(_strlen(token) + 1);
		if (commands[i] == NULL)
		{
			perror("Unable to allocate buffer");
			free_dp(commands);
			return (NULL);
		}
		_strcpy(commands[i], token);
		token = strtok(NULL, s);
		i++;
	}
	commands[i] = NULL;
	return (commands);
}
