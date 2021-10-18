#include <iostream>
#include <vector>

template<typename T>
void PrintVector(const std::vector<T>& v)
{
	for (auto& e : v)
		std::cout << e << ' ';
	std::cout << std::endl;
}

template<typename T>
void InsertionSort(std::vector<T>& v)
{
	int j{};
	int n = v.size();
	PrintVector(v);
	for (int i = 1; i < n; i++)
	{
		auto hjelp = v[i];
		for (j = i - 1; j >= 0 && v[j] > hjelp; j--)
		{
			v[j+1] = v[j];
			PrintVector(v);
		}
		v[j+1] = hjelp;
		PrintVector(v);
	}
}

int main()
{
	auto data = { 17, 14, 4, 7, 1, 2, 5, 9, 11 };
	std::vector<int> v = { data };
	InsertionSort(v);
}