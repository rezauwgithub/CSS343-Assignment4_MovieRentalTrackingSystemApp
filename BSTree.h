//80 Character Limit
//********//********//********//********//********//********//********//********

//----------------------------BSTree-----------------------------
//A BSTree is a data structure that stores item in sorted order.
//It does this by using overloaded operators (such as < and >).
//Therefore, any object needs to overload those operators in 
//order to be stored in the BSTree. BSTrees are good for fast
//insert, remove, and retrieval (on average). With the added
//benefit of storing items in order, it will help with sorting
//the movies.
//---------------------------------------------------------------
//By: Reza Naeemi
//Created: 11/05/2016
//Last Edited: 11/26/2016
//---------------------------------------------------------------
//Note: The .h and .cpp were sub-optimally combined into the same
//file due to the fact that this class is templatized. Please see
//comment below on C++ templates.
//---------------------------------------------------------------

#ifndef BSTREE_H
#define BSTREE_H
#include <iostream>
#include <vector>
template<class ItemType>
class BSTree
{
public:
	//----------------------------BSTree-----------------------------
	//Default constructor sets the root of the BSTree to NULL.
	//---------------------------------------------------------------
	BSTree()
	{
		root = NULL;
	}
	
	//----------------------------BSTree-----------------------------
	//Copy constructor sets the root to NULL and uses assignment 
	//operator to copy the source tree.
	//---------------------------------------------------------------
	BSTree(const BSTree& source)
	{
		root = NULL;
		*this = source;
	}
	
	//----------------------------~BSTree----------------------------
	//Calls the clear method to delete all dynamically allocated 
	//memory.
	//---------------------------------------------------------------
	~BSTree()
	{
		clear();
	}

	//----------------------------isEmpty-----------------------------
	//Returns true if the tree is empty, false otherwise.
	//---------------------------------------------------------------
	bool isEmpty() const
	{
		return (root == NULL);
	}

	//----------------------------Insert-----------------------------
	//Calls a private recursive insert function to insert data into
	//the BSTree. Returns true if the insert worked, false otherwise.
	//---------------------------------------------------------------
	bool insert(ItemType* data)
	{
		return insert(data, root);
	}
	
	//----------------------------remove-----------------------------
	//Calls a private recursive remove function to remove toFind 
	//from the tree and sets result to a copy of the data. True is
	//returned if the remove is successful, false otherwise.
	//---------------------------------------------------------------
	bool remove(const ItemType& toFind, ItemType& result)
	{
		return remove(toFind, result, root);
	}
	
	//----------------------------retrieve---------------------------
	//Calls a recursive private helper function to retrieve an item
	//in the tree. True is returned if the item was found and result
	//is pointed to the item in the tree, and false is returned
	//otherwise.
	//---------------------------------------------------------------
	bool retrieve(const ItemType& toFind, ItemType*& result) const
	{
		return retrieve(toFind, result, root);
	}

	//----------------------------operator==-------------------------
	//Compares two trees for structural and value equality. This is
	//done using a recursive private helper compare function.
	//---------------------------------------------------------------
	bool operator==(const BSTree<ItemType>& other) const
	{
		/*
		Checks to see if the two trees are the same trees.
		If so, true is returned.
		*/
		if (this == &other)
		{
			return true;
		}

		return compare(root, other.root);
	}
	
	//----------------------------operator!=--------------------------
	//Compares two trees for inequality by negating the result of the
	//equality operator.
	//---------------------------------------------------------------
	bool operator!=(const BSTree<ItemType>& other) const
	{
		return !(*this == other);
	}

	//----------------------------operator=--------------------------
	//Uses a private recursive helper function to copy one tree's
	//data into the other. At the end, both trees have the same
	//structure and values.
	//---------------------------------------------------------------
	BSTree<ItemType>& operator=(const BSTree<ItemType>& source)
	{
		/*
		Checks to make sure the two trees are not the same.
		*/
		if (this != &source)
		{
			//deletes the calling tree
			clear();

			/*
			Checks to see if the source tree is empty. If so, 
			a reference to the current tree is returned.
			*/
			if (source.isEmpty())
			{
				return *this;
			}

			//calls the private helper function to start
			//copying at the roots.
			copy(root, source.root);
		}

		return *this;
	}

