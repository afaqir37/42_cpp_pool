CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRC = main.cpp Serializer.cpp
OBJ = $(SRC:.cpp=.o) 
NAME = main

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

Serializer.o: Serializer.cpp Serializer.hpp
main.o: main.cpp Serializer.hpp

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all