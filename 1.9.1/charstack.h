#pragma once
#include "charnode.h"

namespace ADS101
{
	class Stack
	{
	public:
		Stack();

		// access
		Node* top() const;
		// capacity
		bool empty();
		int size();
		// modifiers
		void push(const char& data);
		void pop();

	private:
		ADS101::Node* m_top;
		static int s_antall;
	};
}