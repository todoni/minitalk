#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include "../libftprintf/ft_printf.h"

typedef struct s_server
{
	unsigned char		binary;
	char				message[4096];
	int					count;
	int					pid;
	int					msg_count;
}	t_server;

typedef struct s_client
{
	unsigned char			binary;
	char					*message;
	unsigned long long int	count;
	int						sigcount;
	int						pid;
}	t_client;

#endif
