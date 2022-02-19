#include "MyArray.h"
#include <iostream>
using namespace std;
template <class T>
MyArray< T>::MyArray() {
	data = new T[INITIAL_CAPACITY];  
}

template <class T>
MyArray<T>::MyArray(T arr[], int size) 
{
	while (size > capacity)   // check if size > initial capacity
	{ 
		capacity *= 2;
	}
	data = new T[capacity];
	this->size = size;
	for (int i = 0; i < size; i++)
	{
		data[i] = arr[i];
	}
}

template<class T>
T MyArray<T>::get(int index)
{
	if (index < 0 || index >= size)  // invalid index
		return -1;
	return data[index];
}

template <class T>
void MyArray<T>::push(T element)  // pushing back
{
	if (size == capacity)
	{
		Duplicate();
		data[size++] = element;
	}
	else
	{
		data[size++] = element;
	}
}

template <class T>
void MyArray<T>::print()  // printing elements 
{
	for (int i = 0; i < size; i++)
		cout << data[i] << " ";
	cout << endl;
}


template <class T>
int MyArray<T>::get_capacity()
{
	return capacity;
}

template <class T>
void MyArray<T>::Duplicate() // for expansion
{
	capacity *= 2;
	T* newArray = new T[capacity];  
	for (int i = 0; i < size; i++)
	{
		newArray[i] = data[i];
	}
	delete[]data;   // deleting the old array from the memory after we copied them in the newArray
	data = newArray;
	newArray = nullptr;
}

template <class T>
T MyArray<T>::pop() {
	if (size == 0) // failed operation
		return -1;
	size--;
	T deletedElem = data[size]; 

	if (size <= capacity / 4)  // for shrinkage
	{
		T* ptr;
		capacity /= 2;
		ptr = new T[capacity];
		for (int i = 0; i < size; i++)
			ptr[i] = data[i];
		delete[]data;
		data = ptr;
		ptr = nullptr;
	}
	return deletedElem;
}


template <class T>
void MyArray<T>::insert(int index, T element)
{
	if (index<0 || index>size)  // failed operation (invalid index)
	{
		return;
	}
	if (size == capacity)
		Duplicate();

	if (index == size)  
	{
		push(element);
		return;
	}
	for (int i = size; i > index; i--)  // shifting all elements from the index to last element
		data[i] = data[i - 1];
	data[index] = element;
	size++;
}

template <class T>
T MyArray<T>::remove(int index)  // removing from a specific position
{
	if (index < 0 || index >= size)  // invalid index
		return -1;
	T deletedElement;
	deletedElement = data[index];
	if (index == size - 1)  // if the user want to delete the an element but he didn't know that it's the last one
	{
		return pop(); ;
	}
	size--;

	
	if (size <= capacity / 4)/*shrinkage and deleting the element at the same time to improve the time complexity*/
		                    // that's better than shrinkage then deleting then shifting the elements (that's if we will shrinkage the size)		                       
	{
		capacity /= 2;
		T* ptr = new T[capacity];
		for (int i = 0; i < index; i++)
			ptr[i] = data[i];
		for (int i = index; i < size; i++)
			ptr[i] = data[i + 1];
		delete[]data;
		data = ptr;
		ptr = nullptr;
		return deletedElement;
	}
	for (int i = index; i < size; i++) 
		data[i] = data[i + 1];
	return deletedElement;
}

template <class T>
int MyArray<T>::get_size() 
{
	return size;
}

template <class T>
MyArray<T>::~MyArray()  // destructor to free the memory
{
	delete[]data;
}