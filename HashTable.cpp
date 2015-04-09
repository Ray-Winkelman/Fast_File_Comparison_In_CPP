#include <string.h>
#include "BinarySearchTree.cpp"
using namespace std;

class HashTable {

private:
	int primenum;
	Tree * table;

	/* Private internal function for producing indexes */
	int Hash(const char * in){

		int sum = 0;

		for (int i = 0; i < strlen(in); i++){
			sum += in[i];
		}

		return sum % primenum;
	}

public:

	/* Constructor */
	HashTable(int primenum):primenum(primenum){
		table = new Tree[primenum];
	}

	/* Insert a key into the binary search tree */
	void Insert(char * key){
		
		int index = Hash(key);
		table[index].Insert(key);
	}

	/* Check that the binary search tree at this index contains a key */
	bool Contains(char * key){

		int index = Hash(key);

		if (table[index].Contains(key)){
			return true;
		}
		return false;
	}
};