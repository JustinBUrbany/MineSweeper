#ifndef ARRAY_H
#define ARRAY_H
#include "Cell.h"

class Cell;

template<typename T>
class Array
{
public:

	Array();
	Array(int length, int start_index = 0);
	Array(const Array & copy);
	~Array();
	Array & operator =(const Array & rhs);
	T & operator [](int index);
	int getStartIndex()const;
	void setStartIndex(int start_index);
	int getLength()const;
	void setLength(int length);

private:
	T * m_array;
	int m_length;
	int m_start_index;
};

template<typename T>
Array<T>::Array() :m_array(nullptr), m_length(0), m_start_index(0)
{
}

template<typename T>
Array<T>::Array(int length, int start_index) : m_array(nullptr), m_length(length), m_start_index(start_index)
{
	if (length < 0) //can't have a length less then zero
	{
		throw Exception("Trying to make an array with a negative length!");
	}
	m_array = new T[length];//create a new length for m_array
}
template<typename T>
Array<T>::Array(const Array & copy) : m_array(nullptr), m_length(0), m_start_index(0)
{
	m_length = copy.m_length; // Set m_length to the copies length
	m_start_index = copy.m_start_index; //change the start_index to the copies start_index
	if (copy.m_array != nullptr) //if copies m_array is not nullptr 
	{
		m_array = new T[copy.m_length]; //Set the new size of m_array
		for (int i = getStartIndex(); i < getLength(); ++i) //for the whole length of the array
		{
			m_array[i] = copy.m_array[i]; //copy over each part of the array
		}
	}
}
template<typename T>
Array<T>::~Array()
{
	delete[] m_array; //delete m_array
	m_array = nullptr; //set to nullptr
	m_length = 0; //set the length to zero
	m_start_index = 0; //set start_index back to zero
}
template<typename T>
Array<T> & Array<T>::operator=(const Array & rhs)
{
	if (this != &rhs) //check for self assignment
	{
		delete[] m_array; //if not self assignment delete orginal
		m_array = nullptr; //set to null
		m_length = 0; //reset length
		m_start_index = 0; //reset the start_index

		if (rhs.m_array != nullptr) //if right hand side is not nullptr
		{
			m_length = rhs.m_length; //assign left length with rhs length
			m_start_index = rhs.m_start_index; //assign the start index
			m_array = new T[m_length]; // create array with the new length
			for (int i = getStartIndex(); i < getLength(); ++i)
			{
				m_array[i] = rhs.m_array[i]; //for each element copy  them over
			}
		}
	}

	return *this;
}
template<typename T>
T & Array<T>::operator[](int index)
{
	index = index - m_start_index; // if you want to make sure its in bounds you have to adjust the new index so that it works with your length

	if (index >= m_length)  //if index is out of bounds the big way 
	{
		throw Exception("You're out of bounds of your array!");
	}
	if (index<0) //if index is out of bounds the small way
	{
		throw Exception("You're out of bounds of your array!");
	}

	return m_array[index];  //return the element in that index
}
template<typename T>
int Array<T>::getStartIndex() const
{
	return m_start_index;
}
template<class T>
void Array<T>::setStartIndex(int start_index)
{
	m_start_index = start_index;
}

template<typename T>
int Array<T>::getLength() const
{
	return m_length;
}

template<typename T>
void Array<T>::setLength(int length)
{
	if (length < 0)//if the length is less then 0 throw exception
	{
		throw Exception("Can't have array length less then zero!");
	}
	else
	{
		int len = 0;  // create an int
		T * temp = new T[length];//set new
		if (m_length < length)
		{
			len = m_length; //if new length is greater then old length set len to old

		}
		else
		{
			len = length;//if new length is less then old length set to new length
		}
		for (int i = 0; i < len; ++i)
		{
			temp[i] = m_array[i];//copy old into the new plus more or less depending on the length
		}

		delete[]m_array;//delete
		m_array = nullptr; // set to nullptr

		m_length = length; //set the new m_length
		if (m_length > 0) //if length >0 then you have to resize your array
		{
			m_array = new T[m_length]; //resize the array
			for (int i = 0; i < m_length; i++) //for the length of the new array copy back into the orginal m_array
			{
				m_array[i] = temp[i];
			}
		}
		delete[]temp;

	}
}

#endif
