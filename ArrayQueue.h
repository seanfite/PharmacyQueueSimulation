#ifndef ARRAY_QUEUE_H_
#define ARRAY_QUEUE_H_

#include <iostream>
using namespace std;

template<class Type>
class ArrayQueue
{
	//private: 
	public:
		int _capacity = 20;
		int _size;
		Type *_data;

	public:
		ArrayQueue(int capacity = 20);
		~ArrayQueue();

		bool is_full() const;
		bool is_empty() const;
		Type &peek() const;
		bool enqueue(const Type &item);
		bool dequeue();
		void print();
};

#include "ArrayQueue.cpp"
#endif /* ARRAY_QUEUE_H_ */