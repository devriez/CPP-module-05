# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amoiseik <amoiseik@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/09 15:28:22 by amoiseik          #+#    #+#              #
#    Updated: 2026/01/13 14:09:39 by amoiseik         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= a.out
CXX		= c++
CXXFLAGS	= -Wall -Werror -Wextra -std=c++98

SRCS	=	main.cpp \
			AForm.cpp \
			Bureaucrat.cpp \
			Intern.cpp \
			PresidentialPardonForm.cpp \
			RobotomyRequestForm.cpp \
			ShrubberyCreationForm.cpp

OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME): $(OBJS)
		$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: re fclean clean all
