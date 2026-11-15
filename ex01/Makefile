# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adeestev <adeestev@student.42urduliz.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/10/19 08:32:36 by adeestev          #+#    #+#              #
#    Updated: 2026/11/06 13:05:36 by adeestev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RPN

CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98

SRCS = main.cpp\
	RPN.cpp

OBJS = $(SRCS:.cpp=.o)

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "$(NAME) has been successfully compiled"

%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -o $@ -c $<

clean:
	@$(RM) $(OBJS)
	@echo "object files have been deleted"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(NAME) has been deleted"

re: fclean all

.PHONY: all clean fclean re
