#include <stdio.h>
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

void nullTerminatingString(string &str)
{
	str[2] = '\0'; // the specific character is replaced with null character, but 
					//the string size is not changed, so like the specific character is deleted.
}

void nullTerminatingChar(char *str)
{
	str[2] = '\0'; // the specific character is replaced with null character, 
					//from this character, when you want to print the string, it will stop.
}

int main()
{
	string str1 = "hala madrid";
	printf("string: %s\n", str1.c_str());
	printf("strlen: %lu\n", strlen(str1.c_str()));
	printf("size: %lu\n", str1.size());
	nullTerminatingString(str1);
	cout << str1 << endl;
	cout <<str1.length() << endl;

	cout << endl << endl << endl;

	char str2[] = "hala madrid";
	printf("char[] = %s\n", str2);
	printf("strlen: %lu\n", strlen(str2));
	printf("sizeof: %lu\n", sizeof(str2));
	nullTerminatingChar(str2);
	printf("char[] = %s\n", str2);
	printf("strlen: %lu\n", strlen(str2));

	// the below while loop shows that the characters after the null character that we set
	// using nullTerminatingChar() are not deleted. They are still there, but when you want
	// to print the string, it will stop at the null character.

	// int i = 0;
	// while (i < 12)
	// {
	// 	printf("%c", str2[i]);
	// 	i++;
	// }

	return (0);
}