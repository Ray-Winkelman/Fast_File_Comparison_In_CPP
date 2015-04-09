#include "Controller.cpp"

/* 
This program checks files for spelling errors using 
a hash table and binary search tree.

© 2015 Ray Winkelman
*/
#define PRIME_NUM 47
#define DICTIONARY "G:\\GoogleDrive\\GitHub\\PROG_2400_DATA_STRUCTURES\\Assignment_5\\dictionary.txt"
#define FILE "G:\\GoogleDrive\\GitHub\\PROG_2400_DATA_STRUCTURES\\Assignment_5\\mispelled.txt"

int main()
{
	Controller controller(PRIME_NUM, DICTIONARY, FILE);
	controller.Run();
}