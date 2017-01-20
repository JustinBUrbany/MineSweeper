#ifndef ROW_H
#define ROW_H

template<typename T>
class Array2D;

template<typename T>
class Row
{
public:
	Row(Array2D<T> & array, int row);
	T & operator [](int column);
private:
	Array2D<T> & m_array2D;
	int m_row;

};

template<typename T>
Row<T>::Row(Array2D<T> & array, int row) : m_array2D(array), m_row(row) //row is the desired row
{}

template<typename T>
T &  Row<T>::operator[](int column)
{

	return m_array2D.Select(m_row, column);

}

#endif
