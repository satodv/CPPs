NAME = animal

NAME = animal

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp Animal.cpp Dog.cpp Cat.cpp WrongAnimal.cpp WrongCat.cpp

HDR = Animal.hpp Dog.hpp Cat.hpp WrongAnimal.hpp WrongCat.hpp Makefile

OBJS_DIR = obj/
OBJS = $(addprefix $(OBJS_DIR), $(SRC:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJS) Makefile
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(OBJS_DIR)%.o: %.cpp $(HDR)
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean