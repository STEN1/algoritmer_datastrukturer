#pragma once

#include <cstdint>
#include <queue>

template<class T>
class Heap
{
private:
	struct Node
	{
		Node* left_;
		Node* right_;
		Node* parent_;
		T data_;
		Node(const T& _data, Node* _parent) : data_(_data), parent_(_parent), left_(nullptr), right_(nullptr) {}
	};
public:
	Heap() = default;
	~Heap();

public:
	T& top() const;
	bool empty() const;
	uint64_t size() const;
	void push(const T& _data);
	void pop();
private:
	Node* top_ = nullptr;
	uint64_t size_ = 0;
	void perlocate(Node* _node);
};

template<class T>
inline Heap<T>::~Heap()
{
	while (!empty())
	{
		pop();
	}
}

template<class T>
inline T& Heap<T>::top() const
{
	return top_->data_;
}

template<class T>
inline bool Heap<T>::empty() const
{
	if (size_ > 0)
	{
		return false;
	}
	return true;
}

template<class T>
inline uint64_t Heap<T>::size() const
{
	return size_;
}

template<class T>
inline void Heap<T>::push(const T& _data)
{
	if (!top_)
	{
		top_ = new Node(_data, nullptr);
		size_++;
		return;
	}
	else
	{
		std::queue<Node*> q;
		q.push(top_);

		while (!q.empty())
		{
			if (!q.front()->left_)
			{
				q.front()->left_ = new Node(_data, q.front());
				perlocate(q.front()->left_);
				size_++;
				return;
			}
			else
			{
				q.push(q.front()->left_);
			}
			if (!q.front()->right_)
			{
				q.front()->right_ = new Node(_data, q.front());
				size_++;
				perlocate(q.front()->right_);
				return;
			}
			else
			{
				q.push(q.front()->right_);
			}
			q.pop();
		}
	}
}

template<class T>
inline void Heap<T>::pop()
{
	
	size_--;
}

template<class T>
inline void Heap<T>::perlocate(Node* _node)
{
	if (!_node->parent_ )
	{
		top_ = _node;
		return;
	}
	if (_node->parent_->data_ < _node->data_)
	{
		auto child_left = _node->left_;
		auto child_right = _node->right_;
		auto parent = _node->parent_;

		// move child node up to parent pos in tree
		if (_node == parent->left_)
			_node->left_ = parent;
		else
			_node->left_ = parent->left_;

		if (_node == parent->right_)
			_node->right_ = parent; 
		else
			_node->right_ = parent->right_;

		_node->parent_ = parent->parent_;

		// move parent down in tree
		parent->left_ = child_left;
		parent->right_ = child_right;
		parent->parent_ = _node;

		perlocate(_node);
	}
}
