GPP 		= c++

GPPFLAGS 	= -Wall -Wextra -Werror -std=c++98

RM 			= rm -f

NAME 		= ex00

INCLUDE 	= -I inc/


SRCS		=	Bureaucrat.cpp main.cpp

OBJS		=	$(addprefix objs/,$(SRCS:.cpp=.o))

CPPFLAGS	=	c++ -Wall -Wextra -Werror -std=c++98 -g

RM			=	rm -f

NAME		=	interfaces

all:	$(NAME)

objs/%.o: srcs/%.cpp
	@mkdir -p objs
	$(CPPFLAGS) -c $< -o $@

$(NAME):	$(OBJS)
	$(CPPFLAGS) $(OBJS) -o $(NAME)

clean:
	@$(RM) $(OBJS)

fclean:	clean
	@$(RM) $(NAME)

re:	fclean all