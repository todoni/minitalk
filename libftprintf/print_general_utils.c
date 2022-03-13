/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_general_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohan <sohan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 21:23:13 by sohan             #+#    #+#             */
/*   Updated: 2021/09/28 21:23:15 by sohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_untyped_character(const char *fmt, int ret)
{
	write(1, fmt, 1);
	ret++;
	return (ret);
}

int	print_padding_by_length(int length, int ret)
{
	ret += length;
	while (length--)
		write(1, "0", 1);
	return (ret);
}

int	print_space_by_length(int length, int ret)
{
	ret += length;
	while (length--)
		write(1, " ", 1);
	return (ret);
}

int	print_character(int c, int ret)
{
	write(1, &c, 1);
	ret += 1;
	return (ret);
}

int	print_argument_by_length(char *str, int length, int ret)
{
	write(1, str, length);
	ret += length;
	return (ret);
}
