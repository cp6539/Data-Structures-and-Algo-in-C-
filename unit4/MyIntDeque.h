#ifndef MyIntDeque_H
#define MyIntDeque_H

#include <iostream>
using namespace std;

class MyIntDeque{
	
	private:
		struct Node{
			int value;
			Node *next;
			Node *prev;	
		};
		
		Node *first;
		Node *last;
		
	public:
		MyIntDeque();
		~MyIntDeque();
		void push_back(int);
		void push_front(int);
		void pop_back();
		void pop_front();
		int size();
		int front();
		int back();
		bool isFull() const;
		bool isEmpty() const;
		void clear();

};

MyIntDeque::MyIntDeque()
{
	first=NULL;
	last=NULL;
}

MyIntDeque::~MyIntDeque()
{
	clear();
}

void MyIntDeque::push_back(int value)
{
	Node *newNode=new Node();
	newNode->value=value;
	newNode->next=newNode;
	newNode->prev=newNode;
	
	if(first==NULL && last==NULL)
	{
		first=newNode;
		last=newNode;
	}
	else if(first->next==first)
	{
		first->next=newNode;
		newNode->prev=first;
		newNode->next=first;
		first->prev=newNode;
		last=newNode;
		
	}
	else
	{
		last->next=newNode;
		newNode->prev=last;
		newNode->next=first;
		first->prev=newNode;
		last=newNode;
	}
	
}

//push_front - accepts an integer as it's only argument.  
//Inserts the integer at the front of the deque.
void MyIntDeque::push_front(int value)
{
	Node *newNode =new Node();
	newNode->value=value;
	newNode->next=newNode;
	newNode->prev=newNode;
	
	if(first==NULL && last==NULL)
	{
		first=newNode;
		last=newNode;
	}
	else if(first->next==first)
	{
		newNode->next=first;
		first->prev=newNode;
		newNode->prev=first;
		first->next=newNode;
		first=newNode;
	}
	else
	{
		newNode->next=first;
		first->prev=newNode;
		newNode->prev=last;
		last->next=newNode;
		first=newNode;
	}
}

//pop_back - removes the integer at the end of the deque.
void MyIntDeque::pop_back()
{
	if(first==NULL && last==NULL)
	{
		return;
	}
	else if(last->next==last)
	{
		MyIntDeque::clear();	
	}
	else
	{
		Node *temp=last;
		last=last->prev;
		last->next=first;
		first->prev=last;
		delete temp;
	}
}


void MyIntDeque::pop_front()
{
	if(first==NULL && last==NULL)
	{
		return;
	}
	else
	{
		if(first->next==first)
		{
			MyIntDeque::clear();
		}
		else
		{
			Node *temp=first;
			first=first->next;
			temp->next=NULL;
			temp->prev=NULL;
			delete temp;
			
			first->prev=last;
			last->next=first;
			
		}
	}
}

int MyIntDeque::size()
{
	int length=0;
	if(first==NULL && last==NULL)
	{
		return length;
	}
	else
	{
		Node *temp=first;
		if(temp->next==first)
		{
			length++;
			return length;
		}
		
		while(temp!=last)
		{
			length++;
			temp=temp->next;
		}
		
		return length+1;
	}
}

int MyIntDeque::front()
{
	if(first==NULL && last==NULL)
	{
		return -1;
	}
	else
	{
		return first->value;
	}
}

int MyIntDeque::back()
{
	if(first==NULL && last==NULL)
	{
		return -1;
	}
	else
	{
		return last->value;
	}
}

bool MyIntDeque::isFull() const
{
	Node *temp=new Node();
	if(temp==NULL)
	{
		return true;
	}
	return false;
}

bool MyIntDeque::isEmpty() const
{
	if(first==NULL && last==NULL)
	{
		return true;
	}
	
	return false;
}

void MyIntDeque::clear()
{
	if(first==NULL && last==NULL)
	{
		return;
	}
	else if(first->next==first)
	{
		delete first;
	}
	else
	{
		Node *temp=first;
		Node *t;
		while(temp!=last)
		{
			t=temp;
			temp=temp->next;
			delete t;
		}
		delete temp;
	}
	
	first=NULL;
	last=NULL;
	
}

#endif
