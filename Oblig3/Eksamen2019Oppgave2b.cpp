#include <vector>
#include <iostream>
#include <string>
#include <Windows.h>

template<typename T>
static void PrintVector(const std::vector<T>& v)
{
    for (auto& e : v)
        std::cout << e << ' ';
    std::cout << std::endl;
}

template<typename T>
static void MergeSort(std::vector<T>& v)
{
    int i, j, k, lower1, lower2, size, upper1, upper2, n;
    n = v.size();
    std::vector<T> hjelp(n);
    size = 1;
    PrintVector(v);
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
        std::cout << "Partial array size: " << size << std::endl;
        PrintVector(v);
        size = size * 2;
    } //endwhile
    PrintVector(v);
}

static auto GenerateRandomVector(int size)
{
    std::vector<int> v(size);
    for (auto& e : v)
        e = rand() % 100 + 1;
    return v;
}


void Eksamen2019Oppgave2b()
{
    auto v = GenerateRandomVector(14);
    MergeSort(v);

    // For the æ, ø, å :D
    SetConsoleOutputCP(CP_UTF8);
    std::u8string s{};
    s += u8"I mergesort så flettes enkelte elementer inn i hverandre.\n";
    s += u8"Enkeltverdier blir først sammenlignet og puttet i rett rekkefølge\n";
    s += u8"i et array med size 2. Så sammenlignes minste verdier fra to arrayer\n";
    s += u8"og puttet i et array med size 4, helt til man får et sortert array av\n";
    s += u8"hele datasettet.\n";
    std::cout << (const char*)s.c_str();
}