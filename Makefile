# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbartosi <jbartosi@student.42prague.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/15 13:56:55 by jbartosi          #+#    #+#              #
#    Updated: 2023/02/22 13:21:56 by jbartosi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server
SERVER_FILE = server.c
CLIENT = client
CLIENT_FILE = client.c
CFLAGS = -Wall -Wextra -Werror
PRINTF = ft_printf

all: lib $(SERVER) $(CLIENT)

lib:
	@make -C $(PRINTF)
	@echo "Finished making libraries :D"

$(SERVER):
	cc $(SERVER_FILE) $(CFLAGS) -L $(PRINTF) -o $(SERVER) -lftprintf

$(CLIENT):
	cc $(CLIENT_FILE) $(CFLAGS) -L $(PRINTF) -o $(CLIENT) -lftprintf

clean:
	@rm -f $(CLIENT) $(SERVER)
	@make clean -C $(PRINTF)

fclean: clean
	@rm -f $(CLIENT) $(SERVER)
	@make fclean -C $(PRINTF)

re:	fclean
	@make all

.PHONY: re, fclean, clean
