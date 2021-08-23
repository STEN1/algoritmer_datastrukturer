#pragma once
#include <utility>

namespace ADS101
{
	class CharStack
	{
	public:
		CharStack(const int& maxDataSize);
		~CharStack();

		char top();

		bool empty() const;
		int size() const;

		void push(const char& data);
		void pop();

	private:
		char* m_data;
		const int m_maxDataSize;
		int m_top;
	};

	template<class T>
	class Stack
	{
	public:
		Stack(const int& maxDataSize);
		~Stack();

		T top();

		bool empty() const;
		int size() const;

		void push(T&& data);
		void pop();

	private:
		T* m_data;
		const int m_maxDataSize;
		int m_top;
	};

	template<class T>
	inline Stack<T>::Stack(const int& maxDataSize)
	:m_maxDataSize(maxDataSize)
	,m_top(-1)
	{
		m_data = new T[m_maxDataSize];
	}

	template<class T>
	inline ADS101::Stack<T>::~Stack()
	{
		delete[] m_data;
	}

	template<class T>
	inline T Stack<T>::top()
	{
		return m_data[m_top];
	}

	template<class T>
	inline bool Stack<T>::empty() const
	{
		if (m_top < 0)
		{
			return true;
		}
		return false;
	}

	template<class T>
	inline int Stack<T>::size() const
	{
		return m_top + 1;
	}

	template<class T>
	inline void Stack<T>::push(T&& data)
	{
		if ((m_top + 1) == m_maxDataSize)
		{
			return;
		}
		m_top++;
		m_data[m_top] = std::forward<T>(data);
	}

	template<class T>
	inline void Stack<T>::pop()
	{
		if (m_top > -1)
		{
			m_top--;
		}
	}
}