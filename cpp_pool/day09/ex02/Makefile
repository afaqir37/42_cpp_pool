CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRC = main.cpp PmergeMe.cpp
OBJ = $(SRC:.cpp=.o) 
NAME = PmergeMe

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

PmergeMe.0: PmergeMe.cpp PmergeMe.hpp
main.o: main.cpp PmergeMe.hpp

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all