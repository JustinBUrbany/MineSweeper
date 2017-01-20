#ifndef ARRAY2D_H
#define ARRAY2D_H
#include "Cell.h"
#include "Array.h"

template <typename T>
class Row;



template<typename T>
class Array2D
{
public:
	Array2D();
	Array2D(int row, int col);
	Array2D(const Array2D & copy);
	~Array2D();
	Array2D<T> & operator=(const Array2D & rhs);
	Row<T> operator[](int index);
	int getRow();
	void setRow(int rows);
	int getColumn();
	void setColumn(int columns);
	T & Select(int row, int column);

private:

	Array<T> m_array;
	int m_row;
	int m_col;
};

template<typename T>
Array2D<T>::Array2D() : m_row(0), m_col(0)
{
}

template<typename T>
Array2D<T>::Array2D(int row, int col) : m_row(row), m_col(col)
{
	if (row < 0 || col < 0)
		throw Exception("Invalid length or width");
	m_array.setLength(row*col);
}

template<typename T>
Array2D<T>::Array2D(const Array2D & copy) : m_row(0), m_col(0)
{
	if (copy.m_row < 0 || m_col < 0)
	{
		throw Exception("Invalid column or row length");
	}
	else
	{
		m_array = copy.m_array;
		m_row = copy.m_row;
		m_col = copy.m_col;
	}


}

template<typename T>
Array2D<T>::~Array2D()
{
	m_array.setLength(0);

	m_col = 0;
	m_row = 0;
}

template <typename T>
Array2D<T> & Array2D<T>::operator=(const Array2D & rhs)
{
	if (this != &rhs)
	{
		m_array = rhs.m_array;
		m_row = rhs.m_row;
		m_col = rhs.m_col;
	}
	return *this;
}

template <typename T>
Row<T> Array2D<T>::operator[](int index)
{
	//desired row *m_column + descired column
	//Row<T> row(*this, index); //gonna pass the desired rows to row
	//have a Row<T> with this current 2Darray and desired rows

	return Row<T>(*this, index);//got to return this Row<T> to the Row<T> operator to the
}

template <typename T>
int Array2D<T>::getRow()
{
	return m_row;
}

template <typename T>
int Array2D<T>::getColumn()
{
	return m_col;
}

template <typename T>
void Array2D<T>::setColumn(int column)
{
	if (column > 0)
	{
		Array<T> temp(column * m_row);

		int n = 0;
		for (int i = 0; i < m_row; ++i)
		{
			for (int j = 0; j < column && j< m_col; ++j)
			{
				temp[n] = m_array[i*m_col + j];
				n++;
			}
			if (column > m_col)
			{
				n += column - m_col;
			}
		}
		m_col = column;
		m_array = temp;

	}
	else
	{
		throw Exception("Can't have columns less then zero!");
	}

}

template <typename T>
void Array2D<T>::setRow(int Row)
{
	if (Row > 0)
	{
		m_row = Row;
		m_array.setLength(m_col*m_row);
	}
	else
	{
		throw Exception("Can't have rows less then zero!");
	}
}

template <typename T>
T & Array2D<T>::Select(int row, int column)
{
	return m_array[row*m_col + column];
}

#endif ARRAY2D_H
