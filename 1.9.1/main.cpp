/*	
	1.9.1
	Implementer en char stakk ved å bruke CharNode klassen
	og lenket liste. Lag et testeksempel.
*/

#include <iostream>
#include "charnode.h"



int main()
{
	using namespace ASD101;
	
	CharNode* node_stack = new CharNode('a');
	node_stack->skrivBaklengs();
	std::cout << " size: " << node_stack->size() << std::endl;
	node_stack->push('b');
	node_stack->skrivBaklengs();
	std::cout << " size: " << node_stack->size() << std::endl;
	node_stack->push('c');
	node_stack->skrivBaklengs();
	std::cout << " size: " << node_stack->size() << std::endl;

	std::cout << "top: " << node_stack->top() << std::endl;
	std::cout << "size: " << node_stack->size() << std::endl;
	node_stack->pop(node_stack);
	std::cout << "top: " << node_stack->top() << std::endl;
	std::cout << "size: " << node_stack->size() << std::endl;
	node_stack->pop(node_stack);
	std::cout << "top: " << node_stack->top() << std::endl;
	std::cout << "size: " << node_stack->size() << std::endl;
	node_stack->pop(node_stack);
	std::cout << "size: " << node_stack->size() << std::endl;

	node_stack = new CharNode('a');
	node_stack->skrivBaklengs();
	std::cout << " size: " << node_stack->size() << std::endl;
	node_stack->push('b');
	node_stack->skrivBaklengs();
	std::cout << " size: " << node_stack->size() << std::endl;
	node_stack->push('c');
	node_stack->skrivBaklengs();
	std::cout << " size: " << node_stack->size() << std::endl;

	node_stack->empty(node_stack);
	std::cout << "size: " << node_stack->size() << std::endl;
}