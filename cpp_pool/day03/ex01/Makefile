CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRC = ClapTrap.cpp main.cpp ScavTrap.cpp
OBJ = $(SRC:.cpp=.o)
NAME = main

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

ClapTrap.o: ClapTrap.cpp ClapTrap.hpp
ScavTrap.o: ScavTrap.cpp ScavTrap.hpp ClapTrap.hpp
main.o: main.cpp ClapTrap.hpp ScavTrap.hpp

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all