#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include "../libftprintf/ft_printf.h"

typedef struct s_server
{
	unsigned char			binary;
	char					message[4096];
	unsigned long long int	count;
	int						index;
}	t_server;

#endif
