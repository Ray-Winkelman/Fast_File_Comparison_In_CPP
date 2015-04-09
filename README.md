# Fast_File_Comparison_In_CPP
### Using A Hash Table of Auto-Balancing Binary Search Trees.

This program compares two files and outputs the words in file B that are not in file A. It requires a prime number to create a hash table with a number of elements equal to the prime number. When inserting a new string into the table, the following function is called to return the modulus of the sum of the strings characters ASCII values. 

```cpp
	int Hash(const char * in){

		int sum = 0;

		for (int i = 0; i < strlen(in); i++){
			sum += in[i];
		}

		return sum % primenum;
	}
```

	The value this produces will be the index of the hash tables internal array it will store the string. Hashing two completely different strings may produce the same value, so at each index of the array live an auto-balancing binary search tree. This data structure will add child nodes to the right or left of a root node according to a lexicographical comparison (lesser or greater ASCII data).

```cpp
	static void Insert(TreeNode *&node, char * key, bool newnode)
	{
		try
		{
			if (node == NULL) // If first node, or a new branch.
			{
				node = new TreeNode(key);
				newnode = true;
			}
			else if (key == node->key) // Repeated key. 
			{
				newnode = false;
			}
			else if (key < node->key) // Lexicographical comparison. Median ASCII code is 110 or 'n'
			{
				Insert(node->leftnode, key, newnode);

				if (newnode)
				{
					switch (node->balanced) // The parent node's balance (if node was inserted).
					{
					case -1:
						balancedLeftSide(node); // Left-left scenario. 
						newnode = false;
						break;

					case 0:
						node->balanced = -1;
						break;

					case 1:
						node->balanced = 0;
						newnode = false;
						break;
					}
				}
			}
			else // Same logic as above but for the keys with values greater than their parent node. (Right side)
			{
				Insert(node->rightnode, key, newnode);

				if (newnode)
				{
					switch (node->balanced)
					{
					case -1:
						node->balanced = 0;
						newnode = false;
						break;

					case 0:
						node->balanced = 1;
						break;

					case 1:
						balancedRightSide(node);
						newnode = false;
						break;
					}
				}
			}
		}
		catch (...)
		{
		}
	}
```

	Try it for yourself. The combination of these data structures is very, very fast! Much better than traditional linear searches!
	
	Send a pull request if you have any ideas for improvement. 
