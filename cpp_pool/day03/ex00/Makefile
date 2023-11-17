CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRC = ClapTrap.cpp main.cpp
OBJ = $(SRC:.cpp=.o)
NAME = main

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

ClapTrap.o: ClapTrap.cpp ClapTrap.hpp
main.o: main.cpp ClapTrap.hpp

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all