// blackjackNEW.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include"Shoe.h"
#include"Dealer.h"
#include"Person.h"

#include"Player.h"


using namespace std;

static void ShowHand(Person& p) {

	cout << "============================" << endl;
	cout << p.Getname() << endl;
	p.ShowHand();
	cout << "============================" << endl;
}
static void showResult(Player& p, Dealer& d)
{
	cout << "============================" << endl;
	cout << "            result          " << endl;
	cout << "============================" << endl;
	ShowHand(p);
	ShowHand(d);

	if (p.calcScore() > d.calcScore()) {
		cout << "Player Win!" << endl;
	}
	else if (p.calcScore() < d.calcScore()) {
		cout << "Player Lose" << endl;
	}
	else {
		cout << "Push" << endl;
	}
}
int main()
{
	srand(time(NULL));
	Player p("HAL");
	Dealer d ;
	Shoe shoe;
	for (int i = 0; i < 2; i++) {
		p.hit(&shoe);
	}
	ShowHand(p);

	d.hit(&shoe);
	
	ShowHand(d);

	if (p.play(&shoe) == true) {

		d.play(&shoe);
		
	}
	else {
		cout << "バーストしたのでyouの負けデース！！" << endl;
	}

	showResult(p, d);

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
