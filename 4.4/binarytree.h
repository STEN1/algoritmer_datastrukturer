#pragma once

template<class T>
class BinaryNode
{
public:
	BinaryNode() = delete;
	BinaryNode(const T& data, BinaryNode* left = nullptr, BinaryNode* right = nullptr);
	T& get() const;
	void print() const;
	BinaryNode* find(const T& data) const;
	void insert(const T& data);
	void intrav();

	T data_;
	BinaryNode* left_;
	BinaryNode* right_;
};

template<class T>
inline BinaryNode<T>::BinaryNode(const T& data, BinaryNode* left, BinaryNode* right)
	:data_(data), left_(left), right_(right)
{
}

template<class T>
inline T& BinaryNode<T>::get() const
{
	return data_;
}

template<class T>
inline void BinaryNode<T>::print() const
{
}

template<class T>
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

template<class T>
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

template<class T>
inline void BinaryNode<T>::intrav()
{
}