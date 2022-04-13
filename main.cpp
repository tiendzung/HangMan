#include<bits/stdc++.h>
#define ii pair<int,int>
#define ll long long
using namespace std;
const int mod = 1e9+7;
const int base = 331;
const int MAX_WRONG_GUESSES = 7;
const string FIGURE[] = {
	"   -------------    \n"
	"   |                \n"
	"   |                \n"
	"   |                \n"
	"   |                \n"
	"   |     \n"
	" -----   \n",
	"   -------------    \n"
	"   |           |    \n"
	"   |                \n"
	"   |                \n"
	"   |                \n"
	"   |     \n"
	" -----   \n",
	"   -------------    \n"
	"   |           |    \n"
	"   |           O    \n"
	"   |                \n"
	"   |                \n"
	"   |     \n"
	" -----   \n",
	"   -------------    \n"
	"   |           |    \n"
	"   |           O    \n"
	"   |           |    \n"
	"   |                \n"
	"   |     \n"
	" -----   \n",
	"   -------------    \n"
	"   |           |    \n"
	"   |           O    \n"
	"   |          /|    \n"
	"   |                \n"
	"   |     \n"
	" -----   \n",
	"   -------------    \n"
	"   |           |    \n"
	"   |           O    \n"
	"   |          /|\\  \n"
	"   |                \n"
	"   |     \n"
	" -----   \n",
	"   -------------    \n"
	"   |           |    \n"
	"   |           O    \n"
	"   |          /|\\  \n"
	"   |          /     \n"
	"   |     \n"
	" -----   \n",
	"   -------------    \n"
	"   |           |    \n"
	"   |           O    \n"
	"   |          /|\\  \n"
	"   |          / \\  \n"
	"   |     \n"
	" -----   \n"
};
int nums[50];
vector<char> listwrong;
string chooseW()
{
	srand(time(0));
	vector<string> WORD_LIST;
	string s;
	string line;
	ifstream myfile ("dataword.txt");
	if(myfile.is_open())
	{
		while(getline(myfile,line))
		{
			WORD_LIST.push_back(line);
		}
		myfile.close();
	}
	const int WORD_ID = WORD_LIST.size();
	s = WORD_LIST[rand()%WORD_ID];
//	s = "apple";
	for(int i = 0; i < s.length(); i++)
	{
		nums[s[i]-'a']=1;
	}
	return s;
}
string secretWord = chooseW();
string guessWord = string(secretWord.length(), '-');
int wrongGuess = 0;
char letguess()
{
	char c;
	cout << "Enter the letter: ";
	cin >> c;
	return c;
}
bool check(const string& secretWord, char guess)
{
	int iguess = (guess > 'A') ? (guess - 'A') : (guess - 'a');
	for(int i = 0; i < secretWord.length(); i++)
	{
		if(secretWord[i]==guess&&nums[iguess]!=0) { nums[iguess]--; return true; }
	}
	return false;
}
void update(string& guessWord,const string& secretWord, char guess)
{
	for(int i = 0;i < guessWord.length(); i++)
	{
		if(guess == secretWord[i]) guessWord[i] = guess;
	}
}
void clearScreen() {
	const int PATCH_LINES = 30;
	for (int i = 0; i < PATCH_LINES; i++) cout << endl;
}
void renderGame(string guessWord, int wrongGuess)
{
	clearScreen();
	cout << "Wrong letter: ";
	for(int i = 0; i < listwrong.size(); i++) cout << listwrong[i] << " ";
	cout<<"\n\n";
	cout << FIGURE[wrongGuess];
	cout << guessWord << "\n";
	cout << "Number of wrong guesses: "<< wrongGuess << "\n";
}
int main()
{
	srand(time(0));
	while(wrongGuess != MAX_WRONG_GUESSES && guessWord != secretWord) 
	{
		char guess = letguess();
		if(check(secretWord, guess) == true)
		{
			update(guessWord, secretWord, guess);
		}
		else wrongGuess++, listwrong.push_back(guess);
		renderGame(guessWord, wrongGuess);
	}
//	renderGame(guessWord, wrongGuess);
	if(wrongGuess != MAX_WRONG_GUESSES) cout << "You're Win!";
	else cout << "You're Losse! The word is:  "<<secretWord;
}
