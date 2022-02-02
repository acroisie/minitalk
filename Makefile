# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acroisie <acroisie@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/02 13:49:13 by acroisie          #+#    #+#              #
#    Updated: 2022/02/02 14:57:11 by acroisie         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

CC := gcc 

CC_FLAGS := -Werror -Wall -Wextra

NAME_SERVER := server

NAME_CLIENT := client

SRCS_CLIENT := client.c

SRCS_SERVER := server.c

OBJS_CLIENT := $(SRCS_CLIENT:.c=.o)

OBJS_SERVER := $(SRCS_SERVER:.c=.o)

all : libft $(NAME_SERVER) $(NAME_CLIENT)

objs/client/%.o:	srcs/%.c includes/minitalk.h
					@mkdir -p objs
					@mkdir -p objs/client
					$(CC) $(CC_FLAGS) -c $< -o $@

objs/server/%.o:	srcs/%.c includes/minitalk.h
					@mkdir -p objs
					@mkdir -p objs/server
					$(CC) $(CC_FLAGS) -c $< -o $@

$(NAME_CLIENT):		libft $(addprefix objs/client/, $(OBJS_CLIENT))
					@$(CC) -o $(NAME_CLIENT) $(addprefix objs/client/, $(OBJS_CLIENT)) srcs/libft/libft.a

$(NAME_SERVER):		libft $(addprefix objs/server/, $(OBJS_SERVER))
					@$(CC) -o $(NAME_SERVER) $(addprefix objs/server/, $(OBJS_SERVER)) srcs/libft/libft.a

libft :	
		$(MAKE) -C srcs/libft

clean :
		rm -rf objs
		make clean -C srcs/libft

fclean : clean
		 rm -f $(NAME_CLIENT) $(NAME_SERVER)
		 make fclean -C srcs/libft

re : fclean all

.PHONY : re clean fclean libft all