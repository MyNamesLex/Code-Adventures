#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;
void SelectWhich();
void LinkedListFunc();
void StackFunc();
void QueueFunc();
void BinaryTreeFunc();
void VectorFunc();

template <typename T>

class LinkedList
{

private:
	struct Node
	{
		T data;
		Node* next;

		Node(const T& data)
		{
			this->data = data;
			this->next = nullptr;
		}
	};

	Node* head;
	size_t size;

public:
	LinkedList()
	{
		this->head = nullptr;
		this->size = 0;
	}

	~LinkedList() // when destroyed, deallocate memory
	{
		Clear();
	}

	void Clear()
	{
		while (Empty() == false) // if linkedlist is not empty, recursively call popfront to empty the linkedlist
		{
			PopFront();
		}
	}

	bool Empty() const
	{
		if (size == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	size_t GetSize() const
	{
		return size;
	}

	const T& Front() const
	{
		if (Empty() == true)
		{
			std::cout << "List is empty.\n";
			return NULL;
		}

		return head->data;
	}

	void PushFront(const T& data)
	{
		Node* NewNode = new Node(data); //make new node with data parameter

		NewNode->next = head; // set NewNode next pointer to point to current head

		head = NewNode; // update head pointer to point to the new node

		size = size + 1; //update size of the linkedlist
	}

	void PopFront()
	{
		if (Empty() == true)
		{
			std::cout << "List is empty. Can't pop!\n";
			return;
		}

		Node* temp = head;
		head = head->next; // move head pointer to the next node in the list, aka nothing so it is null
		delete temp;
		size = size - 1; // update size of linkedlist
	}

	int GetElement(int Index)
	{
		if (Index >= size)
		{
			cout << "GetElement, Index is greater then size, returning...";
			return NULL;
		}

		Node* current = head;
		int CurrentIndex = 0;

		while (current != nullptr) // loop through linkedlist, if CurrentIndex equal Index given in parameter, return the current nodes data
		{
			if (CurrentIndex == Index)
			{
				return current->data;
			}

			current = current->next;
			CurrentIndex++;
		}

		// if code reaches here, the index is out of bounds
		cout << "Index out of bounds failsafe triggered\n";
	}

	void PrintList()
	{
		Node* current = head;
		int CurrentIndex = 0;

		while (current != nullptr) // loop through linkedlist while current node isn't null and print out current nodes data
		{
			cout << "Element at index " << CurrentIndex << ": " << current->data << endl;
			CurrentIndex++;
			current = current->next;
		}

		return;
	}
};

class BinaryTree
{
private:
	struct Node
	{
		int data;
		Node* right;
		Node* left;

		Node(int value)
		{
			data = value;
			left = nullptr;
			right = nullptr;
		}
	};

	// go through the tree, navigating the tree by getting the current node passed in
	// and navigating through until the current node is null and then making a node there

	void InsertRecursive(Node* current, int value)
	{
		if (value < current->data)
		{
			if (current->left == nullptr)
			{
				current->left = new Node(value);
			}
			else
			{
				InsertRecursive(current->left, value);
			}
		}
		else if (value > current->data)
		{
			if (current->right == nullptr)
			{
				current->right = new Node(value);
			}
			else
			{
				InsertRecursive(current->right, value);
			}
		}
	}

public:

	Node* root;

	BinaryTree(int rootvalue)
	{
		root = new Node(rootvalue);
	}

	void Insert(int value)
	{
		InsertRecursive(root, value);
	}

	// recursively call search by navigating the tree through the value variable and comparing the current node data
	// until current data is equal to the value, aka found what we are looking for

	bool Search(Node* current, int value)
	{
		if (current == nullptr)
		{
			return false;
		}

		if (value == current->data)
		{
			return true;
		}

		if (value < current->data)
		{
			return Search(current->left, value);
		}
		else
		{
			return Search(current->right, value);
		}
	}

	Node* FindSmallestValue(Node* node) // find the left most node = smallest node
	{
		while (node->left != nullptr)
		{
			node = node->left;
		}
		return node;
	}

	Node* FindLargestValue(Node* node) // find the right most node = largest node
	{
		while (node->right != nullptr)
		{
			node = node->right;
		}
		return node;
	}

	Node* RemoveElement(Node* root, int value)
	{
		if (root == nullptr) // if root is nullptr, tree is empty, nothing to remove
		{
			cout << "Root Is Null, Tree Is Empty" << endl;
			return root;
		}

		// find the node where value is and recursively remove the value from the appropriate subtree

		if (value < root->data)
		{
			root->left = RemoveElement(root->left, value);
		}
		else if (value > root->data)
		{
			root->right = RemoveElement(root->right, value);
		}
		else // node with the value is found
		{
			if (root->left == nullptr) // no left child, replace current node with the right, delete the root and return temp, this replaces the current node with it's right child
			{
				Node* temp = root->right;
				delete root;
				return temp;
			}
			else if (root->right == nullptr) // no right child, replace current node with the left, delete the root and return temp, this replaces the current node with it's left child
			{
				Node* temp = root->left;
				delete root;
				return temp;
			}

			// if the node has both left and right children, replace it with the smallest value in its right subtree
			// right subtree because it is greater then all on the left subtree, ensuring order

			Node* temp = FindSmallestValue(root->right);
			root->data = temp->data; // copy the data of the smallest node to the current node
			root->right = RemoveElement(root->right, temp->data); // remove the smallest node from its original position
		}
		return root; // return modified root to ensure changes made are changed up the tree
	}

	void SearchAllNodes(Node* root) // in order traversal
	{
		if (root == nullptr)
		{
			//cout << "Root is nullptr, returning" << endl;
			return;
		}

		SearchAllNodes(root->left);
		cout << root->data << endl;
		SearchAllNodes(root->right);
	}
};