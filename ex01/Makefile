# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eviscont <eviscont@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/04 18:30:25 by eviscont          #+#    #+#              #
#    Updated: 2024/12/04 18:30:28 by eviscont         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RPN

CFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = main.cpp RPN.cpp
HDRS = RPN.hpp

all: $(NAME)

$(NAME): $(SRCS) $(HDRS)
	c++ $(CFLAGS) $(SRCS) -o $(NAME)

clean:

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re