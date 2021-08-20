/*
1.9.4
Implementer en char stakk og deretter en template stakk ved å bruke en array
til intern lagring. Lag et testeksempel.
*/

#include "stack.h"

#include <iostream>

void CharStackExample()
{
	using namespace ADS101;
	CharStack charStack(3);

	std::cout << std::boolalpha;
	std::cout << "Empty: " << charStack.empty() << std::endl;

	charStack.push('a');
	charStack.push('b');
	charStack.push('c');

	while (!charStack.empty())
	{
		std::cout << charStack.top();
		charStack.pop();
	}
	std::cout << std::endl;
}

void StackTemplateExample()
{
	using CharStack_T = ADS101::Stack<char>;
	CharStack_T charStack(3);

	std::cout << std::boolalpha;
	std::cout << "Empty: " << charStack.empty() << std::endl;

	charStack.push('a');
	charStack.push('b');
	charStack.push('c');

	while (!charStack.empty())
	{
		std::cout << charStack.top();
		charStack.pop();
	}
	std::cout << std::endl;
}

int main()
{
	CharStackExample();
	StackTemplateExample();
}