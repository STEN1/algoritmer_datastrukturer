#pragma once
#include "node.h"

namespace ADS101
{
	template<class T>
	class Stack
	{
	public:
		Stack()
		:m_top(nullptr)
		{
		}

		// access
		Node<T>* top() const { return m_top; };
		// capacity
		bool empty()
		{
			if (s_size > 0)
			{
				return false;
			}
			return true;
		}
		int size() { return s_size; }
		// modifiers
		void push(T&& data) noexcept
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
		void pop()
		{
			if (m_top)
			{
				auto newTop = m_top->m_next;
				delete m_top;
				m_top = newTop;
				s_size--;
			}
		}

	private:
		Node<T>* m_top;
		static int s_size;
	};

	template<class T>
	int ADS101::Stack<T>::s_size = 0;
}