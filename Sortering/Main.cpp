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

template<typename T>
void MergeSort(std::vector<T>& v)
{
    int i, j, k, lower1, lower2, size, upper1, upper2, n;
    n = v.size();
    std::vector<T> hjelp(n);
    PrintVector(v);
    size = 1;
    while (size < n)
    {
        lower1 = 0;
        k = 0;
        while (lower1 + size < n)
        {
            upper1 = lower1 + size - 1;
            lower2 = upper1 + 1;
            upper2 = (lower2 + size - 1 < n) ? lower2 + size - 1 : n - 1;
            for (i = lower1, j = lower2; i <= upper1 && j <= upper2; k++)
                if (v[i] < v[j])
                    hjelp[k] = v[i++];
                else
                    hjelp[k] = v[j++];

            for (; i <= upper1; k++)
                hjelp[k] = v[i++];
            for (; j <= upper2; k++)
                hjelp[k] = v[j++];

            lower1 = upper2 + 1;
        } // endwhile

        for (i = lower1; k < n; i++)
            hjelp[k++] = v[i];
        for (i = 0; i < n; i++)
            v[i] = hjelp[i];

        size = size * 2;

        PrintVector(v);
    } //endwhile
}

#define ever ;;
template<typename T>
void QuickSort(std::vector<T>& v, int left, int right)
{
    if (left < right)
    {
        auto pivot = v[(left + right) / 2];
        auto i = left;
        auto j = right;
        for (ever)
        {
            while (v[i] < pivot)
                i++;
            while (pivot < v[j])
                j--;
            if (i < j)
                std::swap(v[i], v[j]);
            else
                break;
        }
        QuickSort(v, left, i - 1);
        QuickSort(v, i + 1, right);
    }
}

int main()
{
	auto data = { 17, 14, 4, 7, 1, 2, 5, 9, 11 };
	std::vector<int> v = data;
    std::cout << "Insertion sort:" << std::endl;
	InsertionSort(v);
    std::cout << std::endl;

    v = data;
    std::cout << "Merge sort:" << std::endl;
    MergeSort(v);
    std::cout << std::endl;

    v = data;
    std::cout << "QuickSort:" << std::endl;
    PrintVector(v);
    QuickSort(v, 0, v.size() - 1);
    PrintVector(v);
    std::cout << std::endl;
}