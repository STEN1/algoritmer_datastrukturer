#include <iostream>
#include <unordered_set>
#include <string>

struct Test
{
	int key;
	std::string s;
	bool operator == (const Test& t2) const { return key == t2.key; }
};

namespace std
{
	template<>
	class hash<Test>
	{
	public:
		size_t operator() (const Test& t) const
		{
			return t.key % 7;
		}
		bool operator() (const Test& t1, const Test& t2)
		{
			return t1.key == t2.key;
		}
	};
}

void SkrivUtTestSet(const std::unordered_set<Test>& us, int startKey, int endKey)
{
	for (int i = startKey; i <= endKey; i++)
	{
		Test t{ i, "" };
		auto it = us.find(t);
		if (it != us.end())
		{
			auto& [key, val] = *it;
			std::cout << "Key: " << key << ' ' << "Value: " << val << std::endl;
		}
	}
}

void Eksamen2019Oppgave3a()
{
	std::unordered_set<Test> uordnet_sett;
	for (int i = 12; i <= 13; i++)
		uordnet_sett.emplace(i, std::to_string(i * 1000));
	for (int i = 20; i <= 21; i++)
		uordnet_sett.emplace(i, std::to_string(i * 1000));
	for (int i = 1; i <= 6; i++)
		uordnet_sett.emplace(i, std::to_string(i * 1000));

	std::cout << (const char*)u8"Skriver ut med enkel for løkke.\n";
	for (auto&[key, val] : uordnet_sett)
		std::cout << "Key: " << key << ' ' << "Value: " << val << std::endl;

	std::cout << "\nSkriver ut i samme rekkefølge som innsetting.\n";
	
	SkrivUtTestSet(uordnet_sett, 12, 13);
	SkrivUtTestSet(uordnet_sett, 20, 21);
	SkrivUtTestSet(uordnet_sett, 1, 6);
}