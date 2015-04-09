#include <string.h> 
/*
This class stores character arrays in
an auto-balancing binary search tree.

© 2015 Ray Winkelman
*/

/* A struct for the tree's nodes. */
struct TreeNode
{
	char * key;
	int balanced;
	TreeNode * leftnode;
	TreeNode * rightnode;

	TreeNode(char * data)
	{
		key = data;
		balanced = 0;
		leftnode = NULL;
		rightnode = NULL;
	}
};

/* The Tree class. Most members are private. */
class Tree
{
	/*
	Public methods.

	These functions are called externally, and
	call there over-ridden private versions recursively
	to produce return values.

	*/
public:

	// Insert a node.
	void Insert(char * key){
		Insert(rootnode, key, false);
	}

	// Check for strings. 
	bool Contains(char * key){
		return Contains(rootnode, key, false);
	}


	/*
	Private members.

	These members are internal to the tree and hold the
	logic necessary to balance, and traverse the tree in an
	efficient way.

	*/
private:

	// The tree's root node.
	TreeNode * rootnode;

	// Insert.
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

	// Helper function to balance the right side.
	static void balancedRightSide(TreeNode *&node)
	{
		try
		{
			TreeNode *&right = node->rightnode;

			switch (right->balanced)
			{
			case 1:
				node->balanced = 0;
				right->balanced = 0;
				SwapRight(node);
				break;

			case -1:
				TreeNode *subleft = right->leftnode;

				switch (subleft->balanced)
				{
				case 0:
					node->balanced = 0;
					right->balanced = 0;
					break;

				case -1:
					node->balanced = 0;
					right->balanced = 1;
					break;

				case 1:
					node->balanced = -1;
					right->balanced = 0;
					break;
				}

				subleft->balanced = 0;
				SwapLeft(right);
				SwapRight(node);
				break;
			}
		}
		catch (...)
		{
		}
	}

	// Helper function to balance the left side.
	static void balancedLeftSide(TreeNode *&node)
	{
		try
		{
			TreeNode *&left = node->leftnode;

			switch (left->balanced)
			{
			case -1:
				node->balanced = 0;
				left->balanced = 0;
				SwapLeft(node);
				break;

			case 1:
				TreeNode *subright = left->rightnode;

				switch (subright->balanced)
				{
				case 0:
					node->balanced = 0;
					left->balanced = 0;
					break;
				case -1:
					node->balanced = 0;
					left->balanced = 1;
					break;
				case 1:
					node->balanced = -1;
					left->balanced = 0;
					break;
				}

				subright->balanced = 0;
				SwapRight(left);
				SwapLeft(node);
				break;
			}
		}
		catch (...)
		{
		}
	}

	// Helper function to swap places with a right child node.
	static void SwapRight(TreeNode *&node)
	{
		try
		{
			TreeNode *right = node->rightnode;
			node->rightnode = right->leftnode;
			right->leftnode = node;
			node = right;
		}
		catch (...)
		{
		}
	}

	// Helper function to swap places with a left child node.
	static void SwapLeft(TreeNode *&node)
	{
		try
		{
			TreeNode *left = node->leftnode;
			node->leftnode = left->rightnode;
			left->rightnode = node;
			node = left;
		}
		catch (...)
		{
		}
	}

	// Check to see if the tree contains a string.
	static bool Contains(TreeNode *&node, char * key, bool found)
	{
		try
		{
			if (found)
			{
				return found;
			}
			else if (node == NULL)
			{
				return false;
			}
			else if (strcmp(key, node->key) == 0)
			{
				found = true;
				return found;
			}
			else if (strcmp(key, node->key) < 0)
			{
				return Contains(node->leftnode, key, found);
			}
			else
			{
				return Contains(node->rightnode, key, found);
			}
		}
		catch (...)
		{
		}
	}
};