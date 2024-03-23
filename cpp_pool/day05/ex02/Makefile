CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRC = main.cpp Bureaucrat.cpp AForm.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp
OBJ = $(SRC:.cpp=.o) 
NAME = main

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

Bureaucrat.o: Bureaucrat.cpp Bureaucrat.hpp
AForm.o: AForm.cpp AForm.hpp
PresidentialPardonForm.o: PresidentialPardonForm.cpp PresidentialPardonForm.hpp
RobotomyRequestForm.o: RobotomyRequestForm.cpp RobotomyRequestForm.hpp
ShrubberyCreationForm.o: ShrubberyCreationForm.cpp ShrubberyCreationForm.hpp
main.o: main.cpp Bureaucrat.hpp

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all