# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: srusso-b <srusso-b@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/29 07:16:25 by srusso            #+#    #+#              #
#    Updated: 2025/12/06 19:35:12 by srusso-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

 NAME	= libftprintf.a

 CC		= cc

 CFLAGS	= -Wall -Werror -Wextra

 SRC	= ft_printf ft_utils ft_putnbr_base

 RM		= rm -f


 all: $(NAME)

$(NAME): $(SRC:=.o)
	ar rcs $(NAME) $(SRC:=.o)

clean:
	$(RM) $(SRC:=.o)

fclean:	clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
