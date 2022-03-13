/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_function_utils1.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohan <sohan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 23:38:02 by sohan             #+#    #+#             */
/*   Updated: 2021/09/28 23:38:04 by sohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_zero(t_fp function[])
{
	function[ZERO].usage = USED;
	function[SPACE].usage = NOT_USED;
	function[ZERO].print_padding = print_padding_by_length;
}

void	set_pointer(t_fp function[])
{
	function[POINTER].usage = USED;
	function[POINTER].print = print_prefix_pointer;
}

void	set_plus(t_fp function[])
{
	function[PLUS].usage = USED;
	function[PLUS].print_plus = print_plus;
}

void	set_prec(t_fp function[])
{
	function[PRECISION].usage = USED;
	function[PRECISION].print_precision = print_padding_by_length;
}

void	set_space(t_fp function[])
{
	function[ONESPACE].usage = USED;
	function[ONESPACE].print = print_one_space;
}
