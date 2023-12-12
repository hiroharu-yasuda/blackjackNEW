#pragma once

#include "common.h"
#include "Card.h"

class Shoe {
private:
public:
	
	int _cardNum;
	Card _cardShoe[CARD_NUM];

public:
	Shoe();
	virtual ~Shoe();	// デストラクタは virtual をつける

public:
	bool takeCard(Card& card);		// カードを一枚出す
	void _shuffle();
};