CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRC =  AMateria.cpp Character.cpp Cure.cpp Ice.cpp MateriaSource.cpp \
	LinkedList.cpp Node.cpp main.cpp
OBJ = $(SRC:.cpp=.o)
NAME = main

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

AMateria.o: AMateria.cpp AMateria.hpp
Character.o: Character.cpp Character.hpp
Cure.o: Cure.cpp Cure.hpp
Ice.o: Ice.cpp Ice.hpp
MateriaSource.o: MateriaSource.cpp MateriaSource.hpp
LinkedList.o: LinkedList.cpp LinkedList.hpp
Node.o: Node.cpp Node.hpp
main.o: main.cpp AMateria.hpp Character.hpp Cure.hpp Ice.hpp MateriaSource.hpp Node.hpp LinkedList.hpp

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all