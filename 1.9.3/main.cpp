/*
1.9.3
Implementer en char k� og deretter en template k� ved � bruke en array til
intern lagring.Lag et testeksempel.
*/

#include "queue.h"

#include <iostream>

void char_queue_example()
{
	using namespace ADS101;
	CharQueue charQueue(5);

	charQueue.push('a');
	charQueue.push('b');
	charQueue.push('c');
	charQueue.push('d');
	charQueue.push('e');
	charQueue.pop();
	charQueue.pop();
	charQueue.push('f'); 
	charQueue.push('g');
	charQueue.push('h'); // can't add more elements than queue max size
	std::cout << "Size: " << charQueue.size() << std::endl;
	std::cout << "Printing queue data:" << std::endl;
	while (charQueue.size() > 0)
	{
		std::cout << charQueue.front() << std::endl;
		charQueue.pop();
		std::cout << "Size: " << charQueue.size() << std::endl;
	}
}

void queue_T_example()
{
	using CharQueue_T = ADS101::Queue<char>;
	CharQueue_T charQueue(5);

	charQueue.push('a');
	charQueue.push('b');
	charQueue.push('c');
	charQueue.push('d');
	charQueue.push('e');
	charQueue.pop();
	charQueue.pop();
	charQueue.push('f');
	charQueue.push('g');
	charQueue.push('h'); // can't add more elements than queue max size
	std::cout << "Size: " << charQueue.size() << std::endl;
	std::cout << "Printing queue data:" << std::endl;
	while (charQueue.size() > 0)
	{
		std::cout << charQueue.front() << std::endl;
		charQueue.pop();
		std::cout << "Size: " << charQueue.size() << std::endl;
	}
}

int main()
{
	char_queue_example();
	queue_T_example();
}