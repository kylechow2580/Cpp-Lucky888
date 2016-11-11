#include "StdAfx.h"
#include "pokercard.h"
#include <iostream>
#include <string>
using namespace std;


void PokerCard::setType(string t)
{
	type = t;
}
void PokerCard::setValue(int v)
{
	value = v;
}
void PokerCard::setPosition(int p)
{
	position = p;
}
string PokerCard::getType() const
{
	return type;
}
int PokerCard::getValue() const
{
	return value;
}
int PokerCard::getPosition() const
{
	return position;
}