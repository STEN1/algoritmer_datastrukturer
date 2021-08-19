#include "node.h"
#include <sstream>
#include <iostream>

int ADS101::Node::s_antall = 0;

ADS101::Node::Node(char tegn, Node* neste)
:m_tegn(tegn)
,m_neste(neste)
{
	s_antall++;
}

ADS101::Node::~Node()
{
	s_antall--;
}

std::string ADS101::Node::toString() const
{
	std::ostringstream ss;
	ss << m_tegn;
	return ss.str();
}

ADS101::Node* ADS101::Node::hentNeste() const
{
	return m_neste;
}

void ADS101::Node::skrivBaklengs() const
{
	if (m_neste)
	{
		m_neste->skrivBaklengs();
	}
	std::cout << m_tegn;
}

int ADS101::Node::hentAntall()
{
	return s_antall;
}

char ADS101::Node::hentData() const
{
	return m_tegn;
}

