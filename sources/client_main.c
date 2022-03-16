#include "../includes/minitalk.h"
#include "time.h"

void string_to_binary(char *msg, pid_t pid)
{
	int	count;
	int	sigcount;

	count = 0;
    while(msg[count])
	{
		sigcount = 7;
		while (sigcount > -1)
		{
			if (msg[count] & (1 << sigcount))
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(50);
			--sigcount;
		}

        /*while (val > 0)
        {
            if (val % 2 != 0)
			{
				kill(pid, SIGUSR1);
				usleep(200);
			}
			else
			{
				kill(pid, SIGUSR2);
				usleep(200);
			}
            val /= 2;
			++sigcount;
        }*/
		++count;	
	}
}

#include <stdio.h>

int main(int argc, char **argv)
{
	pid_t	pid;
	char	*message;
	clock_t	start, end = 0;

	if (argc <= 1)
		ft_printf("Too few arguments. Usage: ./client [pid] [message]\n");
	pid = ft_atoi(argv[1]);
	message = argv[2];
	ft_printf("server pid: %d\n", pid);
	start = clock();
	string_to_binary(message, pid);
	end = clock();
	printf("소요된 시간 : %.3f \n", (float)(end - start) / CLOCKS_PER_SEC);
	return (0);
}
