#pragma once
#include <iostream>

namespace ADS101
{
	class CharQueue
	{
	public:
		CharQueue(const int& queueMaxSize);
		~CharQueue();
		void push(const char& data);
		char front() const;
		void pop();
		int size() const;

	private:
		char* m_data;
		const int m_dataSize;
		int m_front;
		int m_back;
		int m_size;
	};

	template<class T>
	class Queue
	{
	public:
		Queue(const int& queueMaxSize);
		~Queue();
		void push(T&& data) noexcept;
		T front() const;
		void pop();
		int size() const;

	private:
		T* m_data;
		const int m_dataSize;
		int m_front;
		int m_back;
		int m_size;
	};
	template<class T>
	inline Queue<T>::Queue(const int& queueMaxSize)
	:m_dataSize(queueMaxSize)
	,m_back(0)
	,m_front(0)
	,m_size(0)
	{
		m_data = new T[m_dataSize];
	}
	template<class T>
	inline Queue<T>::~Queue()
	{
		delete[] m_data;
	}
	template<class T>
	inline void Queue<T>::push(T&& data) noexcept
	{
		if (m_size == m_dataSize)
		{
			std::cout << "m_size >= m_dataSize " << std::forward<T>(data) << " not added" << std::endl;
			return;
		}
		if (m_back == m_dataSize)
		{
			m_back = 0;
		}
		m_data[m_back] = std::forward<T>(data);
		m_back++;
		m_size++;
	}
	template<class T>
	inline T Queue<T>::front() const
	{
		return m_data[m_front];;
	}
	template<class T>
	inline void Queue<T>::pop()
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
	template<class T>
	inline int Queue<T>::size() const
	{
		return m_size;
	}
}