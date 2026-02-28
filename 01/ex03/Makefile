NAME = violence
CC = c++
FLAGS = -Werror -Wextra -Wall -std=c++98

SRCS = 	main.cpp \
		HumanA.cpp \
		HumanB.cpp \
		Weapon.cpp \

OBJS_DIR = objs/
OBJS = $(addprefix $(OBJS_DIR), $(SRCS:.cpp=.o))

INC = 	HumanA.hpp \
		HumanB.hpp \
		Weapon.hpp \

all: $(NAME)

$(NAME): $(OBJS) Makefile $(INC)
	$(CC) $(OBJS) -o $(NAME)

$(OBJS_DIR)%.o: %.cpp
	mkdir -p $(OBJS_DIR)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean

