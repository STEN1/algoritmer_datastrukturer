#include "stack.h"

ADS101::CharStack::CharStack(const int& maxDataSize)
:m_maxDataSize(maxDataSize)
,m_top(-1)
{
	m_data = new char[m_maxDataSize];
}

ADS101::CharStack::~CharStack()
{
	delete[] m_data;
}

char ADS101::CharStack::top()
{
	return m_data[m_top];
}

bool ADS101::CharStack::empty() const
{
	if (m_top < 0)
	{
		return true;
	}
	return false;
}

int ADS101::CharStack::size() const
{
	return m_top + 1;
}

void ADS101::CharStack::push(const char& data)
{
	if ((m_top + 1) == m_maxDataSize)
	{
		return;
	}
	m_top++;
	m_data[m_top] = data;
}

void ADS101::CharStack::pop()
{
	if (m_top > -1)
	{
		m_top--;
	}
}
