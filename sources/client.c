#include "../includes/minitalk.h"

t_client	g_c;

void	pong(int signo)
{
	(void)signo;
	g_c.binary = *g_c.message;
	if (g_c.binary & (1 << g_c.sigcount))
		kill(g_c.pid, SIGUSR1);
	else
		kill(g_c.pid, SIGUSR2);
	--g_c.sigcount;
	if (g_c.sigcount == -1)
	{
		g_c.sigcount = 7;
		//if (!*g_c.message)
		//	exit(0);
		++g_c.message;
	}
}

int main(int argc, char **argv)
{
	pid_t	pid;
	char	*message;
	//struct sigaction	act_sigusr1;
	//struct sigaction	act_sigusr2;

	pid = ft_atoi(argv[1]);
	if (argc != 3 || pid == 0)
	{
		write(2, "Usage: ./client [pid] [message]\n", 32);
		exit(1);
	}
	message = argv[2];
	g_c.sigcount = 7;
	g_c.pid = pid;
	g_c.message = message;
	//sigemptyset(&act_sigusr1.sa_mask);
	//sigemptyset(&act_sigusr2.sa_mask);
	//act_sigusr1.sa_handler = pong;
	//act_sigusr2.sa_handler = exit;
	//sigaction(SIGUSR1, &act_sigusr1, NULL);
	//sigaction(SIGUSR2, &act_sigusr2, NULL);
	signal(SIGUSR1, pong);
	signal(SIGUSR2, exit);
	kill(pid, SIGUSR1);
	while (1)
		pause();
	return (0);
}
