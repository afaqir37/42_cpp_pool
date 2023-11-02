CC = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = phonebook
SRC = PhoneBook.cpp contact_func.cpp
HDR = PhoneBook.hpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ) 
	$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)


clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re : fclean all