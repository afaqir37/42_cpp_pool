CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

all: main

main: main.o replace.o
	$(CXX) $(CXXFLAGS) main.o replace.o -o main

clean:
	rm -rf main.o replace.o

fclean: clean
	rm -rf main

re: fclean all