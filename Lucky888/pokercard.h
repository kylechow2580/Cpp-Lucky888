#ifndef POKERCARD_H
#define POKERCARD_H

#include <iostream>
#include <string>
using namespace std;


class PokerCard
{
	private:
		string type;
		int value;
		int position;
	public:
		void setType(string t);
		void setValue(int v);
		void setPosition(int p);
		string getType() const;
		int getValue() const;
		int getPosition() const;
};

#endif