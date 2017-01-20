#ifndef BOARD_H
#define BOARD_H
#include "Cell.h"
#include "Array2D.h"

template<typename T>
class Array2D;

class Cell;


class Board
{
public:
	Board();
	Board(char level);
	void populate_board(int bombs, int length, int height);
	void create_beg_board();
	void create_inter_board();
	void create_exprt_board();
	void flagcell(int row, int column);
	char uncovercell(int row, int column);
	void printboard();
private:
	Array2D<Cell> * m_Board;
};




#endif