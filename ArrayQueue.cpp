#ifndef ARRAY_QUEUE_CPP_
#define ARRAY_QUEUE_CPP_

#include "ArrayQueue.h"

/*
Sean Fite
Data Structures
Assignment 5 
*/

template <class Type>							// default constructor
ArrayQueue<Type>::ArrayQueue(int capacity)
{
	_data = new Type[capacity];
	_size = 0;
	_capacity = capacity;
}

template <class Type>							// destructor
ArrayQueue<Type>::~ArrayQueue()
{
	delete[] _data;
}

template <class Type>							// if size of queue = capacitiy return true
bool ArrayQueue<Type>::is_full() const
{
	return _size == _capacity;
}

template <class Type>							// if queue is empty return true
bool ArrayQueue<Type>::is_empty() const
{
	return _size == 0;
}

template <class Type>
Type &ArrayQueue<Type>::peek() const			// peak at front of queue
{
	if (_size == 0)
	{
		throw logic_error("the queue is empty");
	}
	else
	{
		return _data[0];
	}
}

template <class Type>							// add value to back of queue
bool ArrayQueue<Type>::enqueue(const Type &item)
{
	if (_size == _capacity)
	{
		return false;
	}
	else
	{
		_data[_size] = item;
		_size++;
		return true;
	}
}

template <class Type>							// remove front of queue, shift elements to right, subtract size
bool ArrayQueue<Type>::dequeue()
{
	if (_size == 0)
	{
		return false;
	}
	for (int i = 0; i < _size; i++)
	{
		_data[i] = _data[i + 1];
	}
	_size--;
	return true;
}

template <class Type>							// print queue
void ArrayQueue<Type>::print()
{
	for (int index = 0; index < _size - 1; index++)
		cout << _data[index] << endl;
}

#endif /* ARRAY_QUEUE_CPP_ */
