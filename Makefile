# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/17 22:26:18 by flo-dolc          #+#    #+#              #
#    Updated: 2024/02/05 02:07:37 by flo-dolc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	ft_itoa.c ft_printf.c hex_utils.c \
				numbers_utils.c pointer_utils.c strings_utils.c

OBJS		=	$(SRCS:.c=.o)

NAME		=	libftprintf.a

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror

RM			=	rm -f

all:		$(NAME)

.c.o:
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
			ar rc $(NAME) $(OBJS)
			ranlib $(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
