/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_argument_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohan <sohan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 23:37:37 by sohan             #+#    #+#             */
/*   Updated: 2021/09/28 23:37:39 by sohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_argument_value(va_list arg_ptr, t_component *cmp)
{
	if (cmp->bit & int_mask)
		cmp->_int = va_arg(arg_ptr, int);
	else if (cmp->bit & string)
		cmp->str = va_arg(arg_ptr, char *);
	else if (cmp->bit & pointer)
		cmp->_pointer = va_arg(arg_ptr, unsigned long long);
	else if (cmp->bit & u_int_mask)
		cmp->_uint = va_arg(arg_ptr, unsigned int);
	else if (cmp->bit & percent)
		cmp->str = "%";
}

int	integer_to_string(t_component *cmp)
{
	char	*base;

	base = 0;
	if (cmp->bit & int_base_mask)
		base = "0123456789";
	else if (cmp->bit & x_base_mask)
		base = "0123456789abcdef";
	else if (cmp->bit & hex_up)
		base = "0123456789ABCDEF";
	if (!cmp->str && !(cmp->bit & character))
	{
		if (cmp->bit & int_mask)
			cmp->str = ft_itoa(cmp->_int, base);
		else if (cmp->bit & u_int_mask)
			cmp->str = ft_utoa(cmp->_uint, base);
		else if (!base)
			cmp->str = "(null)";
		else
			cmp->str = ft_ptoa(cmp->_pointer, base);
		if (!cmp->str)
			return (-1);
	}
	return (1);
}

void	set_minimum_field_width(const char **fmt, t_component *cmp)
{
	set_flag(fmt, &cmp->bit);
	set_width(fmt, &cmp->width_total);
	set_precision(fmt, cmp);
	set_type(fmt, &cmp->bit);
}
