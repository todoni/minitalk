#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <unistd.h>
# include <signal.h>
# include "../libftprintf/ft_printf.h"

# define BUFFER_SIZE 4096

typedef struct s_server
{
	char				message[BUFFER_SIZE];
	int					str_count;
	int					bit_count;
	int					pid;
	struct sigaction	act_ping;
	struct sigaction	act_handshake;
}	t_server;

typedef struct s_client
{
	char	*message;
	int		sigcount;
	int		pid;
}	t_client;

#endif
