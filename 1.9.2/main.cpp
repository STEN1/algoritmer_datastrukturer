/*
1.9.2
Implementer en template stakk ved å bruke CharNode klassen og lenket liste.
Lag et testeksempel.
*/

#include <iostream>

#include "stack.h"

int main()
{
	using namespace ADS101;

	Stack<int> stack;

	stack.push(17);
	stack.push(16);
	stack.push(15);
	stack.push(14);
	std::cout << "Size: " << stack.size() << std::endl;

	std::cout << "Print data:" << std::endl;
	while (stack.size() > 0)
	{
		std::cout << stack.top()->get() << std::endl;
		stack.pop();
	}
	std::cout << "Size: " << stack.size() << std::endl;

	std::cout << std::boolalpha;
	std::cout << "Empty: " << stack.empty() << std::endl;
}