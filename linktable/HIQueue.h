#ifndef _LSH_QUEUE_H
#define _LSH_QUEUE_H

#include <assert.h>
#include <iostream>
#include <exception>

/* @brief 链表--头部插入法
*/
template<typename T>
class HIQueue
{
	using value_type = typename T;
	using reference = value_type&;
	using reference_const = const value_type&;
	using pointer = value_type*;
public:
	HIQueue();
	~HIQueue();

	template<typename Type>
	struct Node {
		inline Node<Type>(type _data) :data(_data), next(nullptr) {}
		Type data;
		Node<Type>* next;
	};

public:
	void push_back(const T& data);
	void push_front(const T& data);
	T pop_front();
	T pop_back();
	bool contain(T val);
	inline int count() {
		return _count;
	}
private:
	Node<T>* _headNode;
	int _count;
};

template<typename T>
T HIQueue<T>::pop_back()
{

}

template<typename T>
void HIQueue<T>::push_front(const T& data)
{
	Node<T>* nextNode = new Node<T>(data);
	nextNode->next = _headNode->next;
	_headNode->next = nextNode;
	_count++;
	std::cout << "lsh debug --- push_front pointer = " << nextNode << std::endl;
}

template<typename T>
inline HIQueue<T>::HIQueue()
{
	_headNode = new Node<T>(T(0));
	_count = 0;
}

template<typename T>
inline HIQueue<T>::~HIQueue()
{
	if (_headNode) {

		Node<T>* pMove = _headNode->next;
		while (pMove) {
			std::cout << "lsh debug --- ~pointer = " << pMove << std::endl;
			_headNode->next = pMove->next;
			delete pMove;
			pMove = _headNode->next;
		}

		delete _headNode;
		_headNode = nullptr;
	}
}

template<typename T>
inline void HIQueue<T>::push_back(const T& data)
{
	Node<T>* nextNode = new Node<T>(data);	
	_headNode->next = nextNode;	
	nextNode->next = _headNode->next;
}

template<typename T>
inline T HIQueue<T>::pop_front()
{
	Node<T>* curNode = _headNode->next;
	if (!curNode) {
		throw std::exception("there is no member in the queue! ");
	}
	T value = curNode->data;
	_headNode->next = curNode->next;
	std::cout << "lsh debug --- pop_front pointer = " << curNode << std::endl;
	delete curNode;
	_count--;
	return value;
}

template<typename T>
bool HIQueue<T>::contain(T val)
{
	Node<T>* pMove = _headNode->next;
	while (pMove)
	{
		if (pMove->data == val) {
			return true;
		}
		pMove = pMove->next;
	}
}

#endif // !_LSH_QUEUE_H
