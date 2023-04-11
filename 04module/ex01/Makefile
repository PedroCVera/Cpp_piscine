CPP 			= c++

GPPFLAGS 		= -Wall -Wextra -Werror -std=c++98

RM 			= rm -f

NAME 		= ex01

INCLUDE 	= -I ./

SRCS 		= Brain.cpp Dog.cpp Cat.cpp Animal.cpp main.cpp

OBJS		= $(SRCS:.cpp=.o)

%.o: %.cpp
		$(GPP) $(GPPFLAGS) -c $< -o $@

all:		$(NAME)

$(NAME): 	$(OBJS)
			$(CPP) $(GPPFLAGS) $(SRCS) $(INCLUDE) -c
			$(CPP) $(GPPFLAGS) $(OBJS) -o $(NAME) $(INCLUDE)

clean:
			$(RM) -r $(OBJS)

fclean : 	clean
			$(RM) $(NAME)

re:			fclean all
