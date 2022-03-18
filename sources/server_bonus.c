#include "../includes/minitalk.h"

t_server	g_s;

void	terminate(void)
{
	if (write(2, "An error occured.\n", 18) == -1)
		exit(3);
	exit(1);
}

void	hand_shake(int signo, siginfo_t *info, void *ucontext)
{
	g_s.pid = info->si_pid;
	if (kill(g_s.pid, signo) == -1 || \
		sigaction(signo, &g_s.act_ping, NULL) == -1)
		terminate();
	(void)ucontext;
}

void	ping(int signo, siginfo_t *info, void *ucontext)
{
	g_s.message[g_s.str_count] <<= 1;
	g_s.message[g_s.str_count] |= (signo == SIGUSR1);
	if (++g_s.bit_count > 7)
	{
		g_s.bit_count = 0;
		if (g_s.message[g_s.str_count] == '\0')
		{
			if (write(1, g_s.message, g_s.str_count) == -1 || \
				kill(g_s.pid, SIGUSR2) == -1 || \
				sigaction(SIGUSR1, &g_s.act_handshake, NULL) == -1)
				terminate();
			g_s.pid = 0;
			g_s.str_count = 0;
			return ;
		}
		if (++g_s.str_count == BUFFER_SIZE)
		{
			if (write(1, g_s.message, BUFFER_SIZE) == -1)
				terminate();
			g_s.str_count = 0;
		}
	}
	if (kill(info->si_pid, SIGUSR1) == -1)
		terminate();
	(void)ucontext;
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	if (pid < 100)
		terminate();
	if (ft_printf("server PID[%d]\n", pid) == -1 || \
		sigemptyset(&g_s.act_ping.sa_mask) == -1 || \
		sigemptyset(&g_s.act_handshake.sa_mask) == -1)
		terminate();
	g_s.act_ping.sa_flags = SA_SIGINFO | SA_NODEFER;
	g_s.act_handshake.sa_flags = SA_SIGINFO | SA_NODEFER;
	g_s.act_ping.sa_sigaction = ping;
	g_s.act_handshake.sa_sigaction = hand_shake;
	if (sigaction(SIGUSR1, &g_s.act_handshake, NULL) == -1 || \
		sigaction(SIGUSR2, &g_s.act_ping, NULL) == -1)
		terminate();
	while (1)
		pause();
	return (0);
}
