CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = phonebook
SRC = PhoneBook.cpp contact_func.cpp utils.cpp
HDR = PhoneBook.hpp Contact.hpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ) $(HDR)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)


clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re : fclean all

# argc plus 1 should not be acceptable DONE
# when inset enter when asking for index it shows the contact DONE 
# You should check the input when asking for index 006 is not a valid input 
# solution :
#  - check for the size() it should be one character
#  - if yes ; check that the one character is around 0 and the lenght of your string ex:: input >= 0 && input <= lenght DONE