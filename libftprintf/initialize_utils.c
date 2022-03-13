/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohan <sohan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 23:36:44 by sohan             #+#    #+#             */
/*   Updated: 2021/09/28 23:36:52 by sohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_component(t_component *cmp)
{
	cmp->_int = 0;
	cmp->_uint = 0;
	cmp->_pointer = 0;
	cmp->bit = 0;
	cmp->str = 0;
	cmp->width_flag = 0;
	cmp->width_padding = 0;
	cmp->width_precision = 0;
	cmp->width_space = 0;
	cmp->width_total = 0;
	cmp->width_str = 0;
}

void	init_function(t_fp fp[])
{
	int	i;

	i = 0;
	while (i < MAX_SIZE)
	{
		fp[i].print = 0;
		fp[i].print_space = 0;
		fp[i].print_padding = 0;
		fp[i].print_precision = 0;
		fp[i].print_string = 0;
		fp[i].print_char = 0;
		fp[i].print_plus = 0;
		fp[i].priority = 0;
		fp[i].usage = NOT_USED;
		i++;
	}
}
