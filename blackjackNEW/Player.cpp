#include <iostream>
#include "Player.h"
#include "Shoe.h"
using namespace std;


Player::Player(const char* name) : Person(name) {

}

Player::~Player() {

}

//ゲーム実行
void Player::PlayBase(Shoe& shoe) {
	printf("\n%sのターン\n", getName());

	//入力
	char str[HAND_SIZE] = { " " }; 
	do {
		//手札
		printf("\n========================  \n");
		showName();
		printf("\n\nHand\n");
		showHand();
		printf("\n\nScore\n");
		showScore();
		printf("\n========================  \n");
		cout << "hit or stand >> ";

		cin >> str; //文字列を入力
		//hitが入力された場合
		if (strcmp(str, "hit") == 0) {
			//カードの配布
			hit(shoe);
		}
		else if (strcmp(str, "stand") == 0) {
			break;
		}
	} while (calcScore());
}