	//----------------------------clear------------------------------
	//Calls a private function to delete all dynamically allocated
	//memory. root is then set to NULL.
	//---------------------------------------------------------------
	void clear()
	{
		clear(root);
		root = NULL;
	}

	//----------------------------dfs--------------------------------
	//Performs a depth first search on the tree. The assignment 
	//specifies that we will need to find movies that are similar
	//(such as the same classical movie with different actors),
	//therefore, this method performs a dfs on the tree and places
	//all matches into the result vector. A private helper function
	//is used for this. True is returned if something was found, 
	//false is returned otherwise.
	//---------------------------------------------------------------
	bool dfs(const ItemType& toFind, std::vector<ItemType*>& results) const
	{
		dfs(toFind, results, root);
		return results.size() > 0;
	}

	//----------------------------display-----------------------------
	//This method provides a way to display a tree to a stream
	//(without the output operator). This method simply calls the
	//private helper function to display the tree.
	//----------------------------------------------------------------
	void display(std::ostream& outStream)
	{
		inorderDisplay(outStream, root);
	}

private:
	//Defines a Node as a struct that holds a pointer
	//to the data, a pointer to the left subtree, and
	//a pointer to the right subtree.
	struct Node
	{
		ItemType* data;
		Node* left;
		Node* right;
	};

	//the beginning of the tree
	Node* root;

	//----------------------------clear-------------------------------
	//Recursive method performs a post order traversal of the tree
	//deleting all data items and nodes in order to clear up all
	//dynamically allocated memory.
	//----------------------------------------------------------------
	void clear(Node*& subtree)
	{
		if (subtree != NULL)
		{
			clear(subtree->left);
			clear(subtree->right);
			delete subtree->data;
			subtree->data = NULL;
			delete subtree;
			subtree = NULL;
		}
	}

	//----------------------------retrieve-----------------------------
	//Private method that searches the entire tree looking for toFind.
	//This method uses a Binary search to find the data, if nothing
	//is found, false is returned. If it is found, true is returned
	//and result is set to point to the data.
	//-----------------------------------------------------------------
	bool retrieve(const ItemType& toFind, ItemType*& result,
											 Node* subtree) const
	{
		/*
		Checks to see if the node is NULL. If so, false is returned.
		If no, a check is done to see if toFind is less than subtree's
		data, greater than subtree's data or equal to subtree's data. If it
		is less than, the same function is called to look at the left subtree.
		If is is greater than, the same function is called to look at the right
		subtree. If it is equal to, result is set and true is returned.
		*/
		if (subtree == NULL)
		{
			return false;
		}
		else if (toFind < *subtree->data)
		{
			return retrieve(toFind, result, subtree->left);
		}
		else if (toFind > *subtree->data)
		{
			return retrieve(toFind, result, subtree->right);
		}
		else
		{
			result = subtree->data;
			return true;
		}
	}

	//----------------------------insert------------------------------
	//Recursively works its way down the tree until a leaf node is 
	//found. The data item is then inserted in the tree at the leaf
	//node in order. True is returned. This method allows duplicates
	//in the tree and duplicates go to the right.
	//-----------------------------------------------------------------
	bool insert(ItemType* data, Node*& subtree)
	{
		/*
		Checks to see if subtree is NULL. If so, data is inserted.
		Otherwise, data is compared with subtree's data to see
		if data needs to be inserted to the left (less than) or
		the right (greater than). The method is then called again.
		*/
		if (subtree == NULL)
		{
			subtree = new Node;
			subtree->left = NULL;
			subtree->right = NULL;
			subtree->data = data;
			return true;
		}
		else if (*data < *subtree->data)
		{
			return insert(data, subtree->left);
		}
		else
		{
			return insert(data, subtree->right);
		}
	}

