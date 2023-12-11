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
	//�X�R�A��16�ȉ��̏ꍇhit�𑱂���
	while (calcScore() < 17 && calcScore() > 0) {
		//�q�b�g����
		hit(shoe);
		cout << "hit" << endl;
		//��D�̕\��
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