NAME = harl

SRC = main.cpp Harl.cpp
OBJ = $(SRC:.cpp=.o)

CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

INC = 	Harl.hpp \

all: $(NAME)

$(NAME): $(OBJ) $(INC)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp $(INC)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean