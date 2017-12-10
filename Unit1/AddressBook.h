#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H

#include<string>
#include<iostream>
using namespace std;

class AddressBook
{
	private:
	struct Contact
	{
		string name, phone;
		bool used;
	};
	Contact* list;
	int cap;
	
	public:
	AddressBook(int);
	~AddressBook();
	bool isEmpty() const;
	bool isFull() const;
	void add(string, string);
	void remove(string);
	void clear();
	string find(string);
};

AddressBook::AddressBook(int var)
{
	cap=var;
	list= new Contact[cap]; // array of struct Contact created 
							// to access list[0] , list[1].name or list[1].phone etc
	clear();

}


AddressBook::~AddressBook()
{
	delete [] list;
}

bool AddressBook::isEmpty() const
{
	for(int i=0; i<cap; i++)
	{
		if(Contact[i].used==true)
		{
			return false;
		}
	}
	
	return true;
}

bool AddressBook::isFull() const
{
	for(int i=0; i<cap ;i++)
	{
		if( Contact[i].used==false ) 
		{
			return false;
		}
	}
	
	return true;
	
}

void AddressBook::add(string n, string p)
{
	for(int i=0; i<cap; i++)
	{
		if( Contact[i].used==false)
		{
			
			Contact[i].name=n;
			Contact[i].phone=p;
			Contact[i].used=true;
			break;
		}
		
	}
}

void AddressBook::remove(string contactName)
{
	for(int i=0; i<cap; i++)
	{
		if(Contact[i].name==contactName)
		{
			Contact[i].used=false;
			break;
		}
		
	}
}

void AddressBook::clear()
{
	for(int i=0; i<cap; i++ )
	{
		Contact[i].used=false;
	}
}


string AddressBook::find(string contactName)
{
	for(int i=0; i<cap; i++)
	{
		if( Contact[i].name==contactName  )
		{
			return Contact[i].phone;
		}
	}
	
	return "NO MATCH";

}
#endif

