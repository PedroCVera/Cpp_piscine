# GPP 			= c++

# GPPFLAGS 		= -Wall -Wextra -Werror -std=c++98

# RM 			= rm -f

# NAME 		= ex03

# INCLUDE 	= -I inc/

# SRCS 		= srcs/AMateria.cpp srcs/Character.cpp srcs/Cure.cpp srcs/Ice.cpp \
# 				srcs/MateriaSource.cpp srcs/main.cpp

# OBJS		= $(SRCS:.cpp=.o)

# %.o: %.cpp
# 		$(GPP) $(GPPFLAGS) -c $< -o $@

# all:		$(NAME)

# $(NAME): 	$(OBJS)
# 			$(GPP) $(GPPFLAGS) $(SRCS) $(INCLUDE) -c
# 			$(GPP) $(GPPFLAGS) $(OBJS) -o $(NAME) $(INCLUDE)

# clean:
# 			$(RM) -r $(OBJS)

# fclean : 	clean
# 			$(RM) $(NAME)

# re:			fclean all
SRCS	=	AMateria.cpp Ice.cpp Cure.cpp \
			Character.cpp MateriaSource.cpp \
			main.cpp \

OBJS	=	$(addprefix objs/,$(SRCS:.cpp=.o))

CPPFLAGS	=	c++ -Wall -Wextra -Werror -std=c++98 -g

RM		=	rm -f

NAME	=	interfaces

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