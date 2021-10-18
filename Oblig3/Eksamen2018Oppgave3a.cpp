#include "Timer.h"
#include <iostream>
#include <vector>

template<typename T>
void InsertionSort(std::vector<T>& v)
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
void MergeSort(std::vector<T>& v)
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


auto GenerateRandomVector(int size)
{
    std::vector<int> v(size);
    for (auto& e : v)
        e = rand();
    return v;
}

void Eksamen2018Oppgave3a()
{
	double InsertionSort10avg{};
    double InsertionSort100avg{};
    double InsertionSort1000avg{};
    double InsertionSort10000avg{};
    double MergeSort10avg{};
    double MergeSort100avg{};
    double MergeSort1000avg{};
    double MergeSort10000avg{};

    auto loops = 10;

    for (size_t i = 0; i < loops; i++)
    {
        {
            auto v = GenerateRandomVector(10);
            Timer t;
            InsertionSort(v);
            InsertionSort10avg += t.Stop();
        }
        {
            auto v = GenerateRandomVector(100);
            Timer t;
            InsertionSort(v);
            InsertionSort100avg += t.Stop();
        }
        {
            auto v = GenerateRandomVector(1000);
            Timer t;
            InsertionSort(v);
            InsertionSort1000avg += t.Stop();
        }
        {
            auto v = GenerateRandomVector(10000);
            Timer t;
            InsertionSort(v);
            InsertionSort10000avg += t.Stop();
        }
        {
            auto v = GenerateRandomVector(10);
            Timer t;
            MergeSort(v);
            MergeSort10avg += t.Stop();
        }
        {
            auto v = GenerateRandomVector(100);
            Timer t;
            MergeSort(v);
            MergeSort100avg += t.Stop();
        }
        {
            auto v = GenerateRandomVector(1000);
            Timer t;
            MergeSort(v);
            MergeSort1000avg += t.Stop();
        }
        {
            auto v = GenerateRandomVector(10000);
            Timer t;
            MergeSort(v);
            MergeSort10000avg += t.Stop();
        }
    }

    InsertionSort10avg /= loops;
    InsertionSort100avg /= loops;
    InsertionSort1000avg /= loops;
    InsertionSort10000avg /= loops;
    MergeSort10avg /= loops;
    MergeSort100avg /= loops;
    MergeSort1000avg /= loops;
    MergeSort10000avg /= loops;

    auto unit = " Milliseconds";

    std::cout << "Insertion sort avg(10): " << InsertionSort10avg << unit << std::endl;
    std::cout << "Insertion sort avg(100): " << InsertionSort100avg << unit << std::endl;
    std::cout << "Insertion sort avg(1000): " << InsertionSort1000avg << unit << std::endl;
    std::cout << "Insertion sort avg(10000): " << InsertionSort10000avg << unit << std::endl;
    std::cout << std::endl;
    std::cout << "Merge sort avg(10): " << MergeSort10avg << unit << std::endl;
    std::cout << "Merge sort avg(100): " << MergeSort100avg << unit << std::endl;
    std::cout << "Merge sort avg(1000): " << MergeSort1000avg << unit << std::endl;
    std::cout << "Merge sort avg(10000): " << MergeSort10000avg << unit << std::endl;
}