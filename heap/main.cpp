/*
6.5.1
Sett inn tallene 9, 17, 2, 7, 5, 8, 1, 22, 4, 11, 6 i en stigende prioritetsk�.

6.5.2
Skriv et lite program som sorterer de samme tallene ved hjelp av stl prioritetsk�.

6.5.3
Blir det alltid riktig � reorganisere heapen(ved � bytte et blad over i h�yre subtre) som p� figur 6.4?

6.5.4
Lag en egen heap implementering, enten ved � bruke en dynamisk struktur eller array til � lagre heapen.
*/


#include <vector>
#include <queue>
#include <iostream>
int main()
{
	const auto data = { 9, 17, 2, 7, 5, 8, 1, 22, 4, 11, 6 };
	std::priority_queue<int> q;

	for (auto& n : data)
		q.push(n);

	std::vector<int> sorted_data;

	while (!q.empty())
	{
		sorted_data.push_back(q.top());
		q.pop();
	}

	std::cout << "Sorted data:" << std::endl;
	for (auto& n : sorted_data)
		std::cout << n << ", ";
	std::cout << std::endl;

}