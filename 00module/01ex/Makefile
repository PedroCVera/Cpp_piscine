G++ 		= g++

FLAGS 		= -Wall -Wextra -Werror -std=c++98

RM 			= rm -f

NAME 		= phonebook

INCLUDE 	= -I ./

SRCS 		= main.cpp PhoneBook.cpp Contact.cpp 

OBJS		= $(SRCS:.cpp=.o)

all:		$(NAME)

$(NAME): 	$(OBJS)
			$(G++) $(FLAGS) $(SRCS) $(INCLUDE) -c
			$(G++) $(FLAGS) $(OBJS) -o $(NAME) $(INCLUDE)

clean:
			$(RM) -r $(OBJS)

fclean : 	clean
			$(RM) $(NAME)

re:			fclean all

.PHONY: all clean flcean re
