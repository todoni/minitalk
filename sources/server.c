#include "../includes/minitalk.h"

t_server	g_s;

#include <stdio.h>
void	print_char_handler(int signo, siginfo_t *info, void *ucontext)
{
	(void)ucontext;
	if (g_s.pid == 0)
	{
		//write(1, "init\n", 5);
		g_s.pid = info->si_pid;
		kill(g_s.pid, SIGUSR1);
	}
	else
	{	
		g_s.message[g_s.count] <<= 1;
		if (signo == SIGUSR1)
			g_s.message[g_s.count] |= 1;
		//printf("%d\n", g_s.message[g_s.count]);
		if (++g_s.msg_count > 7)
		{
			//write(1, "hi\n", 3);
			//write(1, &g_s.message[g_s.count], 1);
			if (g_s.message[g_s.count] == '\0')
			{
				write(1, g_s.message, g_s.count);
				kill(info->si_pid, SIGUSR2);
				g_s.count = 0;
				g_s.pid = 0;
			}
			else
			{
				if (g_s.count == 4095)
				{
					write(1, g_s.message, 4096);
					g_s.count = 0;
				}
				else
					++g_s.count;
			}
			g_s.msg_count = 0;
			kill(info->si_pid, SIGUSR1);
		}
		else
			kill(info->si_pid, SIGUSR1);	
	}
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
