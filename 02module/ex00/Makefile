GPP 			= c++

GPPFLAGS 		= -Wall -Wextra -Werror -std=c++98

RM 			= rm -f

NAME 		= fixed

INCLUDE 	= -I ./

SRCS 		= main.cpp Fixed.cpp

OBJS		= $(SRCS:.cpp=.o)

%.o: %.cpp
		$(GPP) $(GPPFLAGS) -c $< -o $@

all:		$(NAME)

$(NAME): 	$(OBJS)
			$(GPP) $(GPPFLAGS) $(SRCS) $(INCLUDE) -c
			$(GPP) $(GPPFLAGS) $(OBJS) -o $(NAME) $(INCLUDE)

clean:
			$(RM) -r $(OBJS)

fclean : 	clean
			$(RM) $(NAME)

re:			fclean all
