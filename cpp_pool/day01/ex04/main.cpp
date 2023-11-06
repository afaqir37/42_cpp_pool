#include "replace.hpp"

int main(int argc, const char **argv)
{
	if (argc != 4)
	{
		std::cout << "Usage: <./program \"filename\" \"string_s1\" \"string_s2\"\n";
		return (1);
	}

	std::ifstream file(argv[1]);

	if (!file) {
		std::cerr << "Unable to open file\n";
		return (1);
	}

	return (replaceClone(file, argv));
}