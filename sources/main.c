#include "../includes/minitalk.h"

struct	sigaction	act_new;
struct	sigaction	act_prev;

struct	sigaction	act_sigusr1;
struct	sigaction	act_sigusr1_prev;

int		resting;

void sigint_handler(int signo)
{

   ft_printf("Ctrl-C(SIGINT:%d) received!!\n", signo);
   //printf("Press Ctrl-C again to terminate process.\n");
   //sigaction(SIGINT, &act_prev, NULL);
   //printf("You'll not see me anymore. bye. :(\n");
   resting += 1;
   resting *= -1;
}

void sigusr1_handler(int signo)
{
	ft_printf("sigusr1:%d signal\n", signo);
}

int main( void)
{
	pid_t	pid;

	pid = getpid();
	act_new.sa_handler = sigint_handler;
	act_sigusr1.sa_handler = sigusr1_handler;
	sigemptyset( &act_new.sa_mask);
	sigemptyset(&act_sigusr1.sa_mask);
	
	ft_printf("pid: %d\n", pid);
	sigaction( SIGINT, &act_new, &act_prev); 
	sigaction(SIGUSR1, &act_sigusr1, &act_sigusr1_prev); 
	kill(pid, SIGUSR1);
	kill(pid, SIGUSR1);
	while(!resting)
	{
		ft_printf( "running...\n");
		sleep(1);
	}
	while(resting)
	{
		ft_printf("Well I'll go get some rest. Ho-hum\n");
		pause();
		ft_printf("Did you wake me up?\n");
	}
	ft_printf("bye\n");
	return (0);
}
