#include"Shoe.h"
#include <iostream>
#include <random> //乱数生成
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
	//後ろから引いていく方がロジック的にも楽ちんらしい
	_cardNum--;
	int card = _cardShoe[_cardNum];
	_cardShoe[_cardNum] = -1;//念のためのデバック用

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