#pragma once

#include <string>
#include <utility>

// hmm 2
namespace ADS101
{
	template<class T>
	class Node
	{
	public:
		Node(T&& data, Node<T>* next = nullptr)
		:m_data(std::forward<T>(data))
		,m_next(next)
		{
		}

		T get() { return m_data; }

	private:
		template<class T>
		friend class Stack;
		T m_data;
		Node<T>* m_next;
	};
}