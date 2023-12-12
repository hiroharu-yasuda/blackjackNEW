#include <iostream>
#include <ctime>
#include "Shoe.h"
#include "Player.h"
#include "Dealer.h"

using namespace std;

const int NUMBER_MAX = 13;
const char* CARD_NUMBER[] = { "Joker", " A", " 2", " 3", " 4", " 5", " 6", " 7", " 8", " 9", "10", " J", " Q", " K" };
const char* CARD_SUIT[] = { "  heart", "diamond", "  spade", "   club" };


void ShowHand(Person& person) {
	printf("========================\n");
	printf("Dealer\n");
	person.showName();
	printf("\n\nHand\n");
	person.showHand();
	printf("\n\nScore\n");
	person.showScore();
	printf("\n========================\n");
}

void ShowHand(Person& p1, Person& p2, Person& p3, Person& p4) {
	const Person* players[] = { &p1, &p2, &p3, &p4 };
	int size = (sizeof players / sizeof players[0] - 1);

	printf("\n");
	for (int i = 0, end = size; i <= end; i++) {
		printf("========================  ");
	}
	printf("\nPlayers\n");
	// 名前
	for (int i = 0, end = size; i <= end; i++) {
		players[i]->showName();
	}
	printf("\n\n");
	// 手札
	for (int i = 0, end = size; i <= end; i++) {
		printf("%-26s", "Hand");
	}
	printf("\n");
	for (int i = 0, end = size; i <= end; i++) {
		players[i]->showHand();
	}
	printf("\n\n");
	// スコア
	for (int i = 0, end = size; i <= end; i++) {
		printf("%-26s", "Score");
	}
	printf("\n");
	for (int i = 0, end = size; i <= end; i++) {
		players[i]->showScore();
	}
	printf("\n");

	for (int i = 0, end = size; i <= end; i++) {
		printf("========================  ");
	}
	printf("\n");
}

static void showResult(Player& p1, Player& p2, Player& p3, Player& p4, Dealer& dealer)
{
	const Player* players[] = { &p1, &p2, &p3, &p4 };
	int size = (sizeof players / sizeof players[0] - 1);

	printf("\n========================  \n");
	printf("         RESULT           ");
	printf("\n========================  \n");
	ShowHand(dealer);
	ShowHand(p1, p2, p3, p4);


	for (int i = 0, end = size; i <= end; i++) {
		if (players[i]->calcScore() > dealer.calcScore()) {
			printf("%s Win\n", players[i]->getName());
		}
		else if (players[i]->calcScore() < dealer.calcScore()) {
			printf("%s Lose\n", players[i]->getName());
		}
		else {
			printf("%s Push\n", players[i]->getName());
		}
	}
}

int main()
{
	srand((unsigned int)time(NULL));
	Player p1("inu");
	Player p2("dog");
	Player p3("wanko");
	Player p4("neko");
	Player* players[4] = { &p1, &p2, &p3, &p4 };
	int size = (sizeof players / sizeof players[0] - 1);

	Dealer d("Dealer");
	Shoe shoe;
	shoe._shuffle();

	d.hit(shoe);
	ShowHand(d);
	d.hit(shoe);

	for (int i = 0, end = size; i <= end; i++) {
		for (int j = 0; j < 2; j++) {
			players[i]->hit(shoe);
		}
	}
	ShowHand(p1, p2, p3, p4);

	bool dealerFlag = false;
	for (int i = 0, end = size; i <= end; i++) {
		if (players[i]->Play(shoe)) {
			dealerFlag = true;
		}
	}

	if (dealerFlag) {
		d.Play(shoe);

		showResult(p1, p2, p3, p4, d);
	}
	else {
		printf("全員バーストしたので負けです。");
	}
}

// プログラムの実行: Ctrl + F5 または [デバッグ] > [デバッグなしで開始] メニュー
// プログラムのデバッグ: F5 または [デバッグ] > [デバッグの開始] メニュー

// 作業を開始するためのヒント: 
//    1. ソリューション エクスプローラー ウィンドウを使用してファイルを追加/管理します 
//   2. チーム エクスプローラー ウィンドウを使用してソース管理に接続します
//   3. 出力ウィンドウを使用して、ビルド出力とその他のメッセージを表示します
//   4. エラー一覧ウィンドウを使用してエラーを表示します
//   5. [プロジェクト] > [新しい項目の追加] と移動して新しいコード ファイルを作成するか、[プロジェクト] > [既存の項目の追加] と移動して既存のコード ファイルをプロジェクトに追加します
//   6. 後ほどこのプロジェクトを再び開く場合、[ファイル] > [開く] > [プロジェクト] と移動して .sln ファイルを選択します
