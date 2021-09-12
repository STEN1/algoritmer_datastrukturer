#include "queue.h"
#include <iostream>

ADS101::CharQueue::CharQueue(const int& queueMaxSize)
:m_dataSize(queueMaxSize)
,m_back(0)
,m_front(0)
,m_size(0)
{
	m_data = new char[m_dataSize];
}

ADS101::CharQueue::~CharQueue()
{
	delete[] m_data;
}

void ADS101::CharQueue::push(const char& data)
{
	if (m_size == m_dataSize)
	{
		pop();
	}
	if (m_back == m_dataSize)
	{
		m_back = 0;
	}
	m_data[m_back] = data;
	m_back++;
	m_size++;
}

char ADS101::CharQueue::front() const
{
	return m_data[m_front];
}

void ADS101::CharQueue::pop()
{
	if (m_size == 0)
	{
		return;
	}
	m_front++;
	if (m_front == m_dataSize)
	{
		m_front = 0;
	}
	m_size--;
}

int ADS101::CharQueue::size() const
{
	return m_size;
}
