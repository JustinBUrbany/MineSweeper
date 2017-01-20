#include "Board.h"
#include "Row.h"
#include "windows.h"


Board::Board()
{
}

Board::Board(char level)
{
	if (level == 'b')
	{
		create_beg_board();
		
	}
	else if (level == 'i')
	{
		create_inter_board();
	}
	else
	{
		create_exprt_board();
	}
}

void Board::populate_board(int bombs, int length, int height)
{
	int count = 0;
	int x = 0;
	int y = 0;
	srand(0);
	while (count < bombs)
	{
		x = rand() % (length-1); //x is the row so take a random number then modulous
		//it by the length-1 so that you always get a value inbounds of your 2D array
		y = rand() % (height-1);
		if (m_Board[x][y]->getValue() != 'B')
		{
			m_Board[x][y]->setValue() = 'B';
			++count;
		}
	}
	for (int i = 1; i < length-1; ++i) //set values for all the insides squares
	{
		for (int j = 1; j < height-1; ++j)
		{
			if(m_Board[i][j]->getValue()!='B')
			{
				count = 0;
				if (m_Board[i - 1][j - 1]->getValue() == 'B')
					++count;
				if (m_Board[i][j - 1]->getValue() == 'B')
					++count;
				if (m_Board[i + 1][j - 1]->getValue() == 'B')
					++count;
				if (m_Board[i - 1][j]->getValue() == 'B')
					++count;
				if (m_Board[i + 1][j]->getValue() == 'B')
					++count;
				if (m_Board[i - 1][j + 1]->getValue() == 'B')
					++count;
				if (m_Board[i][j + 1]->getValue() == 'B')
					++count;
				if (m_Board[i + 1][j + 1]->getValue() == 'B')
					++count;
				count += 0x30; // add 0x30 to get ascii value for the integer
				m_Board[i][j]->setValue(static_cast<char>(count)); //cast the int so that it will have same value as a char
			}
			m_Board[i][j]->setState = '?';
		}
	}
	//All edge rows


	for (int i = 1; i < height - 1; ++i) // first column without corners
	{
		count = 0;
		if (m_Board[i][0]->getValue() != 'B')
		{
			if (m_Board[i-1][0]->getValue() == 'B')
				++count;
			if (m_Board[i - 1][1]->getValue() == 'B')
				++count;
			if (m_Board[i][1]->getValue() == 'B')
				++count;
			if (m_Board[i + 1][0]->getValue() == 'B')
				++count;
			if (m_Board[i + 1][1]->getValue() == 'B')
				++count;
			count += 0x30; // add 0x30 to get ascii value for the integer
			m_Board[i][0]->setValue(static_cast<char>(count)); //cast the int so that it will have same value as a char
		}
		m_Board[i][0]->setState = '?';
	}
	for (int j = height - 1; j < length - 1; ++j) // first row without corners
	{
		count = 0;
		if (m_Board[0][j]->getValue() != 'B')
		{
			if (m_Board[0][j - 1]->getValue() == 'B')
				++count;
			if (m_Board[1][j - 1]->getValue() == 'B')
				++count;
			if (m_Board[1][j]->getValue() == 'B')
				++count;
			if (m_Board[0][j + 1]->getValue() == 'B')
				++count;
			if (m_Board[1][j + 1]->getValue() == 'B')
				++count;
			count += 0x30; // add 0x30 to get ascii value for the integer
			m_Board[0][j]->setValue(static_cast<char>(count)); //cast the int so that it will have same value as a char
		}
		m_Board[0][j]->setState = '?';
	}

	for (int i = 1; i < height - 1; ++i) // last column
	{
		count = 0;
		if (m_Board[i][length - 1]->getValue() != 'B')
		{
			if (m_Board[i - 1][length - 1]->getValue() == 'B')
				++count;
			if (m_Board[i - 1][length - 2]->getValue() == 'B')
				++count;
			if (m_Board[i][length - 2]->getValue() == 'B')
				++count;
			if (m_Board[i + 1][length - 2]->getValue() == 'B')
				++count;
			if (m_Board[i + 1][length - 1]->getValue() == 'B')
				++count;
			count += 0x30; // add 0x30 to get ascii value for the integer
			m_Board[i][length - 1]->setValue(static_cast<char>(count)); //cast the int so that it will have same value as a char
		}
		m_Board[i][length - 1]->setState = '?';
	}
	for (int j = 1; j < length - 1; ++j) //last row
	{
		count = 0;
		if (m_Board[0][j]->getValue() != 'B')
		{
			if (m_Board[height - 1][j - 1]->getValue() == 'B')
				++count;
			if (m_Board[height - 2][j - 1]->getValue() == 'B')
				++count;
			if (m_Board[height - 2][j]->getValue() == 'B')
				++count;
			if (m_Board[height - 2][j + 1]->getValue() == 'B')
				++count;
			if (m_Board[height - 1][j + 1]->getValue() == 'B')
				++count;
			count += 0x30; // add 0x30 to get ascii value for the integer
			m_Board[0][j]->setValue(static_cast<char>(count)); //cast the int so that it will have same value as a char
		}
		m_Board[0][j]->setState = '?';
	}
	
	//set corners
	count = 0;
	if (m_Board[0][0]->getValue() != 'B')
	{
		if (m_Board[0][1]->getValue() == 'B')
			count++;
		if (m_Board[1][0]->getValue() == 'B')
			count++;
		if (m_Board[1][1]->getValue() == 'B')
			count++;
		count += 0x30;
		m_Board[0][0]->setValue(static_cast<char>(count)); //cast the int so that it will have same value as a char
	}
	m_Board[0][0]->setState = '?';

	count = 0;
	if (m_Board[0][length - 1]->getValue() != 'B')
	{
		if (m_Board[0][length - 2]->getvalue() == 'B')
			count++;
		if (m_Board[1][length - 2]->getvalue() == 'B')
			count++;
		if (m_Board[1][length - 1]->getvalue() == 'B')
			count++;
		count += 0x30;
		m_Board[0][length-1]->setValue(static_cast<char>(count)); //cast the int so that it will have same value as a char
	}
	m_Board[0][length - 1]->setState = '?';

	count = 0;
	if (m_Board[height - 1][0]->getValue() != 'B')
	{
		if (m_Board[height - 2][0]->getValue() == 'B')
			count++;
		if (m_Board[height - 2][1]->getValue() == 'B')
			count++;
		if (m_Board[height - 1][1]->getValue() == 'B')
			count++;
		count += 0x30;
		m_Board[height-1][0]->setValue(static_cast<char>(count)); //cast the int so that it will have same value as a char
	}
	m_Board[height - 1][0]->setState = '?';
	
	count = 0;
	if (m_Board[height - 1][length - 1]->getValue() != 'B')
	{
		if (m_Board[height - 2][length - 1]->getValue() == 'B')
			count++;
		if (m_Board[height - 1][length = 2]->getValue() == 'B')
			count++;
		if (m_Board[height - 2][length - 2]->getValue() == 'B')
			count++;
		count += 0x30;
		m_Board[height - 1][length - 1]->setValue(static_cast<char>(count));
	}
	m_Board[height - 1][length - 1]->setState = '?';
}

void Board::create_beg_board()
{
	m_Board = new Array2D<Cell>(10, 10);
	populate_board(10,10,10);

}

void Board::create_inter_board()
{
	m_Board = new Array2D<Cell>(16, 16);
	populate_board(40,16,16);
}

void Board::create_exprt_board()
{
	m_Board = new Array2D<Cell>(16, 30);
	populate_board(100,16,30);
}

void Board::flagcell(int row, int column)
{
	m_Board[row][column]->setState = 'F';
}

char Board::uncovercell(int row, int column)
{
	if (m_Board[row][column] = '0')
	{

	}
	return m_Board[row][column].getValue();
}

void Board::printboard()
{
	for (int i = 0; i < m_Board->getRow; ++i)
	{
		for (int j = 0; j < m_Board->getColumn; ++j)
		{

		}
	};
}
