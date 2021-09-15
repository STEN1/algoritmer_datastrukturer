#pragma once

#include <iostream>

template<typename T>
concept NodeType = requires(T nodeData)
{
	std::cout << nodeData;
	nodeData < nodeData;
	nodeData > nodeData;
	nodeData <= nodeData;
	nodeData >= nodeData;
};


template<NodeType T>
class BinaryNode
{
public:
	BinaryNode() = delete;
	BinaryNode(const T& data, BinaryNode* left = nullptr, BinaryNode* right = nullptr);
	const T& get() const;
	BinaryNode* find(const T& data) const;
	void insert(const T& data);
	void intrav() const;

	BinaryNode* left() const;
	BinaryNode* right() const;
private:

	T data_;
	BinaryNode* left_;
	BinaryNode* right_;
};

template<NodeType T>
inline BinaryNode<T>::BinaryNode(const T& data, BinaryNode* left, BinaryNode* right)
	:data_(data), left_(left), right_(right)
{
}

template<NodeType T>
inline const T& BinaryNode<T>::get() const
{
	return data_;
}

template<NodeType T>
inline BinaryNode<T>* BinaryNode<T>::find(const T& data) const
{
	if (data_ = data)
		return this;
	else if (data < data_ && left_ != nullptr)
		return left_->find(data);
	else if (right_)
		return right_->find(data);
	return nullptr;
}

template<NodeType T>
inline void BinaryNode<T>::insert(const T& data)
{
	if (data < data_)
	{
		if (left_)
			left_->insert(data);
		else
			left_ = new BinaryNode(data);
	}
	else if (data > data_)
	{
		if (right_)
			right_->insert(data);
		else
			right_ = new BinaryNode(data);
	}
}

template<NodeType T>
inline void BinaryNode<T>::intrav() const
{
	if (left_)
		left_->intrav();
	std::cout << data_;
	if (right_)
		right_->intrav();
}

template<NodeType T>
inline BinaryNode<T>* BinaryNode<T>::left() const
{
	return left_;
}

template<NodeType T>
inline BinaryNode<T>* BinaryNode<T>::right() const
{
	return right_;
}
