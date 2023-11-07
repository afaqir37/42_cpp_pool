CXX = c++
CXXFLAGS =  -Wall -Wextra -Werror -std=c++98 -fsanitize=address
SRC = main.cpp Harl.cpp
OBJ = $(SRC:.cpp=.o)
NAME = main

all: $(NAME)

$(NAME): $(OBJ) Harl.hpp
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all