 

#include "Tree.h"

 
int main()
{
	
	Reality::Tree<int> tree;

	tree.push_back(124);
	tree.push_back(44);
	tree.push_back(544);
	tree.push_back(244);
	tree.push_back(8888888);
	tree.push_back(3437);


	std::cout << tree.Max();
	std::cout << "\n" << tree.Min();
	std::cout << "\n";
	 

	

	std::cout << tree.find(44) << "\n";
 
 

	 
 
	system("pause");
	return 0;
}