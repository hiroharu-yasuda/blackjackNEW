#include <iostream>
#include <ctime>
#include "Shoe.h"
#include"Card.h"
using namespace std;


// �R���X�g���N�^
Shoe::Shoe() {
	_cardNum = CARD_NUM - 1;

	int num = 0;
	int suit = 0;


	for (int i = 0; i < CARD_NUM; i++) {
		num = i % NUMBER_MAX + 1;
		suit = i / NUMBER_MAX;
		_cardShoe[i].SetCard(num, suit);
	}
}

Shoe::~Shoe() {

}

bool Shoe::takeCard(Card& card) {
	card = _cardShoe[_cardNum];
	if (card.GetNum() <= 0) {
		return false;
	}

	_cardShoe[_cardNum].SetCard(-1, -1);
	_cardNum--;

	return true;
}

//�V���b�t���i�t�B�b�V���[�C�F�[�c�j
void Shoe::_shuffle()
{
	srand((unsigned int)time(NULL));

	for (int i = _cardNum + 1; i > 1; --i) {
		int a = i - 1;
		int b = rand() % i;
		swap(_cardShoe[a], _cardShoe[b]);
	}
}