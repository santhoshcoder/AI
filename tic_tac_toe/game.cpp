#include <iostream>
using namespace std;
void boarddisplay(char s[][3]);
char nextPlayer();
void printplayer();
void printactions(char s[][3]);
char player = 'X';
int main() 
{
	char s[3][3] = {{'_','_','_'},{'_','_','_'},{'_','_','_'}};
	//printplayer(player);
	cout<<"Initial State"<<endl;
	boarddisplay(s);
	cout<<"----------------------------------------------"<<endl;
	//nextPlayer();
	printplayer();
	printactions(s);
}
void printactions(char s[][3])
{
	cout<<"Current Player Actions"<<endl;
	for(int i = 0;i < 3;i++)
	{
		for(int j = 0;j < 3;j++)
		{
			if(s[i][j] != '_')
				continue;
			else
			{
				s[i][j] = player;
				boarddisplay(s);
				s[i][j] = '_';
			}
		}
	}
}
void printplayer()
{
	cout<<"Current Player: "<<player<<endl;
}
char nextPlayer()
{
	if(player == 'X')
		player = 'O';
	else
		player = 'X';
}
void boarddisplay(char s[3][3])
{
	cout<<endl<<"***************"<<endl;
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			cout<<s[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl<<"***************"<<endl;
}