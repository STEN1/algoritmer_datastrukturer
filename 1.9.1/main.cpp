/*	
	1.9.1
	Implementer en char stakk ved å bruke CharNode klassen
	og lenket liste. Lag et testeksempel.
*/

#include <iostream>
#include "charstack.h"



int main()
{
	using namespace ADS101;

	Stack stack;

	std::cout << std::boolalpha;
	std::cout << "empty? " << stack.empty() << std::endl;

	stack.push('a');
	std::cout << stack.top();
	stack.push('b');
	std::cout << stack.top();
	stack.push('c');
	std::cout << stack.top();
	std::cout << std::endl;

	std::cout << std::boolalpha;
	std::cout << "empty? " << stack.empty() << std::endl;

	stack.pop();
	std::cout << stack.top();
	stack.pop();
	std::cout << stack.top();
	stack.pop();
	// std::cout << stack.top()->hentData();
	std::cout << std::endl;

	std::cout << "empty? " << stack.empty() << std::endl;
}