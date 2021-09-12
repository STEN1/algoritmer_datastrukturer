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
		Node(T&& data, Node<T>* next = nullptr);
		Node(const T& data, Node<T>* next = nullptr);

	private:
		template<class T>
		friend class Stack;
		T m_data;
		Node<T>* m_next;
	};

	template<class T>
	inline Node<T>::Node(T&& data, Node<T>* next)
		:m_data(std::move(data))
		,m_next(next)
	{
	}

	template<class T>
	inline Node<T>::Node(const T& data, Node<T>* next)
		:m_data(data)
		,m_next(next)
	{
	}
}