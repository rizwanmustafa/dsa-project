#pragma once
#ifndef BST
#define BST_Hpp

template <typename T>
class BST
{
	class BSTNode
	{
	public:
		T data;
		BSTNode* left;
		BSTNode* right;
		BSTNode(T data)
		{
			this->data = data;
			this->left = nullptr;
			this->right = nullptr;
		}
	};
	BSTNode* root;
public:
	BST()
	{
		this->root = nullptr;
	}

	BST(const BST& other)
	{
		this->root = copy(other.root);
	}

	void insert(T data)
	{
		this->root = insert(this->root, data);
	}

	void deleteData(T data)
	{
		this->root = deleteData(this->root, data);
	}
	
	bool search(T data)
	{
		return search(this->root, data);
	}

	~BST()
	{
		clear(this->root);
	}

private:
	BSTNode* copy(BSTNode* other)
	{
		if (other == nullptr)
		{
			return nullptr;
		}

		BSTNode* newNode = new BSTNode(other->data);
		newNode->lest = copy(other->left);
		newNoe->right = copy(other->right);
		return newNode;
	}

	BSTNode* insert(BSTNode* nodeptr, T data)
	{
		if (nodeptr == nullptr)
		{
			return new BSTNode(data);
		}

		if (data < nodeptr->data)
		{
			nodeptr->left = insert(nodeptr->left, data);
		}
		else if(data > nodeptr->data)
		{
			nodeptr->right = insert(nodeptr->right, data);
		}
		else
		{
			// DoNothing: Duplicate Value
			return nodeptr;
		}
	}

	BSTNode* deleteValue(BSTNode* nodeptr, T data)
	{
		if (nodeptr == nullptr)
		{
			return nullptr;
		}
		if (data < nodeptr->data)
		{
			nodeptr->left = deleteValue(nodeptr->left, data);
		}
		else if (data > nodeptr->data)
		{
			nodeptr->right = deleteValue(nodeptr->right, data);
		}
		else
		{
			if (nodeptr->left == nullptr && nodeptr->right == nullptr)
			{
				delete nodeptr;
				return nullptr;
			}
			else if (nodeptr->left == nullptr)
			{
				BSTNode* temp = nodeptr->right;
				delete nodeptr;
				return temp;
			}
			else if (nodeptr->right == nullptr)
			{
				BSTNode* temp = nodeptr->left;
				delete nodeptr;
				return temp;
			}
			else
			{
				BSTNode* minNode = nodeptr->right;
				while (minNode->left != nullptr)
				{
					minNode = minNode->left;
				}
				nodeptr->data = minNode->data;
				nodeptr->right = deleteValue(nodeptr->right, minNode->data);
			}
		}
	}
	
	bool search(BSTNode* nodeptr, T data)
	{
		if (nodeptr == nullptr)
		{
			return false;
		}

		if (nodeptr->data == data)
		{
			return true;
		}

		if (data < nodeptr->data)
		{
			return search(nodeptr->left, data);
		}
		else
		{
			return search(nodeptr->right, data);
		}
	}

	void clear(BSTNode* nodeptr)
	{
		if (nodeptr == nullptr)
		{
			return;
		}

		clear(nodeptr->left);
		clear(nodeptr->right);
		delete nodeptr;
	}
};


#endif // BST_HPP