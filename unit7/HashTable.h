#ifndef HashTable_H
#define HashTable_H
//#include<string>
#include<iostream>
using namespace std;


class HashTable{
	
	
	private:
		struct Element{
			string key;
			int mark;
			
		};
		
		Element *table;
		int size;
		
	public:
		HashTable(int);	//done
		~HashTable();	//done
		void insert(string); //done
		void remove(string); //done
		bool isFull();	//done
		bool isEmpty();	//done
		void clear();	//done
		void print();	//done
		bool find(string); //done
		
	private:
		int hash(string); //done
		
};

HashTable::HashTable(int s)
{
	size=s;
	table= new Element[size];
	int i=0;
	while(i<size)
	{
		table[i].mark=0;
		i++;
	}
	
}

HashTable::~HashTable()
{
	delete [] table;
}


bool HashTable::find(string s)
{
	int i=0;
	while(i<size)
	{
		if(table[i].mark ==2 && table[i].key==s)
		{
			return true;
		}
		i++;
	}
	
	return false;
}


void HashTable::print()
{
	int i=0;
	while(i<size)
	{
		if(table[i].mark==2)
		{
			cout<<table[i].key<<endl;
		}
		i++;
	}
	
	cout<<endl;
}

void HashTable::clear()
{
	int i=0;
	while(i<size)
	{
		table[i].mark=0;
		i++;
	}
	
}


void HashTable::remove(string s)
{
		int i=0;
		while(i<size)
		{
			if(table[i].mark==2 && table[i].key==s)
			{
				table[i].mark=1;
				//cout<<table[i].key<< " 11111 "<<endl;
				//cout<<table[i].mark<< " 11111 "<<endl;
				return;
			}
			
			i++;
		}
}
	

int HashTable::hash(string s) 
{
	int total=0;
	for(int i=0; i<s.length(); i++)
	{
		total=total+ (int)s[i]; 
		cout<<" asci for "<<s[i]<<" is "<<((int)s[i])<< endl; 
	}
	cout<<" asci for "<<s<<" is "<<total<< " and modulo is "<<(total%size)<<endl;
	int hashIndex=total%size;
	int end=size-1;
	int curr=hashIndex;
	
	if(table[hashIndex].mark==2)
	{
		hashIndex++;
		if(hashIndex>end)
		{
			hashIndex=0;
		}
		
		while(table[hashIndex].mark==2)
		{
			cout<<hashIndex<<"   ";
			if(curr==hashIndex)
			{	
				return -1;
				
			}
			else if(hashIndex==end)
			{
				hashIndex=0;
			}
			else
			{
				hashIndex++;
			}	
		}
		
		
	}

	
	return hashIndex;
	
}

void HashTable::insert(string s)
{
	int hashIndex=hash(s);
	if(hashIndex==-1)
	{
		return;
	}
	else
	{
		table[hashIndex].key=s;
		table[hashIndex].mark=2;
	}
}

bool HashTable::isEmpty()
{
	int i=0;
	while(i<size && table[i].mark==0)
	{
		i++;
	}
	
	if(i==size)
	{
		return true;
	}
	
	return false;
	
}

bool HashTable::isFull()
{
	int i=0;
	while(i<size && table[i].mark==2) 
	{
		i++;
	}
	
	if(i==size)
	{
		return true;
	}
	
	return false;
}






#endif

