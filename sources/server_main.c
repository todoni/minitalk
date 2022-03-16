#include "../includes/minitalk.h"

t_server	g_s;

void	sigusr1_handler(int signo)
{
	//if (g_s.binary != 0)
	g_s.binary <<= 1;
	g_s.binary |= 1;
	++g_s.count;
	signo = (int)signo;
	//ft_printf("[%d]usr1 : %d\n", g_s.count, g_s.binary);
}

void	sigusr2_handler(int signo)
{
	g_s.binary <<= 1;
	++g_s.count;
	signo = (int)signo;
	//ft_printf("[%d]usr2 : %d\n", g_s.count, g_s.binary);
}

int	reverse(int	binary)
{
	int	r;
	int	i;
	int	b;
	int	tmp;

	i = 0;
	r = 0;
	b = 128;
	tmp = binary;
	while (i < 8)
	{
		r += (tmp & 1) * b;
		b /= 2;
		tmp >>= 1;
		i++;
	}
	return (r);
}

#include <time.h>
#include <stdio.h>

int main(void)
{
	pid_t	pid;
	int		count;
	struct sigaction	act_sigusr1;
	struct sigaction	act_sigusr2;
	clock_t	start, end = 0;

	pid = getpid();
	count = 0;
	ft_printf("server PID[%d]\n", pid);
	act_sigusr1.sa_handler = sigusr1_handler;
	act_sigusr2.sa_handler = sigusr2_handler;
	sigemptyset(&act_sigusr1.sa_mask);
	sigemptyset(&act_sigusr2.sa_mask);
	sigaction(SIGUSR1, &act_sigusr1, NULL);
	sigaction(SIGUSR2, &act_sigusr2, NULL);
	start = clock();
	while (1)
	{
		pause();
		//count = reverse(g_s.binary);
		if (g_s.count && g_s.count % 8 == 0)
		{
			ft_printf("%c",g_s.binary);
			g_s.binary = 0;
		}
	}
	end = clock();
	printf("소요된 시간 : %.3f \n", (float)(end - start) / CLOCKS_PER_SEC);
	return (0);
}
