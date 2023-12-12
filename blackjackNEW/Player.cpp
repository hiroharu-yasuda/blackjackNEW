#include <iostream>
#include "Player.h"
#include "Shoe.h"
using namespace std;


Player::Player(const char* name) : Person(name) {

}

Player::~Player() {

}

//�Q�[�����s
void Player::PlayBase(Shoe& shoe) {
	printf("\n%s�̃^�[��\n", getName());

	//����
	char str[HAND_SIZE] = { " " }; 
	do {
		//��D
		printf("\n========================  \n");
		showName();
		printf("\n\nHand\n");
		showHand();
		printf("\n\nScore\n");
		showScore();
		printf("\n========================  \n");
		cout << "hit or stand >> ";

		cin >> str; //����������
		//hit�����͂��ꂽ�ꍇ
		if (strcmp(str, "hit") == 0) {
			//�J�[�h�̔z�z
			hit(shoe);
		}
		else if (strcmp(str, "stand") == 0) {
			break;
		}
	} while (calcScore());
}