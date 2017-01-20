#ifndef MINESWEEPER_H
#define MINESWEEPER_H
#include "Board.h"


class Minesweeper
{
public:
	Minesweeper();
	~Minesweeper();
	void StartGame();
	void PlayingGame();
	bool GameOver();
	void NewGame();
private:
	Board * m_game;
	char m_level;
};

#endif
