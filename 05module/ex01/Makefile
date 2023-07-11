CXX 			= c++

CXXFLAGS 		= -Wall -Wextra -Werror -std=c++98 #-g #-fsanitize=address

RM 			= rm -f

NAME 		= Forms

INCLUDE 	= -I ./

SRCS 		= Bureaucrat.cpp main.cpp Form.cpp

OBJS		= $(SRCS:.cpp=.o)

all:		$(NAME)

$(NAME): 	$(OBJS)
			$(CXX) $(CXXFLAGS) $(SRCS) $(INCLUDE) -c
			$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME) $(INCLUDE)

clean:
			$(RM) -r $(OBJS)

fclean : 	clean
			$(RM) $(NAME)

re:			fclean all