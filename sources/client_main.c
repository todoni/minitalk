#include "../includes/minitalk.h"
#include "time.h"

void	pong(int signo)
{
	(void)signo;
}
void	string_to_binary(char *msg, pid_t pid)
{
	int	count;
	int	sigcount;

	count = 0;
    while(msg[count])
	{
		sigcount = 7;
		while (sigcount > -1)
		{
			if (msg[count] & (1 << sigcount))
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			pause();
			--sigcount;
		}
        ++count;
	}
}

#include <stdio.h>

int main(int argc, char **argv)
{
	pid_t	pid;
	char	*message;
	struct sigaction	act_sigusr1;

	pid = ft_atoi(argv[1]);
	if (argc != 3 || pid == 0)
	{
		write(1, "Usage: ./client [pid] [message]\n", 32);
		exit(1);
	}
	message = argv[2];
	ft_printf("server pid: %d\n", pid);
	sigemptyset(&act_sigusr1.sa_mask);
	act_sigusr1.sa_handler = pong;
	sigaction(SIGUSR1, &act_sigusr1, NULL);
	string_to_binary(message, pid);
	return (0);
}
