CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRC = Fixed.cpp main.cpp
OBJ = $(SRC:.cpp=.o)
NAME = main

all: $(NAME)

$(NAME): $(OBJ) Fixed.hpp
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all