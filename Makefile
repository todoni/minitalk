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
		server \
		client \

FILES_BONUS = \
		server_bonus \
		client_bonus \

vpath %.c $(SOURCE_DIR)

OBJECTS = $(addprefix $(OBJECT_DIR)/, $(addsuffix .o, $(FILES)))
OBJECTS_BONUS = $(addprefix $(OBJECT_DIR)/, $(addsuffix .o, $(FILES_BONUS)))

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -Llibftprintf -lftprintf

NAME = client server
LIBFTPF = $(addprefix $(LIBFTPF_INC_DIR), libftprintf.a)

all: $(LIBFTPF) $(NAME)

bonus:
	make BONUS=1 all

ifdef BONUS
$(NAME): $(OBJECT_DIR) $(OBJECTS_BONUS)
	$(CC) $(CFLAGS) $(LDFLAGS) -I$(INCLUDES_DIR) $</$@_bonus.o -o $@
else
$(NAME): $(OBJECT_DIR) $(OBJECTS)
	$(CC) $(CFLAGS) $(LDFLAGS) -I$(INCLUDES_DIR) $</$@.o -o $@
endif

$(OBJECT_DIR):
	@echo make object folder
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

.PHONY: all clean fclean re bonus
