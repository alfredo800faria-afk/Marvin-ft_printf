# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: srusso-b <srusso-b@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/29 07:16:25 by srusso            #+#    #+#              #
#    Updated: 2025/12/01 17:56:18 by srusso-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

 NAME	= libftprintf.a

 CC		= cc

 CFLAGS	= -Wall -Werror -Wextra

 SRC	= ft_printf.c ft_utils.c ft_putnbr_base.c \

 OBJ	= $(SRC:.c=.o)


 all: $(NAME)

 $(NAME): $(OBJ)
	 ar rcs $(NAME) $(OBJ)

 %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

 clean:
	rm -f $(OBJ)
	
 fclean:	clean
	rm -f $(NAME)
	
 re: fclean all

.PHONY: all clean fclean re 
