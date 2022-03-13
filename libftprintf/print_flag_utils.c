/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_flag_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohan <sohan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 21:25:26 by sohan             #+#    #+#             */
/*   Updated: 2021/09/28 21:25:29 by sohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_one_space(int ret)
{
	write(1, " ", 1);
	ret += 1;
	return (ret);
}

int	print_plus(int num, int ret)
{
	if (num >= 0)
	{
		write(1, "+", 1);
		ret += 1;
	}
	return (ret);
}

int	print_prefix_pointer(int ret)
{
	write(1, "0x", 2);
	ret += 2;
	return (ret);
}

int	print_prefix_sharp_up(int ret)
{
	write(1, "0X", 2);
	ret += 2;
	return (ret);
}

int	print_prefix_sharp_low(int ret)
{
	write(1, "0x", 2);
	ret += 2;
	return (ret);
}
