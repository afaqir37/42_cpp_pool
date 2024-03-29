CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRC = main.cpp easyfind.cpp
OBJ = $(SRC:.cpp=.o) 
NAME = main

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

easyfind.o: easyfind.cpp easyfind.hpp
main.o: main.cpp easyfind.cpp easyfind.hpp

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all