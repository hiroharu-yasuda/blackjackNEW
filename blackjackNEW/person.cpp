
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include "Person.h"
#include "Shoe.h"
using namespace std;


Person::Person(const char* pName) {
	_cardNum = 0;

	_pName = new char[strlen(pName) + 1];
	strcpy(_pName, pName);
}

Person::~Person() {
	if (_pName != nullptr) {
		delete[] _pName;
		_pName = nullptr;
	}
}

const char* Person::getName() const {
	return _pName;
}

//スコアの計算
int Person::calcScore() const {
	if (_cardNum <= 0) {
		return 0;
	}
	int* data = NULL; //スコア計算用配列用ポインタ

	data = new(nothrow) int[_cardNum]; //手札枚数確保
	if (data == NULL)
	{
		// メモリ不足は今回はバーストとして終了する。
		cout << "メモリの確保に失敗しました。再起動してください。" << endl;
		return 0;
	}


	for (int i = 0; i < _cardNum; i++) {
		if (_hand[i].GetNum() < 11) {
			*(data + i) = _hand[i].GetNum();
		}
		else {
			//ここで10を格納しているのは,11-13のカードのこと
			*(data + i) = 10;
		}
	}

	//ソート（Aをあぶりだすため）
	sort(data, data + _cardNum);

	//返り値用変数(計算結果)
	int score = 0;
	//2番目から順にスコアを足していく
	//1番目が0の場合(つまりAである。2枚続く可能性はあるが2枚目のAは必ず1としてカウントする
	//ので先頭だけ調べればよい
	for (int i = 1; i < _cardNum; i++) {
		//スコアにデータを加える
		score += (*(data + i));
	}

	//先頭が1(A)であるか判定し状況によって1 or 11として計算
	if (*data == 1) {
		if (score + 11 < 22) { //11として扱ってもバーストしない場合
			//11を加える
			score += 11;
		}
		else {
			//11として扱うとバーストする場合
			//スコアに1を加える
			score += 1;
		}
	}
	else {
		//先頭が1でないなら,スコアにデータをそのまま加える
		score += data[0];
	}

	//バーストである場合は0を返す
	if (score > 21) {
		score = 0;
	}

	// 解放
	if (data != NULL)
	{
		delete[] data;
		data = NULL;
	}

	return score;
}

void Person::hit(Shoe& shoe) {
	if (shoe.takeCard(_hand[_cardNum])) {
		_cardNum++;
	}
	else
	{
		cout << "カードが引けませんでした。" << endl;
	}
}

void Person::showName() const {
	printf("%-26s", _pName);
}

void Person::showHand() const {
	//配列の最初から最後までを順に表示
	int i = 0;
	for (; i < _cardNum; i++) {
		printf("%s:%-2s ", CARD_SUIT[_hand[i].GetSuit()], CARD_NUMBER[_hand[i].GetNum()]);
	}
	for (int j = 0; j < 4; j++) {
		printf(" ");
	}
}

void Person::showScore() const {
	printf("%-26d", calcScore());
}

bool Person::Play(Shoe& shoe) {
	PlayBase(shoe);
	if (calcScore() <= 0) return false;
	return true;
}