#include "../includes/minitalk.h"

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

void	send_exit_signal(int pid)
{
	int	count;

	count = 0;
	while (count < 8)
	{
		kill(pid, SIGUSR2);
		pause();
		count++;
	}
}

int main(int argc, char **argv)
{
	pid_t	pid;
	char	*message;
	struct sigaction	act_sigusr1;
	struct sigaction	act_sigusr2;

	pid = ft_atoi(argv[1]);
	if (argc != 3 || pid == 0)
	{
		write(2, "Usage: ./client [pid] [message]\n", 32);
		exit(1);
	}
	message = argv[2];
	sigemptyset(&act_sigusr1.sa_mask);
	act_sigusr1.sa_handler = pong;
	act_sigusr2.sa_handler = exit;
	sigaction(SIGUSR1, &act_sigusr1, NULL);
	sigaction(SIGUSR2, &act_sigusr2, NULL);
	string_to_binary(message, pid);
	send_exit_signal(pid);
	return (0);
}
