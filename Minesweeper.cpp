#include <iostream>
using std::cout;
using std::cin;
#include "Minesweeper.h"


Minesweeper::Minesweeper() : m_game(nullptr), m_level('\0')
{
	StartGame();
}

Minesweeper::~Minesweeper()
{
}

void Minesweeper::StartGame()
{
	while (m_level != 'b' || m_level != 'i' || m_level != 'e')
	{
		cout << "*****Starting a New Game***** \n" << "Enter level you would like to play:\n" <<
			"	b=beginner 10x10 grid with 10 mines\n" <<
			"	i=intermediate 16x16 gride with 40mines\n" <<
			"	e=expert 16x30 grids with 100 mines \n";
		cout << "Selection:";
		cin >> m_level;
		if (m_level != 'b' || m_level != 'i' || m_level != 'e')
		{
			cout << "In valid selection restarting\n";
		}
	}
	m_game = new Board(m_level);
	PlayingGame();
}

void Minesweeper::PlayingGame()
{
	int row_select = -1;
	int column_select = -1;
	m_game->printboard();

}

bool Minesweeper::GameOver()
{

	return false;
}

void Minesweeper::NewGame()
{
	char newgame = '\0';
	while (newgame != 'y' || newgame != 'n')
	{
		cout << "\n **Would You like to Play again?(y,n): ";
		{
			cin >> newgame;
		}
		if (newgame != 'y' || newgame != 'n')
		{
			cout << "Invalid Selection!";
		}
	}
	if (newgame == 'y')
	{
		StartGame();
	}
}