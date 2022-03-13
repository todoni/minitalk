#include "../includes/minitalk.h"

int	binary;

void	sigusr1_handler(int signo)
{
	if (binary != 0)
		binary <<= 1;
	binary |= 1;
	ft_printf("[%d]usr1 : %d\n", signo, binary);
}

void	sigusr2_handler(int signo)
{
	binary <<= 1;
	ft_printf("[%d]usr2 : %d\n", signo, binary);
}

int main(void)
{
	pid_t	pid;
	int		count;
	struct sigaction	act_sigusr1;
	struct sigaction	act_sigusr2;
	
	pid = getpid();
	count = 0;
	binary = 0b00000000;
	ft_printf("server PID[%d]\n", pid);
	act_sigusr1.sa_handler = sigusr1_handler;
	act_sigusr2.sa_handler = sigusr2_handler;
	sigemptyset(&act_sigusr1.sa_mask);
	sigemptyset(&act_sigusr2.sa_mask);
	sigaction(SIGUSR1, &act_sigusr1, NULL);
	sigaction(SIGUSR2, &act_sigusr2, NULL);
	while (1)
	{
		pause();
		ft_printf("%c\n", binary);
		binary = 0;
	}
	return (0);
}
