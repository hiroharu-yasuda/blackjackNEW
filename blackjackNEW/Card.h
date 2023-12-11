#pragma once
extern const int NUMBER_MAX;
extern const char* CARD_NUMBER[];
extern const char* CARD_SUIT[];


struct CardKinds {
	int CardNum;
	int CardSuit;
};

class Card
{
protected:
	int _cardNum;
	int _cardSuit;

public:
	void operator=(const Card other);
	bool operator==(const Card other);
	void SetCard(int num, int suit);
	const int GetNum()  const;
	const int GetSuit()  const;
	const char* ShowNum() const;
	const char* ShowSuit() const;
};