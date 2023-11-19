CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRC = Animal.cpp Cat.cpp Dog.cpp main.cpp
OBJ = $(SRC:.cpp=.o)
NAME = main

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

Animal.o: Animal.cpp Animal.hpp
Cat.o: Cat.cpp Cat.hpp
Dog.o: Dog.cpp Dog.hpp
main.o: main.cpp Animal.hpp Cat.hpp Dog.hpp

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all