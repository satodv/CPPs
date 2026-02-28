NAME = materia

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp AMateria.cpp Ice.cpp Cure.cpp Character.cpp MateriaSource.cpp \
		UnequippedMateria.cpp

HDR = AMateria.hpp Ice.hpp Cure.hpp Character.hpp MateriaSource.hpp \
		UnequippedMateria.hpp Makefile
		
OBJS_DIR = obj/
OBJS = $(addprefix $(OBJS_DIR), $(SRC:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJS)
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