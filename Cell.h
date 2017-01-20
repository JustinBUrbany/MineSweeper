#ifndef CELL_H
#define CELL_H

class Cell
{
public:
	Cell();
	~Cell();
	char getState();
	void setState(char state);
	char getValue();
	void setValue(char value);
	bool isflaged();
private:
	char m_value;
	char m_state;
};




#endif
