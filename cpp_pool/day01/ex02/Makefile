CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

all: main

main: main.o
	$(CXX) $(CXXFLAGS) main.o -o main

clean:
	rm -rf main.o

fclean: clean
	rm -rf main

re: fclean all
	