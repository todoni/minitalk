# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sohan <sohan@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/28 21:19:08 by sohan             #+#    #+#              #
#    Updated: 2021/09/28 21:19:11 by sohan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
SOURCES = ft_printf.c ft_atoi.c ft_strlen.c ft_isdigit.c ft_itoa.c ft_utoa.c ft_ptoa.c ft_calloc.c ft_memset.c heap.c function_priority_utils.c initialize_utils.c print_flag_utils.c print_general_utils.c setting_bit_utils.c set_argument_utils.c setting_function_utils1.c setting_function_utils2.c setting_length_utils.c
SRCBONUS = ft_printf.c ft_atoi.c ft_strlen.c ft_isdigit.c ft_itoa.c ft_utoa.c ft_ptoa.c ft_calloc.c ft_memset.c heap.c function_priority_utils.c initialize_utils.c print_flag_utils.c print_general_utils.c setting_bit_utils.c set_argument_utils.c setting_function_utils1.c setting_function_utils2.c setting_length_utils.c

all: $(NAME)

bonus:
	make BONUS=1 all

OBJECTS = $(SOURCES:.c=.o)

OBJBONUS = $(SRCBONUS:.c=.o)

ifdef BONUS
$(NAME): $(OBJBONUS)
	ar rc $@ $(OBJBONUS)
else
$(NAME): $(OBJECTS)
	ar rc $@ $(OBJECTS)
endif

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -rf $(OBJECTS)
	rm -rf $(OBJBONUS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean

