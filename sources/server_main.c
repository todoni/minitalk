#include "../includes/minitalk.h"

t_server	g_s;

void	sigusr1_handler(int signo, siginfo_t *info, void *ucontext)
{
	g_s.binary <<= 1;
	g_s.binary |= 1;
	++g_s.count;
	(void)signo, (void)info, (void)ucontext;
	kill(info->si_pid, SIGUSR1);
}

void	sigusr2_handler(int signo, siginfo_t *info, void *ucontext)
{
	g_s.binary <<= 1;
	++g_s.count;
	(void)signo, (void)info, (void)ucontext;
	kill(info->si_pid, SIGUSR1);
}

int main(void)
{
	pid_t	pid;
	int		count;
	struct sigaction	act_sigusr1;
	struct sigaction	act_sigusr2;

	pid = getpid();
	count = 0;
	ft_printf("server PID[%d]\n", pid);
	sigemptyset(&act_sigusr1.sa_mask);
	sigemptyset(&act_sigusr2.sa_mask);
	act_sigusr1.sa_flags |= SA_SIGINFO;
	act_sigusr2.sa_flags |= SA_SIGINFO;
	act_sigusr1.sa_flags |= SA_NODEFER;
	act_sigusr2.sa_flags |= SA_NODEFER;
	act_sigusr1.sa_sigaction = sigusr1_handler;
	act_sigusr2.sa_sigaction = sigusr2_handler;

	sigaction(SIGUSR1, &act_sigusr1, NULL);
	sigaction(SIGUSR2, &act_sigusr2, NULL);
	while (1)
	{
		pause();
		if (g_s.count && g_s.count % 8 == 0)
		{
			write(1, &g_s.binary, 1);
			g_s.binary = 0;
			g_s.count = 0;
		}
	}
	return (0);
}
