#ifndef MyIntDeque_H
#define MyIntDeque_H

#include <iostream>
using namespace std;

//change 222

class MyIntDeque{
	
	private:
		int *list;
		int cap;
		int length;
		int first;
		int last;
		
	public:
		MyIntDeque(int);
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

MyIntDeque::MyIntDeque(int s)
{
	cap=s;
	length=0;
	first=-1;
	last=-1;
	list= new int[cap];

	
}

MyIntDeque::~MyIntDeque()
{
	delete [] list;
}


void MyIntDeque::push_back(int data)
{
	if(first==-1 && last==-1)
	{
		first++;
		last++;
		list[last]=data;
		length++;
	}
	else if((last+1)%cap==first)
	{
		return;  //it means the Queue is FUll 
 	}
	else
	{
		last=(last+1)%cap;
		list[last]=data;
		length++;
	}
	
	
}

void MyIntDeque::pop_front()
{
	if(first==-1 && last==-1)
	{
		return;
	}
	else if(first==last)
	{
		first=-1;
		last=-1;
		length=0;
	}
	else
	{
		first=(first+1)%cap;
		length--;
	}
	
}

int MyIntDeque::size()
{
	return length;
}

int MyIntDeque::front()
{
	if(first==-1 & last==-1)
	{
		return -1;
	}
	else
	{
		return list[first];
	}
}

int MyIntDeque::back()
{
	if(first==-1 && last==-1)
	{
		return -1;
	}
	else
	{
		return list[last];
	}
}

bool MyIntDeque::isFull() const
{
	if(length==cap)
	{
		return true;
	}
	
	return false;
}

bool MyIntDeque::isEmpty() const
{
	if(first==-1 && last==-1)
	{
		return true;
	}
	
	return false;
}

void MyIntDeque::clear()
{
	first=-1;
	last=-1;
	length=0;
}


//push_front - accepts an integer as it's only argument.  Inserts the integer at the front of the deque.
void MyIntDeque::push_front(int data)
{
	if(first==-1 && last==-1)
	{
		first=cap-1;
		last=cap-1;
		list[first]=data;
		length++;
	}
	else if(first==0 && last==cap-1) 
	{
		return; //cannot add anything to the list	
	}
	else if((first-1)==last)
	{
		return;
	}
	else
	{
		if(first==0)
		{
			first=cap-1;
			list[first]=data;
			length++;
		}
		else
		{
			first--;
			list[first]=data;
			length++;
		}
	}
		
}


//pop_back - removes the integer at the end of the deque.
void MyIntDeque::pop_back()
{
	if(first==-1 && last==-1)
	{
		return;
	}
	else if(first==last)
	{
		first=-1;
		last=-1;
		length=0;
	}
	else if(last==0)
	{
		last=cap-1;
		length--;
	}
	else
	{
		last--;	
		length--;
	}
}



#endif
