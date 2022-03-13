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
SERVER_FILES = \
		server_main \

CLIENT_FILES = \
		client_main \

vpath %.c $(SOURCE_DIR)

SRC_CLIENT = $(addprefix $(SOURCE_DIR), $(addsuffix .c, $(CLIENT_FILES)))
SRC_SERVER = $(addprefix $(SOURCE_DIR), $(addsuffix .c, $(SERVER_FILES)))
OBJ_CLIENT = $(addprefix $(OBJECT_DIR)/, $(addsuffix .o, $(CLIENT_FILES)))
OBJ_SERVER = $(addprefix $(OBJECT_DIR)/, $(addsuffix .o, $(SERVER_FILES)))

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -Llibftprintf -lftprintf

NAME = client server
LIBFTPF = $(addprefix $(LIBFTPF_INC_DIR), libftprintf.a)


all: $(LIBFTPF) $(NAME)

#$(NAME): $(OBJECT_DIR) $(OBJECTS) $(LIBFTPF)
#	$(CC) $(CFLAGS) $(LDFLAGS) -I$(INCLUDES_DIR) $(OBJECTS) -o $@

client: $(OBJECT_DIR) $(OBJ_CLIENT)
	$(CC) $(CFLAGS) $(LDFLAGS) -I$(INCLUDES_DIR) $(OBJ_CLIENT) -o $@
	
server: $(OBJECT_DIR) $(OBJ_SERVER)
	$(CC) $(CFLAGS) $(LDFLAGS) -I$(INCLUDES_DIR) $(OBJ_SERVER) -o $@

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

.PHONY: all clean fclean re
