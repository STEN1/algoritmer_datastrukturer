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
	int size() const;
	int depth() const;
	int not_cursed_depth() const;
	int not_cursed_size() const;
	void insert(const T& data);
	void intrav() const;
	void postorder() const;

	BinaryNode* left() const;
	BinaryNode* right() const;
private:
	void rek_size(int& size) const;
	void rek_depth(int* arr, int& index, const int& depth) const;

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
inline void BinaryNode<T>::postorder() const
{
	if (left_)
		left_->postorder();
	if (right_)
		right_->postorder();
	std::cout << data_;
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

template<NodeType T>
inline int BinaryNode<T>::size() const
{
	int size{ 1 };

	if (left_)
		left_->rek_size(size);
	if (right_)
		right_->rek_size(size);

	return size;
}

template<NodeType T>
inline void BinaryNode<T>::rek_size(int& size) const
{
	size++;
	if (left_)
		left_->rek_size(size);
	if (right_)
		right_->rek_size(size);
}

template<NodeType T>
inline int BinaryNode<T>::depth() const
{
	const auto N = size();
	int* arr = new int[N]; // worst case så er dybden lik størrelsen
	int index{};
	rek_depth(arr, index, -1);
	int deepest{};
	for (int i = 0; i < index; i++)
		if (arr[i] > deepest)
			deepest = arr[i];
	delete[] arr;
	return deepest;
}

template<NodeType T>
inline void BinaryNode<T>::rek_depth(int* arr, int& index, const int& depth) const
{
	
	if (left_ && right_)
	{
		left_->rek_depth(arr, index, depth + 1);
		right_->rek_depth(arr, index, depth + 1);
	}
	else if (left_)
		left_->rek_depth(arr, index, depth + 1);
	else if (right_)
		right_->rek_depth(arr, index, depth + 1);
	else
	{
		arr[index] = depth + 1;
		index++;
	}
}

template<NodeType T>
inline int BinaryNode<T>::not_cursed_depth() const
{
	int left_depth{};
	int right_depth{};

	if (left_)
		left_depth = 1 + left_->not_cursed_depth();
	if (right_)
		right_depth = 1 + right_->not_cursed_depth();

	if (left_depth > right_depth)
		return left_depth;
	else 
		return right_depth;
}

template<NodeType T>
inline int BinaryNode<T>::not_cursed_size() const
{
	if (left_ && right_)
		return 1 + left_->not_cursed_size() + right_->not_cursed_size();
	else if (left_)
		return 1 + left_->not_cursed_size();
	else if (right_)
		return 1 + right_->not_cursed_size();
	return 1;
}