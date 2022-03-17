#include "../includes/minitalk.h"

t_server	g_s;

void	print_char_handler(int signo, siginfo_t *info, void *ucontext)
{
	(void)signo, (void)info, (void)ucontext;
	if (g_s.count && g_s.count % 8 == 0)
	{
		write(1, &g_s.binary, 1);
		g_s.binary = 0;
		g_s.count = 0;
	}
	g_s.binary <<= 1;
	if (signo ==SIGUSR1)
		g_s.binary |= 1;
	++g_s.count;
	//if ()
	kill(info->si_pid, SIGUSR1);
}

int main(void)
{
	pid_t	pid;
	int		count;
	struct sigaction	act_print_char;

	pid = getpid();
	count = 0;
	ft_printf("server PID[%d]\n", pid);
	sigemptyset(&act_print_char.sa_mask);
	act_print_char.sa_flags |= SA_SIGINFO;
	act_print_char.sa_flags |= SA_NODEFER;
	act_print_char.sa_sigaction = print_char_handler;
	sigaction(SIGUSR1, &act_print_char, NULL);
	sigaction(SIGUSR2, &act_print_char, NULL);
	while (1)
		pause();
	return (0);
}
