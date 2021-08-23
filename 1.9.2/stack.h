#pragma once
#include "node.h"

namespace ADS101
{
	template<class T>
	class Stack
	{
	public:
		Stack();
		~Stack();
		T top() const;
		bool empty() const;
		int size();
		void push(T&& data) noexcept;
		void pop();

	private:
		Node<T>* m_top;
		static int s_size;
	};

	template<class T>
	int ADS101::Stack<T>::s_size = 0;

	template<class T>
	inline Stack<T>::Stack()
	:m_top(nullptr)
	{
	}

	template<class T>
	inline Stack<T>::~Stack()
	{
		while (m_top)
		{
			pop();
		}
	}

	template<class T>
	inline T Stack<T>::top() const
	{
		return m_top->get();
	}

	template<class T>
	inline bool Stack<T>::empty() const
	{
		if (s_size > 0)
		{
			return false;
		}
		return true;
	}

	template<class T>
	inline int Stack<T>::size()
	{
		return s_size;
	}

	template<class T>
	inline void Stack<T>::push(T&& data) noexcept
	{
		if (m_top)
		{
			m_top = new Node<T>(std::forward<T>(data), m_top);
			s_size++;
		}
		else
		{
			m_top = new Node<T>(std::forward<T>(data));
			s_size++;
		}
	}

	template<class T>
	inline void Stack<T>::pop()
	{
		if (m_top)
		{
			auto newTop = m_top->m_next;
			delete m_top;
			m_top = newTop;
			s_size--;
		}
	}
}