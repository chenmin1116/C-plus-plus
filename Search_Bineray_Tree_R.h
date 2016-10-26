#pragma once
#include<iostream>
using namespace std;

template<typename T>
struct SearchBinerayTreeNode
{
	SearchBinerayTreeNode<T> *_left;
	SearchBinerayTreeNode<T> *_right;
	T  key;
	SearchBinerayTreeNode(const T&x)
		:_left(NULL)
		,_right(NULL)
		,key(x)
	{}
};

template<typename T>
class SearchBineryTree
{
	typedef SearchBinerayTreeNode<T> Node;
protected:
	Node *CreatTree(T*a,size_t size,size_t &index,const T& invalid)   
	{
		Node* root = NULL;
		if((a[index] != invalid)&&(index<size))
		{
			root = new Node(a[index]);
			root->_left = CreatTree(a,size,++index,invalid);
			root->_right = CreatTree(a,size,++index,invalid);
		}
		return root;
	}

	void _InOrder(Node *root)      //中序遍历实现
	{
		if(root == NULL)
			return;
		_InOrder(root->_left);
		cout<<root->key<<" ";
		_InOrder(root->_right);
	}

	bool _Insert(Node* &root,const T& key)
	{
		if(root == NULL)
		{
			root = new Node(key);
		}
		else
		{
			if(root->key < key)
				return _Insert(root->_right,key);
			else
			{
				if(root->key > key)
					return _Insert(root->_left,key);
				else
					return false;
			}
			return true;
		}
		return false;
	}

	bool _Find(Node* &root,const T&key)
	{
		if(root == NULL)
			return false;
		else
		{
			if(root->key < key)
			{
				return _Find(root->_right,key);
			}
			else
			{
				if(root->key >key)
				{
					return _Find(root->_left,key);
				}
				else
				{
					return true;
				}
			}
		}
		return false;
	}


public:
	SearchBineryTree()
		:_root(NULL)
	{}

	SearchBineryTree(T *a,size_t size,const T& invalid)
	{
		size_t index = 0;
		_root = CreatTree(a,size,index,invalid);
	}

void InOrder();
bool Insert(const T&key);
bool Find(const T&key);
bool Remove(const T&key);
public:
	Node *_root;
};

template<typename T>
void SearchBineryTree<T>:: InOrder()
{
	_InOrder(_root);
	cout<<endl;
}

template<typename T>
bool SearchBineryTree<T>:: Insert(const T&key)
{
	return _Insert(_root,key);
}
template<typename T>
bool SearchBineryTree<T>:: Remove(const T&key)
{
	if(_root == NULL)
	{return false;}
	else
	{
		Node* cur = _root;
		Node* parent = _root;
		while(cur->key != key)
		{
			if(cur->key < key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else
			{
				if(cur->key > key)
				{
					parent = cur;
					cur = cur->_left;
				}
				
			}
		}
		if(cur->_left == NULL)
		{
			if(cur == parent->_right)
			{
				parent->_right = cur->_right;
				delete cur;
				return true;
			}
			if(cur == parent->_left)
			{
				parent->_left = cur->_right;
				delete cur;
				return true;
			}
		}
		if(cur->_right == NULL)
		{
			if(cur == parent->_right)
			{
				parent->_right = cur->_left;
				delete cur;
				return true;
			}
			if(cur == parent->_left)
			{
				parent->_left = cur->_left;
				delete cur;
				return true;
			}
		}
		if((cur->_left != NULL)&&(cur->_right != NULL))
		{
			Node* MinParent = cur;
			Node* MinRight = cur->_right;
			while(MinRight->_left)
			{
				MinParent = MinRight;
				MinRight = MinRight->_left;
			}
			cur->key = MinRight->key;
			if(MinRight == MinParent->_left)
			{MinParent->_left = MinRight->_right;}
			if(MinRight == MinParent->_right)
			{MinParent->_right = MinRight->_right;}
			delete MinRight;
			MinParent = NULL;
			return true;
		}
	}
	return false;
}
//   if(root == NULL)
//   {return false;}
//   else
//   {
//	   if(root->key < key)
//	   {return _Remove(root->_right,key);}
//	   else
//	   {
//		   if(root->key > key)
//		   {return _Remove(root->_left,key);}
//		   else                 
//		   {
//			   Node* del = root;
//			   if(root->_left == NULL)
//			   {
//				   root = root->_right;
//				   delete del;
//				   return true;
//			   }
//			   else                  
//			   {
//				   if(root->_right == NULL)
//				   {
//					   root = root->_left;
//					   delete del;
//					   return true;
//				   }
//				   else
//				   {
//					   Node* parent = root;
//					   Node* MinRight = root->_right;
//					   while(MinRight->_left)
//					   {
//						   parent = MinRight;
//						   MinRight = MinRight->_left;
//					   }
//					   
//					   root->key = MinRight->key;
//					   if(parent->_left == MinRight)
//					   {parent->_left = MinRight->_right;}
//					   else
//					   {
//						   if(parent->_right == MinRight)
//						   {parent->_right = MinRight->_right;}
//					   }
//					   delete del;
//					   return true;
//				   }
//			   }
//		   }
//	   }
//   }
//   return false;
//}
template<typename T>
bool SearchBineryTree<T>:: Find(const T&key)
{
	return _Find(_root,key);
}





