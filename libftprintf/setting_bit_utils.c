/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_bit_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohan <sohan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 23:37:47 by sohan             #+#    #+#             */
/*   Updated: 2021/09/28 23:37:50 by sohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_flag(char c)
{
	if (c == '0' || c == '-' || c == '+' || c == ' ' || c == '#')
		return (1);
	return (0);
}

void	set_flag(const char **fmt, int *flag)
{
	while (is_flag(**fmt))
	{
		if (**fmt == '0')
			*flag |= zero;
		else if (**fmt == '-')
			*flag |= minus;
		else if (**fmt == '+')
			*flag |= plus;
		else if (**fmt == ' ')
			*flag |= space;
		else if (**fmt == '#')
			*flag |= sharp;
		move_fmt_by_length(fmt, 1);
	}
}

void	set_precision(const char **fmt, t_component *cmp)
{
	if (**fmt == '.')
	{
		move_fmt_by_length(fmt, 1);
		cmp->width_precision = ft_atoi(*fmt);
		move_fmt_by_length(fmt, find_digit_width(cmp->width_precision));
		cmp->bit |= precision;
	}
}

void	set_type(const char **fmt, int *type)
{
	if (**fmt == 'c')
		*type |= character;
	else if (**fmt == 's')
		*type |= string;
	else if (**fmt == 'p')
		*type |= pointer;
	else if (**fmt == 'd')
		*type |= integer;
	else if (**fmt == 'i')
		*type |= integer;
	else if (**fmt == 'u')
		*type |= u_integer;
	else if (**fmt == 'x')
		*type |= hex_low;
	else if (**fmt == 'X')
		*type |= hex_up;
	else if (**fmt == '%')
		*type |= percent;
	move_fmt_by_length(fmt, 1);
}
