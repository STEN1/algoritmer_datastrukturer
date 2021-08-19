#include "charstack.h"

int ADS101::Stack::s_antall = 0;

ADS101::Stack::Stack()
:m_top(nullptr)
{
}

ADS101::Node* ADS101::Stack::top() const
{
	return m_top;
}

bool ADS101::Stack::empty()
{
	if (s_antall > 0)
	{
		return false;
	}
	return true;
}

int ADS101::Stack::size()
{
	return s_antall;
}

void ADS101::Stack::push(const char& data)
{
	if (m_top)
	{
		m_top = new Node(data, m_top);
	}
	else
	{
		m_top = new Node(data);
	}
	s_antall++;
}

void ADS101::Stack::pop()
{
	if (m_top)
	{
		Node* neste = m_top->hentNeste();
		delete m_top;
		m_top = neste;
		s_antall--;
	}
}
