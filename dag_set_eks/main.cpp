// ADS101 (170914) (181001) 191014
// stl set eksempel

#include <iostream>
#include <set>
#include <map>

using namespace std;

// set - ordnet container uten duplikater, altså sortert
// begin end size empty insert
// siden duplikater ikke er tillatt, er det logisk å
// returnere en bool ved insert
// insert returnerer i tillegg en iterator til innsatt element
// returverdien er altså et par:

//set<double>::iterator it;
//typedef set<double>::iterator setIt;

void setEks()
{
   // pair<setIt, bool> par;
    set<double> ds;

    if (auto [iter, confirmation] = ds.insert(3.14); confirmation) 
        cout << "inserted " << *iter << " ok" << endl;
    if (auto [iter, confirmation] = ds.insert(9.81); confirmation) 
        cout << "inserted " << *iter << " ok" << endl;
    if (auto [iter, confirmation] = ds.insert(1.0); confirmation) 
        cout << "inserted " << *iter << " ok" << endl;
    if (auto [iter, confirmation] = ds.insert(1.0); confirmation) 
        cout << "inserted " << *iter << " ok" << endl;
    for (auto& d : ds)
        cout << d << ", ";
    cout << endl;
}
// map - ordnet container med (key, value) par
// key - entydig
// flere keys kan mappe til samme value
// map virker som set med sammenligning kun på key
// begin end size empty insert find erase
// ValueType& operator[] (const KeyType& key);

void mapEks()
{

}

float& moveEks(float&& x)
{
    float& y = x;
    return y;
    //std::move()
}
float moveEks2(float&& x)
{
    float y = x;
    return y;
}

int main()
{
    float& b = moveEks(3.14f);
    cout << b;
    float c = moveEks2(9.81f);
    cout << " " << c;
    cout << "\n *** set ***\n";
    setEks();
    return 0;
}
