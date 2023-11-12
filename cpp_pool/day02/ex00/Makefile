CXX = c++
CXXFLAGS = -Wall -Wextra -Werror
SRC = Fixed.cpp main.cpp
OBJ = $(SRC:.cpp=.o)
Name = a.out

all: $(NAME)

$(NAME): $(OBJ) Fixed.hpp
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

all: fclean re