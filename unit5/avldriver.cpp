#include "AVLTree.h"


#include <cstdlib>


int main()
{
	AVLTree tree;
	
	tree.clear();
	
	tree.append(8);
	tree.append(6);
	tree.print();
	tree.append(7);
	tree.print();
	tree.append(5);
	tree.print();
	tree.append(3);
	tree.print();
	tree.append(0);
	tree.print();
	tree.append(9);
	
	cout << tree.find(6) << endl;
	cout << tree.find(12) << endl;
	
	tree.print();
	
	tree.remove(9);
	
	tree.print();
	
	tree.clear();

    AVLTree t;

    for(int i = 0; i < 10; i++)
        t.append(1 + rand() % 100);

    t.print();
    
	
}
