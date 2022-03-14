#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include "../libftprintf/ft_printf.h"

typedef struct s_server
{
	int	binary;
	int	count;
}	t_server;

void	sigint_handler(int signo);
void	sigusr1_handler(int signo);
void	display_pid();

#endif
