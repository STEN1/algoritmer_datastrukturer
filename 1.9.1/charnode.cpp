#include "charnode.h"
#include <sstream>
#include <iostream>

int ASD101::CharNode::s_antall = 0;

ASD101::CharNode::CharNode(char tegn, CharNode* neste)
:m_tegn(tegn)
,m_neste(neste)
{
	s_antall++;
}

ASD101::CharNode::~CharNode()
{
	s_antall--;
}

std::string ASD101::CharNode::toString() const
{
	std::ostringstream ss;
	ss << m_tegn;
	return ss.str();
}

ASD101::CharNode* ASD101::CharNode::hentNeste() const
{
	return m_neste;
}

void ASD101::CharNode::skrivBaklengs() const
{
	if (m_neste)
	{
		m_neste->skrivBaklengs();
	}
	std::cout << m_tegn;
}

int ASD101::CharNode::hentAntall()
{
	return s_antall;
}

char ASD101::CharNode::hentData()
{
	return m_tegn;
}

void ASD101::CharNode::push(char tegn)
{
	m_neste = new CharNode(m_tegn, m_neste);
	m_tegn = tegn;
}

void ASD101::CharNode::pop(CharNode*& node)
{
	if (m_neste)
	{
		m_tegn = m_neste->m_tegn;
		CharNode* neste = m_neste->m_neste;
		delete m_neste;
		m_neste = neste;
	}
	else
	{
		node = nullptr;
		std::cout << "node = nullptr" << std::endl;
		delete this;
	}
}

char ASD101::CharNode::top()
{
	return hentData();
}

int ASD101::CharNode::size()
{
	return hentAntall();
}

void ASD101::CharNode::empty(CharNode*& node)
{
	if (!m_neste)
	{
		delete this;
		node = nullptr;
		std::cout << "node = nullptr" << std::endl;
		return;
	}
	m_neste->empty(node);

	delete this;
}

