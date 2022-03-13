/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohan <sohan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 13:40:41 by sohan             #+#    #+#             */
/*   Updated: 2021/09/28 21:18:34 by sohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "heap.h"

enum	e_mask
{
	zero = 1 << 13,
	minus = 1 << 12,
	plus = 1 << 11,
	space = 1 << 10,
	sharp = 1 << 9,
	precision = 1 << 8,
	character = 1 << 7,
	string = 1 << 6,
	pointer = 1 << 5,
	integer = 1 << 4,
	u_integer = 1 << 3,
	hex_low = 1 << 2,
	hex_up = 1 << 1,
	percent = 1 << 0,
	int_mask = 0b00000010010000,
	u_int_mask = 0b00000000001110,
	int_base_mask = 0b00000000011000,
	x_base_mask = 0b00000000100100,
	malloc_free = 0b00000010111110,
};

enum	e_funtions
{
	ARGUMENT,
	SPACE,
	ONESPACE,
	PLUS,
	SHARPUP,
	SHARPLOW,
	ZERO,
	POINTER,
	CHAR,
	PRECISION,
	MINUS
};

typedef struct s_component
{
	int						width_space;
	int						width_total;
	int						width_padding;
	int						width_precision;
	int						width_flag;
	int						width_str;
	char					*str;
	int						_int;
	unsigned int			_uint;
	unsigned long long int	_pointer;
	int						bit;
}				t_component;

int		ft_isdigit(char c);
int		ft_atoi(const char *str);
int		ft_strlen(char *str);
int		ft_printf(const char *fmt, ...);
int		find_digit_width(int num);
int		is_flag(char c);
int		integer_to_string(t_component *cmp);
int		print_by_priority(t_heap *heap, t_component *cmp, int ret);
int		print_untyped_character(const char *fmt, int ret);
int		print_padding_by_length(int length, int ret);
int		print_space_by_length(int length, int ret);
int		print_character(int c, int ret);
int		print_argument_by_length(char *str, int length, int ret);
int		print_one_space(int ret);
int		print_plus(int num, int ret);
int		print_prefix_pointer(int ret);
int		print_prefix_sharp_up(int ret);
int		print_prefix_sharp_low(int ret);
char	*ft_itoa(int num, char *base);
char	*ft_utoa(unsigned int num, char *base);
char	*ft_ptoa(unsigned long long int num, char *base);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_calloc(size_t count, size_t size);
void	move_fmt_by_length(const char **fmt, int length);
void	set_flag(const char **fmt, int *flag);
void	set_precision(const char **fmt, t_component *cmp);
void	set_type(const char **fmt, int *type);
void	set_width(const char **fmt, int *width);
void	set_width_flag(t_component	*cmp);
void	set_print_length(t_component *cmp);
void	init_component(t_component *cmp);
void	get_argument_value(va_list arg_ptr, t_component *cmp);
void	set_minimum_field_width(const char **fmt, t_component *cmp);
void	insert_to_heap(t_fp function[], t_heap *heap);

#endif
