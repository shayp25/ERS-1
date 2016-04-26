#include <winbgi.cpp>
#include <graphics.h>
#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

int GrDriver, GrMode, ErrorCode;

void gr_Start(int &GrDriver, int &GrMode, int &ErrorCode){
	GrDriver = VGA;
	GrMode = VGAMAX;
	initgraph(&GrDriver, &GrMode, "");
	ErrorCode = graphresult();
	if (ErrorCode != grOk){
		cout << "Error : " << ErrorCode << endl;
		getch();
		exit(1);
	}

}

void shuffle(vector<int> &stuff);
void put(vector<int> &pp, vector<int> &pile);
bool check(vector<int> &pile);
bool checkTen(vector<int> &pile);
bool checkDouble(vector<int> &pile);
bool checkSandwitch(vector<int> &pile);
bool checkST(vector<int> &pile);
bool checkFace(vector<int> &pile);
bool checkJ(vector<int> &pile);
bool checkQ(vector<int> &pile);
bool checkK(vector<int> &pile);
bool checkA(vector<int> &pile);
// a = 97, d = 100, j = 106, l = 
void main(){
	srand(time(NULL));
	vector<int> deck (52); // Spades : 0 - 12, Hearts : 13 - 25, Diamonds : 26 - 38, Clubs : 39 - 51
	vector<int> player1;
	vector<int> player2;
	vector<int> pile;

	bool p1turn = true;
	char lshift;
	for (int i = 0; i < deck.size(); i++){
		deck[i] = i;
	}
	shuffle(deck);
	/*for (int i = 0; i < deck.size(); i++){
		cout << deck[i] << endl;
	}*/
	for (int i = 0; i < 26; i++){
		player1.push_back(deck[deck.size() - 1]);
		deck.pop_back();
	}
	for (int i = 0; i < 26; i++){
		player2.push_back(deck[deck.size() - 1]);
		deck.pop_back();
	}
	shuffle(player1);
	shuffle(player2);
	bool win = false;
	//gr_Start(GrDriver, GrMode, ErrorCode);

	while (win == false){
		if (player1.size() == 1)
		{	 win = true;
			cout << "Player two wins!"<<"\n";
		
		}
		if (player2.size() == 1)
		{	win = true;
			cout << "Player one wins!"<<"\n";
		
		}
		if (p1turn == true){
			if ((GetAsyncKeyState(VK_LSHIFT) & 0x8000) != 0){
				//cout << "Left Shift \n";
				//if ()
				cout << player1[0] << "\n";
				put(player1, pile);
				cout << player1[0] << "\n";
				cout << pile[pile.size() - 1] << "\n" << "\n";
				p1turn = false;
				do{} while ((GetAsyncKeyState(VK_LSHIFT) & 0x8000) != 0);
			}
		}
		if (p1turn == false){
			if ((GetAsyncKeyState(VK_RSHIFT) & 0x8000) != 0){
				//cout << "Right Shift \n";
				cout << player2[0] << "\n";
				put(player2, pile);
				cout << player2[0] << "\n";
				cout << pile[pile.size() - 1] << "\n" << "\n";
				do{} while ((GetAsyncKeyState(VK_RSHIFT) & 0x8000) != 0);
				p1turn = true;
		}
	}
		if (kbhit()){
			int key = getch();
			cout << key << endl;
		}
		/*for (int i = 0; i < player1.size(); i++)
		{
			cout << player1[i] << "\n";
		}
		cout << "End of player 1 deck" << "\n";
		system("pause");
		for (int i = 0; i < player2.size(); i++)
		{
			cout << player2[i] << "\n";
		}
		cout << "End of player 2 deck" << "\n";*/
		
	}

	getch();
	

}

void shuffle(vector <int> &stuff){
	for (int i = 0; i < rand() % 5 + 2; i++){
		random_shuffle(stuff.begin(), stuff.end());
	}
}

void put(vector<int> &pp, vector<int> &pile){
	pile.push_back(pp[0]);
	pp.erase(pp.begin());
}

bool check(vector <int> pile){
	if (checkDouble(pile) == true) return true;
	if (checkTen(pile) == true) return true;
	if (checkSandwitch(pile) == true) return true;
	if (checkST(pile) == true) return true;
	if (checkFace(pile) == true) return true;
	return false;
}

bool checkTen(vector<int> &pile){
	if (pile[pile.size() - 1] + pile[pile.size() - 2] == 8) return true;
	return false;
}

bool checkDouble(vector<int> &pile){
	if (pile[pile.size() - 1] == pile[pile.size() - 2]) return true;
	return false;
}

bool checkSandwitch(vector<int> &pile){
	if (pile[pile.size() - 1] == pile[pile.size() - 3]) return true;
	return false;
}

bool checkST(vector<int> &pile){
	if (pile[pile.size() - 1] + pile[pile.size() - 3] == 8) return true;
	return false;
}

bool checkFace(vector<int> &pile){
	if (checkJ(pile) == true) return true;
	if (checkQ(pile) == true) return true;
	if (checkK(pile) == true) return true;
	if (checkA(pile) == true) return true;
	return false;
}

bool checkJ(vector<int> &pile){
	return true;
}

bool checkQ(vector<int> &pile){
	return true;
}

bool checkK(vector<int> &pile){
	return true;
}

bool checkA(vector<int> &pile){
	return true;
}