# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: akasiota <akasiota@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2026/05/21 14:52:57 by akasiota      #+#    #+#                  #
#    Updated: 2026/05/21 14:55:15 by akasiota      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME := libasm.a

SRCFILES :=

all: $(NAME)

$(NAME):

clean:

fclean:

re: fclean all

.PHONY: all clean fclean re