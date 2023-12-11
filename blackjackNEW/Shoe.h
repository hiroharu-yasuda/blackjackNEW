#pragma once

#include "common.h"
#include "Card.h"

class Shoe {
private:
public:
	
	int _cardNum;
	Card _cardShoe[CARD_MAX];

public:
	Shoe();
	virtual ~Shoe();	// �f�X�g���N�^�� virtual ������

public:
	bool takeCard(Card& card);		// �J�[�h���ꖇ�o��
	void _shuffle();
};