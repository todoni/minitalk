#include "../includes/minitalk.h"

void string_to_binary(char *msg, pid_t pid)
{
    int len;
	int	val;
	int	count;

	len = ft_strlen(msg);
	count = 0;
    while(count < len)
	{
        // convert each char to
        // ASCII value
        val = msg[count]; 
		ft_printf("count:%d\n", count);
        // Convert ASCII value to binary
        while (val > 0)
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
        }
		count++;
    }
}

int main(int argc, char **argv)
{
	pid_t	pid;
	char	*message;

	if (argc <= 1)
		ft_printf("Too few arguments. Usage: ./client [pid] [message]\n");
	pid = ft_atoi(argv[1]);
	message = argv[2];
	ft_printf("server pid: %d\n", pid);
	string_to_binary(message, pid);
	return (0);
}
