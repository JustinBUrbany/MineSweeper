#include "Cell.h"

Cell::Cell()
{
}

Cell::~Cell()
{
}

char Cell::getState()
{
	return m_state;
}

void Cell::setState(char state)
{
	m_state=state;
}

char Cell::getValue()
{
	return m_value;
}

void Cell::setValue(char value)
{
	m_value=value;
}

bool Cell::isflaged()
{
	bool flagged = false;
	if (m_state == 'F')
		flagged = true;
	return flagged;
}