	//----------------------------compare-----------------------------
	//Recursively compares two trees for structural equality and
	//quality with values.
	//-----------------------------------------------------------------
	bool compare(Node* subtree, Node* otherSubtree) const
	{
		/*
		Checks to see if both subtree are NULL if so,
		true is returned. If only one is NULL, they
		are not equal, so false is returned. If none
		are NULL, the values at the node are 
		compared for inequality. If they are not equal,
		false is returned. Otherwise, the current nodes
		are equal, so the left and right subtrees are 
		compared.
		*/
		if (subtree == NULL && otherSubtree == NULL)
		{
			return true;
		}
		else if (subtree == NULL || otherSubtree == NULL)
		{
			return false;
		}
		else if (*subtree->data != *otherSubtree->data)
		{
			return false;
		}
		else
		{
			//return the result of both the left and right subtrees
			//being equal
			return compare(subtree->left, otherSubtree->left) &&
				   compare(subtree->right, otherSubtree->right);
		}
	}

	//----------------------------copy---------------------------------
	//Copies one node's data into a new node. This is done recursively
	//to build an entire tree.
	//-----------------------------------------------------------------
	void copy(Node*& subtree, Node* toCopy)
	{
		/*
		If toCopy is NULL, subtree needs to be set to NULL.
		Otherwise, a new node is created and all values from
		toCopy are copied to subtree.
		*/
		if (toCopy == NULL)
		{
			subtree = NULL;
		}
		else
		{
			//creates a new Node
			subtree = new Node;
			subtree->left = NULL;
			subtree->right = NULL;
			ItemType* newItemType = new ItemType;
			//copies toCopy's data
			*newItemType = *toCopy->data;
			subtree->data = newItemType;

			//copies the left subtree
			copy(subtree->left, toCopy->left);
			//copies the right subtree
			copy(subtree->right, toCopy->right);
		}
	}

	//----------------------------inorderDisplay-----------------------
	//Uses an in-order traversal to print all of the tree's data to 
	//a stream. This is done recursively.
	//-----------------------------------------------------------------
	void inorderDisplay(std::ostream& outStream, Node* subtree) const
	{
		/*
		Checks to make sure subtree is not NULL before display the
		left subtree, the current data, and the right subtree.
		*/
		if (subtree != NULL)
		{
			inorderDisplay(outStream, subtree->left);
			outStream << *subtree->data << std::endl;
			inorderDisplay(outStream, subtree->right);
		}
	}

	//----------------------------remove-------------------------------
	//Recursively searches for toFind to delete from the tree.
	//If found, the data is removed from the tree and result is set to
	//a copy of the data and true is returned. Otherwise, false is 
	//returned.
	//-----------------------------------------------------------------
	bool remove(const ItemType& toFind, ItemType& result, Node*& subtree)
	{
		/*
		If subtree is NULL, toFind was never found so false is returned.
		Otherwise, if toFind is less than subtree's data, the method is
		called again but uses the left subtree. Likewise, if toFind is 
		larger than subtree's data, the method is called again with the
		right subtree. The fourth case is that the data was found. If
		this happens, the data is removed and true is returned.
		*/
		if (subtree == NULL)
		{
			return false;
		}
		else if (toFind < *subtree->data)
		{
			return remove(toFind, result, subtree->left);
		}
		else if (toFind > *subtree->data)
		{
			return remove(toFind, result, subtree->right);
		}
		else
		{
			//set result to a copy of the data
			result = *subtree->data;
			Node* toDelete = subtree;
			//delete the data from the tree
			delete toDelete->data;
			toDelete->data = NULL;
			
			//Now that the data is deleted, the tree needs to
			//be restructured.

			/*
			Checks to see how many children the node to delete
			has. If none, the node is deleted and set to NULL.
			If it has one, the node is deleted and then pointed
			to the child so the tree doesn't lose the information
			contained in the child node. If it has two, the largest
			value from the left subtree is deleted from the left
			subtree and moved to the current node to keep the 
			BSTree ordering.
			*/
			if (subtree->left == NULL && subtree->right == NULL)
			{//no children
				delete toDelete;
				toDelete = NULL;
				subtree = NULL;
			}
			else if (subtree->left == NULL)
			{//right child
				subtree = subtree->right;
				delete toDelete;
				toDelete = NULL;
			}
			else if (subtree->right == NULL)
			{//left child
				subtree = subtree->left;
				delete toDelete;
				toDelete = NULL;
			}
			else
			{//two children
				//uses a helper function to remove the largest
				//from the left subtree. The data is then 
				//returned and set as the data of the current
				//node.
				subtree->data = deleteMax(subtree->left);
			}

			return true;
		}
	} //end remove

