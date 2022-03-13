/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohan <sohan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 21:17:40 by sohan             #+#    #+#             */
/*   Updated: 2021/09/28 21:17:44 by sohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	move_fmt_by_length(const char **fmt, int length)
{
	(*fmt) += length;
}

int	find_digit_width(int num)
{
	int	digit;

	digit = 0;
	if (!num)
		digit = 1;
	while (num)
	{
		num /= 10;
		digit++;
	}
	return (digit);
}

int	do_print(const char **fmt, va_list arg_ptr, int ret)
{
	t_component	cmp;
	t_fp		fp[MAX_SIZE];
	t_heap		heap;
	int			malloc_error;

	init_component(&cmp);
	heap_initialize(&heap);
	init_function(fp);
	move_fmt_by_length(fmt, 1);
	set_minimum_field_width(fmt, &cmp);
	get_argument_value(arg_ptr, &cmp);
	malloc_error = integer_to_string(&cmp);
	if (malloc_error == -1)
		return (-1);
	set_print_length(&cmp);
	set_function_usage(cmp.bit, fp);
	set_priority(fp, cmp.bit);
	insert_to_heap(fp, &heap);
	ret = print_by_priority(&heap, &cmp, ret);
	if (cmp.bit & malloc_free)
		free(cmp.str);
	return (ret);
}

int	ft_vprintf(const char **fmt, va_list arg_ptr, int ret)
{
	while (**fmt)
	{
		if (**fmt == '%')
		{
			ret = do_print(fmt, arg_ptr, ret);
			if (ret == -1)
				return (-1);
		}
		if (**fmt == '\0')
			break ;
		if (**fmt != '%')
		{
			ret = print_untyped_character(*fmt, ret);
			move_fmt_by_length(fmt, 1);
		}
	}
	return (ret);
}

int	ft_printf(const char *fmt, ...)
{
	int		ret;
	va_list	arg_ptr;

	ret = 0;
	va_start(arg_ptr, fmt);
	ret = ft_vprintf(&fmt, arg_ptr, ret);
	if (ret == -1)
	{
		write(2, "Memory Allocation Failed!\n", 26);
		return (-1);
	}
	va_end(arg_ptr);
	return (ret);
}
