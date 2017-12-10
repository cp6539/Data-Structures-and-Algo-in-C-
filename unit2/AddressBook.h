#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H

#include<string>
#include<iostream>
using namespace std;

class AddressBook{
	
		private:
			struct Contact{
				string name;
				string phone;
				Contact *next;
			}; 
			
			Contact *list;
			
		public:
			AddressBook();   		
			~AddressBook();
			bool isEmpty() const;			
			bool isFull() const;				
			void add(string name, string phone);
			void remove(string name);
			void clear();
			string find(string name);
};

AddressBook::AddressBook()
{
	list=NULL;
}

AddressBook::~AddressBook()
{
	
	clear();
	cout<<"Program ended!!";
	
}

bool AddressBook::isEmpty() const
{
	if(list==NULL)
	{
		return true;
	}
	
	return false;
}

bool AddressBook::isFull() const
{
	Contact *temp= new Contact();
	if(temp==NULL)
	{
		delete temp;
		return true;
	}
	
	delete temp;
	return false;
}


void AddressBook::add(string name, string phone)
{
	if(isFull())
	{
		return;
	}
	else
	{
		Contact *temp= new Contact();
		temp->name=name;
		temp->phone=phone;
		temp->next=NULL;
		if(list==NULL)
		{
			list=temp;
			list->next=NULL;
		}
		else
		{
			Contact *p=list;
			while(p->next!=NULL)
			{
				p=p->next;
			}
			
			p->next=temp;
		}
	}
	
}

void AddressBook::remove(string name)
{
	Contact *delPtr=NULL;
	Contact *temp=list;
	Contact *curr=list;
	
	if(list==NULL)
	{
		return;
	}
	else
	{	
	while(curr!=NULL && curr->name!=name)
	{
		temp=curr;
		curr=curr->next;
	}
	
	if(curr==NULL)
	{
		return;
	}
	else
	{
		delPtr=curr;
		curr=curr->next;
		temp->next=curr;
		delete delPtr;
	}
	}
		
}

void AddressBook::clear()
{
	if(list==NULL)
	{
		return;
	}
	else if(list->next==NULL)
	{
		delete list;
	}
	else
	{
		Contact *prev=list;
		Contact *curr=list->next;
		Contact *temp;
		while(curr->next!=NULL)
		{
			curr=curr->next;
			temp=prev;
			prev=prev->next;
			delete temp;;
		}
		
		delete prev;
		delete curr;
	}
	
	list=NULL;

	
}

string AddressBook::find(string name)
{
	if(list==NULL)
	{
		return "NONE FOUND";
	}
	
	Contact *temp=list;
	while(temp->name!=name)
	{
		temp=temp->next;
		if(temp==NULL)
		{
			return "NONE FOUND";
		}
	}
	
	if(temp->name==name)
	{
		return temp->phone;
	}

	
}
#endif

