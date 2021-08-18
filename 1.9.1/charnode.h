#pragma once

#include <string>
#include <list>

namespace ASD101
{
	class CharNode
	{
	public:
		CharNode(char tegn = '0', CharNode* neste = nullptr);
		~CharNode();

		std::string toString() const;
		CharNode* hentNeste() const ;
		void skrivBaklengs() const;
		static int hentAntall();
		char hentData();

		void push(char tegn);
		void pop(CharNode*& node);
		char top();
		int size();
		void empty(CharNode*& node);

	private:
		char m_tegn;
		static int s_antall;
		CharNode* m_neste;
	};
}