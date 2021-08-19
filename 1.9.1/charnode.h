#pragma once

#include <string>
// hmm
namespace ADS101
{
	class Node
	{
	public:
		Node(char tegn = '0', Node* neste = nullptr);
		~Node();

		std::string toString() const;
		Node* hentNeste() const;
		void skrivBaklengs() const;
		static int hentAntall();
		char hentData() const;

	private:
		char m_tegn;
		static int s_antall;
		Node* m_neste;
	};
}