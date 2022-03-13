/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohan <sohan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 23:33:55 by sohan             #+#    #+#             */
/*   Updated: 2021/09/28 23:34:06 by sohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# define NOT_USED -1
# define USED 1
# define FIRST -1

typedef struct s_functions
{
	int	(*print_space)(int length, int ret);
	int	(*print_padding)(int length, int ret);
	int	(*print_precision)(int length, int ret);
	int	(*print)(int ret);
	int	(*print_string)(char *fmt, int length, int ret);
	int	(*print_char)(int c, int ret);
	int	(*print_plus)(int num, int ret);
	int	(*print_minus)(int ret);
	int	usage;
	int	priority;
}				t_fp;

void	init_function(t_fp function[]);
void	set_zero(t_fp function[]);
void	set_pointer(t_fp function[]);
void	set_plus(t_fp function[]);
void	set_prec(t_fp function[]);
void	set_space(t_fp function[]);
void	set_sharp(t_fp function[], int bit);
void	set_character(t_fp function[]);
void	set_string(t_fp function[]);
void	set_function_usage(int bit, t_fp function[]);
int		get_used_number(t_fp function[]);
void	set_priority(t_fp function[], int bit);

#endif
