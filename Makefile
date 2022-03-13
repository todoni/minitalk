# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sohan <sohan@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/11 15:38:21 by sohan             #+#    #+#              #
#    Updated: 2022/03/11 15:39:01 by sohan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INCLUDES_DIR = ./includes/
LIBFTPF_INC_DIR = ./libftprintf/
SOURCE_DIR = ./sources/
OBJECT_DIR = objects
FILES = \
		main \
		client \
		server \

vpath %.c $(SOURCE_DIR)

SOURCES = $(addprefix $(SOURCE_DIR), $(addsuffix .c, $(FILES)))
OBJECTS = $(addprefix $(OBJECT_DIR)/, $(addsuffix .o, $(FILES)))

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -Llibftprintf -lftprintf

NAME = client server
LIBFTPF = $(addprefix $(LIBFTPF_INC_DIR), libftprintf.a)


all: $(NAME)

$(NAME): $(OBJECT_DIR) $(OBJECTS) $(LIBFTPF)
	$(CC) $(CFLAGS) $(LDFLAGS) -I$(INCLUDES_DIR) $(OBJECTS) -o $@

$(OBJECT_DIR):
	@mkdir -p $(OBJECT_DIR)

$(OBJECT_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -I$(INCLUDES_DIR) -I$(LIBFTPF_INC_DIR) -c $< -o $@

$(LIBFTPF):
	@echo "make libftprintf"
	@make -C libftprintf/

clean:
	rm -rf $(OBJECT_DIR)
	@make -C $(LIBFTPF_INC_DIR) clean

fclean: clean
	rm -f $(NAME)
	@make -C $(LIBFTPF_INC_DIR) fclean

re : fclean all

.PHONY: all clean fclean re
