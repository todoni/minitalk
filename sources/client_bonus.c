#include "../includes/minitalk.h"

t_client	g_c;

void	terminate(void)
{
	if (write(2, "An error occured.\n", 18) == -1)
		exit(3);
	exit(1);
}

void	pong(int signo)
{
	if (*g_c.message & (1 << g_c.sigcount))
	{
		if (kill(g_c.pid, SIGUSR1) == -1)
			terminate();
	}
	else
	{
		if (kill(g_c.pid, SIGUSR2) == -1)
			terminate();
	}
	--g_c.sigcount;
	if (g_c.sigcount == -1)
	{
		g_c.sigcount = 7;
		++g_c.message;
	}
	(void)signo;
}

int	main(int argc, char **argv)
{
	g_c.pid = ft_atoi(argv[1]);
	if (argc != 3 || g_c.pid == 0)
	{
		if (write(2, "Usage: ./client [pid] [message]\n", 32) == -1)
			terminate();
		exit(1);
	}
	g_c.sigcount = 7;
	g_c.message = argv[2];
	signal(SIGUSR1, pong);
	signal(SIGUSR2, exit);
	if (kill(g_c.pid, SIGUSR1) == -1)
		terminate();
	while (1)
		pause();
	return (0);
}
