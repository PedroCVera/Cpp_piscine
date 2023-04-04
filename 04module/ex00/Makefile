GPP 			= c++

GPPFLAGS 		= -Wall -Wextra -Werror -std=c++98

RM 			= rm -f

NAME 		= polymorphism

INCLUDE 	= -I ./

SRCS 		= Dog.cpp Cat.cpp Animal.cpp WrongAnimal.cpp WrongCat.cpp main.cpp

OBJS		= $(SRCS:.cpp=.o)

all:		$(NAME)

$(NAME): 	$(OBJS)
			$(GPP) $(GPPFLAGS) $(SRCS) $(INCLUDE) -c
			$(GPP) $(GPPFLAGS) $(OBJS) -o $(NAME) $(INCLUDE)

clean:
			$(RM) -r $(OBJS)

fclean : 	clean
			$(RM) $(NAME)

re:			fclean all
