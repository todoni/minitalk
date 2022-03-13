/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_length_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohan <sohan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 23:38:25 by sohan             #+#    #+#             */
/*   Updated: 2021/09/28 23:38:27 by sohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_width(const char **fmt, int *width)
{
	if (ft_isdigit(**fmt) && **fmt != '0')
	{
		*width = ft_atoi(*fmt);
		move_fmt_by_length(fmt, find_digit_width(*width));
	}
}

void	set_width_flag(t_component	*cmp)
{
	if ((cmp->bit & plus) || (cmp->bit & space))
		cmp->width_flag++;
	if (cmp->bit & sharp)
		cmp->width_flag += 2;
}

void	set_print_length(t_component *cmp)
{
	set_width_flag(cmp);
	cmp->width_str = ft_strlen(cmp->str);
	if (cmp->width_precision && cmp->width_str > cmp->width_precision)
		cmp->width_str = cmp->width_precision;
	cmp->width_padding = cmp->width_precision - cmp->width_str;
	if (cmp->width_padding < 0)
		cmp->width_padding = 0;
	cmp->width_space = cmp->width_total - cmp->width_flag - cmp->width_str;
	if (!(cmp->bit & string))
		cmp->width_space -= cmp->width_padding;
	if (cmp->bit & character)
		cmp->width_space--;
	if (cmp->bit & pointer)
		cmp->width_space -= 2;
	if (cmp->width_space < 0)
		cmp->width_space = 0;
}
