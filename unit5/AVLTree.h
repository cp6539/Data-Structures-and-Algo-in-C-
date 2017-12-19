#ifndef AVLTree_H
#define AVLTree_H

#include<iostream>
using namespace std;

class AVLTree{
	
	private:
		struct Node{
			int value;
			Node *left;
			Node *right;
		};
		
	Node *root;
	void rotateRight(Node * &);
	void rotateLeft(Node* &a);
	void rotateRightLeft(Node* &a);
	void rotateLeftRight(Node* &a);
	int height(Node *);
	int difference(Node*);
	void balance(Node* &);
	void append(Node *&,int);
	void remove(Node *&,int);
	void inorder(Node*);
	bool find(Node*,int);
	void clear(Node* &);
	void print(Node* );
	
	public:
		AVLTree();
		~AVLTree();
		void clear();
		void append(int);
		void remove(int);
		bool find(int);
		void print();
		bool isEmpty();
		bool isFull();
		
};

AVLTree::AVLTree() 
{
	root=NULL;
}

AVLTree::~AVLTree()
{
	clear(root);
}

void AVLTree::clear(Node* &r)
{
	if(r!=NULL)
	{
		clear(r->left);
		clear(r->right);
		delete r;
		r=NULL;
	}
}

void AVLTree::clear()
{
	clear(root);
}

int AVLTree::height(Node *r)
{
	if(r==NULL)
	{
		return 0;
	}
	else
	{
		int left=height(r->left);
		int right=height(r->right);
		
		if( left> right)
		{
			return left+1;
		}
		else
		{
			return right+1;
		}
	}
	
}

/*
 * 	right- right Rotation
 */
void AVLTree::rotateRight(Node* &parent)
{
    Node *temp;
    temp = parent->right;
    parent->right = temp->left;
    temp->left = parent;
    parent=temp;
}
/*
 * Left- Left Rotation
 */
void AVLTree::rotateLeft(Node* &parent)
{
    Node *temp;
    temp = parent->left;
    parent->left = temp->right;
    temp->right = parent;
    parent=temp;
}
 
/*
 * Left - Right Rotation
 */
void AVLTree::rotateLeftRight(Node* &parent)
{
    Node* temp;
    temp = parent->left;
    rotateRight(temp);
	parent->left=temp;
    rotateLeft(parent);
}
 
/*
 * Right- Left Rotation
 */
void AVLTree::rotateRightLeft(Node* &parent)
{
    Node* temp;
    temp = parent->right;
    rotateLeft(temp);
	parent->right=temp;
    rotateRight(parent);
}


int AVLTree::difference(Node *r)
{
	int leftHeight=height(r->left);
	int rightHeight=height(r->right);
	int bf= leftHeight-rightHeight;
	return bf;
}

void AVLTree::balance(Node* &temp)
{
    int bal_factor = difference(temp);
    if (bal_factor > 1)
    {
        if (difference (temp->left) > 0)
            rotateLeft(temp);
        else
           rotateLeftRight(temp);
    }
    else if (bal_factor < -1)
    {
        if (difference (temp->right) > 0)
            rotateRightLeft(temp);
        else
           rotateRight(temp);
    }
}

void AVLTree::append(Node*& lroot,int data)
{
	 if (lroot == NULL)
    {
        lroot = new Node;
        lroot->value = data;
        lroot->left = NULL;
        lroot->right = NULL;
			
    }
    else if (data < lroot->value)
    {
        if(lroot->left==NULL){
			Node *newNode = new Node;
			newNode->value = data;
			newNode->left = NULL;
			newNode->right = NULL;
			lroot->left=newNode;
			balance(root);
		}
		else{
			append (lroot->left,data);
			
		}
        
    }
    else if (data >= lroot->value)
    {
        if(lroot->right==NULL){
			Node *newNode = new Node;
			newNode->value = data;
			newNode->left = NULL;
			newNode->right = NULL;
			lroot->right=newNode;
			balance(root);
		}
		else{
			append (lroot->right,data);
		}
    }
	
}

void AVLTree::append(int data)
{
	append(root,data);
}

bool AVLTree::find(Node* a, int data)
{
	if(a==NULL)
	{
		return false;
	}
	else if(data == a->value)
	{
		return true;
	}
	else if(data < a->value)
	{
		find(a->left,data);
	}
	else
	{
		find(a->right,data);
	}
}

void AVLTree::remove(Node* &a,int data)
{
	if(a==NULL)
	{
		return;
	}
	else if(data < a->value)
	{
		remove(a->left,data);
	}
	else if(data > a->value)
	{
		remove(a->right, data);
	}
	else
	{
		if(a->left==NULL && a->right==NULL)
		{
			delete a;
			a=NULL;
		}
		else if(a->left==NULL)
		{
			Node * temp=a;
			a=a->right;
			delete temp;
			root->left=a;
		}
		else if(a->right==NULL)
		{
			Node *temp=a;
			a=a->left;
			delete temp;
			root->right=a;
		}
		else
		{
			Node *temp=a->right;
			while(temp->left!=NULL)
			{
				temp=temp->left; //finding the minimum value in the right subtree
			}
			
			a->value=temp->value;
			delete temp;
			temp=NULL;x
			
		}
	}
}

void AVLTree::remove(int data)
{
	remove(root,data);
}

bool AVLTree::find(int data)
{
	find(root,data);
}

void AVLTree::print(Node* r)
{
	if(r!=NULL)
	{
		print(r->left);
		cout<<r->value<<"  ";
		print(r->right);
	}
	cout<<endl;
}


void AVLTree::print()
{
	cout<<"height: "<<height(root);
	print(root);
}

bool AVLTree::isEmpty()
{
	if(root==NULL)
	{
		return true;
	}
	return false;
}

bool AVLTree::isFull()
{
	Node *t= new Node;
	if(t==NULL)
	{
		return true;
	}
	return false;
}


#endif
