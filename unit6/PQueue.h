#ifndef PQueue_H
#define PQueue_H
#include<iostream>
using namespace std;

class PQueue{
	
	private:
		int *heap;
		int size;
		int bottom;
		//static int j;
		
	public:
		PQueue(int);;
		~PQueue();
		void enqueue(int);
		void dequeue();
		int top();
	
	private:
		void ReHeapUp();
		void ReHeapDown();
};


//int PQueue::j=1;

PQueue::PQueue(int s)
{
	size=s;
	heap=new int[size];
	bottom=-1;
}

PQueue::~PQueue()
{
	delete [] heap;
}

void PQueue::enqueue(int data)
{
	if(bottom==size-1)
	{
		return;
	}
	else
	{
		bottom++;
		heap[bottom]=data;
		ReHeapUp();
	}
}

void PQueue::ReHeapUp()
{
	int childIndex=bottom; 
	int parentIndex;
	while(childIndex>0)
	{
		parentIndex=((childIndex-1)/2);
		if(heap[childIndex]>heap[parentIndex])
		{
			int temp=heap[parentIndex];
			heap[parentIndex]=heap[childIndex];
			heap[childIndex]=temp;
			
			/**cout<<"CALL: "<<j<<endl;
			for(int i=0;i<=bottom;i++)
			{
				cout<<heap[i]<<" ";
				
			}
			j++;
			cout<<endl;**/
		}
		else
		{
			return;
		}
		
		childIndex=parentIndex;
	}

}


int PQueue::top()
{
	if(bottom==-1)
	{
		return -1;
	}
	return heap[0];
}



void PQueue::dequeue()
{
	if(bottom==-1)
	{
		return;
	}
	else
	{
		int temp=heap[0];
		heap[0]=heap[bottom];
		heap[bottom]=0;
		bottom--;
		ReHeapDown();
	}
}


void PQueue::ReHeapDown()
{

	int parentIndex=0;
	int leftChildIndex=(2*parentIndex)+1;
	int rightChildIndex=(2*parentIndex)+2;
	int largestIndex = parentIndex;
	
	while(parentIndex<=bottom)
	{
			if(leftChildIndex==bottom)
			{
				largestIndex=leftChildIndex;
			}
			else
			{
				if(heap[leftChildIndex]>heap[rightChildIndex])
				{	
					largestIndex=leftChildIndex;
				}	
				else
				{
					largestIndex=rightChildIndex;	
				}
			}	
		
			if(heap[parentIndex]<heap[largestIndex])
			{
				int temp=heap[parentIndex];
				heap[parentIndex]=heap[largestIndex];
				heap[largestIndex]=temp;
			
				parentIndex=largestIndex;
				leftChildIndex=(parentIndex*2)+1;
				rightChildIndex=(parentIndex*2)+2;
				if(leftChildIndex>bottom)
				{
					return;
				}
				
				
			}
			else
			{
				return;
			}		
	}
	
}


#endif
