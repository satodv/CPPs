NAME = manipulation
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp
OBJS_DIR = objs/
OBJS = $(addprefix $(OBJS_DIR), $(SRCS:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJS) Makefile
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

