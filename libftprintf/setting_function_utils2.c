/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_function_utils2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohan <sohan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 23:38:13 by sohan             #+#    #+#             */
/*   Updated: 2021/09/28 23:38:15 by sohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_sharp(t_fp function[], int bit)
{
	if (bit & hex_up)
	{
		function[SHARPUP].usage = USED;
		function[SHARPUP].print = print_prefix_sharp_up;
	}
	else
	{
		function[SHARPLOW].usage = USED;
		function[SHARPLOW].print = print_prefix_sharp_low;
	}
}

void	set_character(t_fp function[])
{
	function[CHAR].usage = USED;
	function[CHAR].print_char = print_character;
	function[ARGUMENT].usage = NOT_USED;
}

void	set_string(t_fp function[])
{
	function[ZERO].usage = NOT_USED;
	function[PRECISION].usage = NOT_USED;
}

void	set_function_usage(int bit, t_fp function[])
{
	function[ARGUMENT].usage = USED;
	function[ARGUMENT].print_string = print_argument_by_length;
	function[SPACE].usage = USED;
	function[SPACE].print_space = print_space_by_length;
	if (bit & zero)
		set_zero(function);
	if (bit & pointer)
		set_pointer(function);
	if (bit & plus)
		set_plus(function);
	if (bit & space)
		set_space(function);
	if (bit & sharp)
		set_sharp(function, bit);
	if (bit & character)
		set_character(function);
	if (bit & precision)
		set_prec(function);
	if (bit & string)
		set_string(function);
}
