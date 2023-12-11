#include <iostream>
#include "Dealer.h"
#include "Shoe.h"
using namespace std;

Dealer::Dealer() : Person("Dealer") {

}

Dealer::Dealer(const char* name) : Person(name) {

}

Dealer::~Dealer() {

}


void Dealer::PlayBase(Shoe& shoe) {
	//スコアが16以下の場合hitを続ける
	while (calcScore() < 17 && calcScore() > 0) {
		//ヒットする
		hit(shoe);
		cout << "hit" << endl;
		//手札の表示
		printf("\n========================  \n");
		printf("Dealer:");
		showName();
		printf("\n\nHand\n");
		showHand();
		printf("\n\nScore\n");
		showScore();
		printf("\n========================  \n");
	}
}