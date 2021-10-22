#include "Timer.h"
#include <iostream>
#include <vector>
#include <algorithm>

template<typename T>
static void InsertionSort(std::vector<T>& v)
{
    int j{};
    int n = v.size();
    for (int i = 1; i < n; i++)
    {
        auto hjelp = v[i];
        for (j = i - 1; j >= 0 && v[j] > hjelp; j--)
        {
            v[j + 1] = v[j];
        }
        v[j + 1] = hjelp;
    }
}

template<typename T>
static void MergeSort(std::vector<T>& v)
{
    int i, j, k, lower1, lower2, size, upper1, upper2, n;
    n = v.size();
    std::vector<T> hjelp(n);
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
    } //endwhile
}

template<typename T>
void StdSort(std::vector<T>& v)
{
    std::sort(v.begin(), v.end());
}

static auto GenerateRandomVector(int size)
{
    std::vector<int> v(size);
    for (auto& e : v)
        e = rand();
    return v;
}

template<typename F>
static void GetSortAvg(int size, const F& sortFunc)
{
    double avg{};
    int loops = 10;
    for (int i = 0; i < loops; i++)
    {
        auto v = GenerateRandomVector(size);
        Timer t;
        sortFunc(v);
        avg += t.Stop();
    }
    avg /= loops;
    std::cout << "Sort(" << size << "): " << avg << " milli" << std::endl;
}



void Eksamen2018Oppgave3a()
{
    std::cout << "-----------MERGE SORT---------------\n";
    GetSortAvg<void(std::vector<int>&)>(10, MergeSort);
    GetSortAvg<void(std::vector<int>&)>(100, MergeSort);
    GetSortAvg<void(std::vector<int>&)>(1000, MergeSort);
    GetSortAvg<void(std::vector<int>&)>(10000, MergeSort);
    std::cout << "-----------INSERTION SORT-----------\n";
    GetSortAvg<void(std::vector<int>&)>(10, InsertionSort);
    GetSortAvg<void(std::vector<int>&)>(100, InsertionSort);
    GetSortAvg<void(std::vector<int>&)>(1000, InsertionSort);
    GetSortAvg<void(std::vector<int>&)>(10000, InsertionSort);
    std::cout << "-----------STD SORT-----------\n";
    GetSortAvg<void(std::vector<int>&)>(10, StdSort);
    GetSortAvg<void(std::vector<int>&)>(100, StdSort);
    GetSortAvg<void(std::vector<int>&)>(1000, StdSort);
    GetSortAvg<void(std::vector<int>&)>(10000, StdSort);

}