	//----------------------------deleteMax----------------------------
	//The max value is always at the right most node. Therefore, this
	//method recursively goes as far to the right as it can and deletes
	//the node. The data of the node is then returned.
	//-----------------------------------------------------------------
	ItemType* deleteMax(Node*& subtree)
	{
		/*
		Checks to see if there are more nodes to the right.
		If not, the node must be deleted as it is the largest.
		*/
		if (subtree->right == NULL)
		{
			//stores the data to return
			ItemType* retval = subtree->data;
			Node* toDelete = subtree;
			/*
			Points subtree to the left subtree. This is
			actually an important line. At this point it
			is known that there is nothing in the right
			subtree, but nothing about the left subtree
			is known. Therefore, it could contain data.
			So, even though I need to delete the current
			node I still need to keep the left subtree
			so I don't lose information.
			*/
			subtree = subtree->left;
			//deletes the current node.
			delete toDelete;
			toDelete = NULL;
			//returns the data
			return retval;
		}
		//continues traveling to the right
		return deleteMax(subtree->right);
	}

	//----------------------------dfs----------------------------------
	//Recursively searches the entire tree placing any data that
	//matches toFind into the vector that is passed in by reference.
	//-----------------------------------------------------------------
	void dfs(const ItemType& toFind, std::vector<ItemType*>& results,
														Node* subtree) const
	{
		/*
		Checks to make sure subtree is not NULL.
		*/
		if (subtree != NULL)
		{
			/*
			Checks to see if subtree's data matches
			toFind. If it does, the data pointer is placed
			in the vector.
			*/
			if (toFind == *subtree->data)
			{
				results.push_back(subtree->data);
			}
	
			//searched the left subtree
			dfs(toFind, results, subtree->left);
			//searches the right subtree
			dfs(toFind, results, subtree->right);
		}
	}
};

#endif

//C++ Templates:
/*
"From the point of view of the compiler, templates are
not normal functions or classes. They are compiled on
demand, meaning that the code of a template function
is not compiled until an instantiation with specific
template arguments is required. At that moment, when
an instantiation is required, the compiler generates a
function specifically for those arguments from the template.

When projects grow it is usual to split the code of a 
program in different source code files. In these cases,
the interface and implementation are generally separated.
Taking a library of functions as example, the interface 
generally consists of declarations of the prototypes of 
all the functions that can be called. These are generally 
declared in a "header file" with a .h extension, and the 
implementation (the definition of these functions) is in 
an independent file with c++ code.

Because templates are compiled when required, this forces
a restriction for multi-file projects: the implementation 
(definition) of a template class or function must be in the 
same file as its declaration. That means that we cannot 
separate the interface in a separate header file, and that 
we must include both interface and implementation in any 
file that uses the templates.

Since no code is generated until a template is instantiated 
when required, compilers are prepared to allow the inclusion 
more than once of the same template file with both declarations 
and definitions in a project without generating linkage errors."

From: http://www.cplusplus.com/forum/unices/41824/
*/
