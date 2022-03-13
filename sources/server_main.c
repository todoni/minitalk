#include "../includes/minitalk.h"


int main( void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("server PID[%d]\n", pid);
	return (0);
}
