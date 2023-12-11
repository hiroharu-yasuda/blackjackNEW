#include"Shoe.h"
#include <iostream>
#include <random> //��������
#include"common.h"

using namespace std;
Shoe::Shoe() 
{
	_cardNum = CARD_NUM;
	for (int i = 0; i < CARD_NUM; i++) {
		_cardShoe[i] = i;
	}
	_shuffle();
}
Shoe::~Shoe()
{

}
int Shoe::takeCard() 
{
	if (_cardNum <= 0)return -1;
	//��납������Ă����������W�b�N�I�ɂ��y����炵��
	_cardNum--;
	int card = _cardShoe[_cardNum];
	_cardShoe[_cardNum] = -1;//�O�̂��߂̃f�o�b�N�p

	return card;
}
void Shoe::_shuffle()
{
	for (int i = _cardNum; i > 1; --i) {
		int a = i - 1;
		int b = rand() % i;
		swap(_cardShoe[a], _cardShoe[b]);
	}
}