#pragma once
#include "common.h"
#include "Card.h"

class Shoe;

class Person {
private:
	Card _hand[HAND_SIZE];
	int _cardNum;
	char* _pName;
	virtual void PlayBase(Shoe& shoe) = 0;

public:
	Person(const char* pName);
	virtual ~Person();

	void hit(Shoe& shoe);
	void showName() const;
	void showHand() const;
	void showScore() const;
	int calcScore() const;
	bool Play(Shoe& shoe);

	const char* getName() const;
};

