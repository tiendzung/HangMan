#include<bits/stdc++.h>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iostream>
#include <chrono>
#include <thread>
#define ii pair<int,int>
#define ll long long
using namespace std;
const vector<string> figureWin = {
	"     O     \n"
	"    /|\\   \n"
	"    | |    \n",
	"     O     \n"
	"    /|\\   \n"
	"    / \\   \n",
	"   __O__   \n"
	"     |     \n"
	"    / \\   \n",
	"    \\O/   \n"
	"     |     \n"
	"    / \\   \n",
	"   __O__   \n"
	"     |     \n"
	"    / \\   \n",
	"     O     \n"
	"    /|\\   \n"
	"    / \\   \n" ,
	"    O      \n"
	"    /|\\   \n"
	"    / \\   \n" ,
	"     O     \n"
	"    /|\\   \n"
	"    / \\   \n" ,
	"      O    \n"
	"    /|\\   \n"
	"    / \\   \n" ,
	"     O     \n"
	"    /|\\   \n"
	"    / \\   \n" ,
};
const vector<string> figureLoose = {
	"   ------------+    \n"
	"   |    /           \n"
	"   |    O      \n"
	"   |   /|\\    \n"
	"   |   / \\    \n"
	"   |        \n"
	" -----      \n" ,
	"   ------------+     \n"
	"   |     |           \n"
	"   |     O           \n"
	"   |    /|\\         \n"
	"   |    / \\         \n"
	"   |        \n"
	" -----      \n",
	"   ------------+     \n"
	"   |      \\         \n"
	"   |      O          \n"
	"   |     /|\\        \n"
	"   |     / \\        \n"
	"   |      \n"
	" -----    \n",
	"   ------------+     \n"
	"   |     |           \n"
	"   |     O           \n"
	"   |    /|\\         \n"
	"   |    / \\         \n"
	"   |        \n"
	" -----      \n"
};
void clearScreen() {
	const int PATCH_LINES = 30;
	for (int i = 0; i < PATCH_LINES; i++) cout << endl;
}
long long id = 0;
const int MAX_FW = figureWin.size(), MAX_FL = figureLoose.size();
void displayWon()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	while(true)
	{
		clearScreen();
		cout << figureWin[id] << "\n";
		cout << "You're Win!\n";
		this_thread::sleep_for(chrono::milliseconds(500));
		id = (id+1)%MAX_FW;
	}
}
void displayLoose(const string& secretWord)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	while(true)
	{
		clearScreen();
		cout << figureLoose[id] << "\n";
		cout << "You're Loose! The word is:  "<<secretWord;
		this_thread::sleep_for(chrono::milliseconds(500));
		id = (id+1)%MAX_FL;
	}
}
