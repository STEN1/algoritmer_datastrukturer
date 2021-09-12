/*
2.3.1

1. Lag noen arrayer med n tilfeldige tall, for eksempel n = 10, 100, 1000,
10000, 100 000.

2. Ta tiden på sortering av alle arrayene med selectionsort og noter.

3. Ta tiden på sortering av alle arrayene med std::sort og noter.

4. Gjenta punkt 1-3 10 ganger og regn ut gjennomsnitt for hver arraystørrelse
og hver sorteringsfunksjon. Sett opp en tabell med ulike verdier av n og
sorteringstid.

5. Marker verdiene fra tabellen på et ruteark (eller GeoGebra) og prøv å
tilpasse en glatt kurve til dataene i hvert tilfelle.

6. Presenter resultatene i en LATEXrapport.
*/

#include <iostream>
#include <array>
#include <algorithm>
#include <vector>

#include "timer.h"




template<typename Container>
void SelectionSort(Container& c)
{
	for (auto i = 0; i < c.size() - 1; i++)
	{
		for (auto j = i + 1; j < c.size(); j++)
		{
			if (c[i] > c[j])
			{
				std::swap(c[i], c[j]);
			}
		}
	}
}

template<typename Container>
int BinarySearch(Container& c, int x)
{
	int indeks = -1;
	int n = static_cast<int>(c.size());
	int v{ 0 }; int h{ n - 1 };
	while (v <= h && indeks == -1)
	{
		auto midt = (v + h) / 2;
		if (x == c[midt])
			indeks = midt;
		else if (x < c[midt])
			h = midt = 1;
		else // x > a [ midt ]
			v = midt + 1;
	}
	return indeks;
}

auto MakeRandomIntArray(const std::size_t& size)
{
	std::vector<int> randomArray(size);

	for (size_t i = 0; i < size; i++)
	{
		randomArray[i] = rand();
	}

	return randomArray;
}

void WithSelectionSort()
{
	double totalTime1000 = 0.0;
	double totalTime10000 = 0.0;
	double totalTime100000 = 0.0;

	int loops = 10;

	for (int i = 0; i < loops; i++)
	{
		{
			auto array1000 = MakeRandomIntArray(1000);
			Timer timer("Selection sort array1000", &totalTime1000);
			SelectionSort(array1000);
		}
		{
			auto array10000 = MakeRandomIntArray(10000);
			Timer timer("Selection sort array10000", &totalTime10000);
			SelectionSort(array10000);
		}
		{
			auto array100000 = MakeRandomIntArray(100000);
			Timer timer("Selection sort array100000", &totalTime100000);
			SelectionSort(array100000);
		}
	}

	std::cout << "-------------------------------------" << std::endl;
	std::cout << "SelectionSort average runtime with " << loops << " loops." << std::endl;
	std::cout << "array1000: " << totalTime1000 / loops << std::endl;
	std::cout << "array10000: " << totalTime10000 / loops << std::endl;
	std::cout << "array100000: " << totalTime100000 / loops << std::endl;
	std::cout << "-------------------------------------" << std::endl;
}

void WithSTDsort()
{
	double totalTime1000 = 0.0;
	double totalTime10000 = 0.0;
	double totalTime100000 = 0.0;

	int loops = 10;

	for (int i = 0; i < loops; i++)
	{
		{
			auto array1000 = MakeRandomIntArray(1000);
			Timer timer("std::sort array1000", &totalTime1000);
			std::sort(array1000.begin(), array1000.end());
		}
		{
			auto array10000 = MakeRandomIntArray(10000);
			Timer timer("std::sort array10000", &totalTime10000);
			std::sort(array10000.begin(), array10000.end());
		}
		{
			auto array100000 = MakeRandomIntArray(100000);
			Timer timer("std::sort array100000", &totalTime100000);
			std::sort(array100000.begin(), array100000.end());
		}
	}

	std::cout << "-------------------------------------" << std::endl;
	std::cout << "std::sort average runtime with " << loops << " loops." << std::endl;
	std::cout << "array1000: " << totalTime1000 / loops << std::endl;
	std::cout << "array10000: " << totalTime10000 / loops << std::endl;
	std::cout << "array100000: " << totalTime100000 / loops << std::endl;
	std::cout << "-------------------------------------" << std::endl;
}


int main()
{
	WithSelectionSort();
	WithSTDsort();
}