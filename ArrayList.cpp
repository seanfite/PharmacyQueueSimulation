#ifndef ARRAY_LIST_CPP_
#define ARRAY_LIST_CPP_

#include "ArrayList.h"

/*
Sean Fite
Data Structures
Assignment 5
*/

template <class Type>
ArrayList<Type>::ArrayList()                        // default constructor initializing values
{
    _size = 0;
    _capacity = 20;
    _data = new Type[_capacity];
}

template <class Type>                               // destructor
ArrayList<Type>::~ArrayList()
{
    delete[] _data;
}

template <class Type>                               // return size of list
int ArrayList<Type>::size() const
{
    return _size;
}

template <class Type>                               // expand capacity of list
void ArrayList<Type>::expand()
{
    _capacity *= 2;
    Type *temp = new Type[_capacity];
    for (int i = 0; i < _size; i++)
    {
        temp[i] = _data[i];
    }
    delete[] _data;
    _data = temp;
}

template <class Type>                               // insert values into list
void ArrayList<Type>::insert(const Type &item)
{
    if (_size - 1 == _capacity)
    {
        expand();
    }
    _data[_size] = item;
    _size++;
}

template <class Type>                               // remove at index of list
bool ArrayList<Type>::removeAt(int index)
{
    if (index > _size)                              // if index is larger than size throw error
    {
        throw logic_error("the index is out of bound");
    }
    int i;
    for (i = 0; i < _size; i++)                     // set i to index
    {
        if (i == index)
        {
            break;
        }
    }
    if (i == _size)                                 // return false if size = i
    {
        return false;
    }
    else
    {
        for (; i < _size; i++)
        {
            _data[i] = _data[i + 1];                // move values of list to the right
        }
        _size--;
        return true;
    }
}

template <class Type>
void ArrayList<Type>::sort()                        // bubble sort
{
    if (_size < 2)                                  // if list size is less than 2 sort is not necessary
    {
        return;
    }
    int i, j;
    for (i = 0; i < _size - 1; i++)                
    {
        bool is_sorted = 1;
        for (int j = 0; j < _size - i - 1; j++)     // nested loop to iterate list sort values
        {
            if (_data[j + 1] < _data[j])
            {
                Type temp = _data[j];
                _data[j] = _data[j + 1];
                _data[j + 1] = temp;
                is_sorted = 0;
            }
        }
        if (is_sorted)
            break;
    }
}

template <class Type>                               // get value at index
Type &ArrayList<Type>::get(int index)
{
    if (index >= _size || index < 0)
    {
        throw logic_error("the index is out of bound");
    }
    return _data[index];
}

template <class Type>                               // print list
void ArrayList<Type>::print()
{
    for (int index = 0; index < _size; index++)
        cout << _data[index] << endl;
}

#endif /* ARRAY_LIST_CPP_ */