#include <iostream>
using namespace std;
void boarddisplay(char s[][3]);
char nextPlayer();
void printplayer();
void printactions(char s[][3]);
bool wincheck(char s[][3]);
char player = 'X';
int main() 
{
	char s[3][3] = {{'X','O','X'},{'X','O','X'},{'O','X','O'}};
	//printplayer(player);
	cout<<"Initial State"<<endl;
	boarddisplay(s);
	cout<<"----------------------------------------------"<<endl;
	//nextPlayer();
	printplayer();
	//printactions(s);
	if(!wincheck(s))
	{
		cout<<"Game is not done yet"<<endl;
	}
	cout<<endl;
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

bool wincheck(char s[][3])
{
	if(s[0][0] == s[0][1] && s[0][1] == s[0][2])
	{
		if(s[0][0] == 'X')
			cout<<"X win";
		else if(s[0][0] == 'O')
			cout<<"O win";
		else
			return false;
		return true;
	}
	else if(s[1][0] == s[1][1] && s[1][1] == s[1][2])
	{
		if(s[1][0] == 'X')
			cout<<"X win";
		else if(s[1][0] == 'O')
			cout<<"O win";
		else
			return false;
		return true;
	}
	else if(s[2][0] == s[2][1] && s[2][1] == s[2][2])
	{
		if(s[2][0] == 'X')
			cout<<"X win";
		else if(s[2][0] == 'O')
			cout<<"O win";
		else
			return false;
		return true;
	}
	else if(s[0][0] == s[1][1] && s[1][1] == s[2][2])
	{
		if(s[0][0] == 'X')
			cout<<"X win";
		else if(s[0][0] == 'O')
			cout<<"O win";
		else
			return false;
		return true;		
	}
	else if(s[0][2] == s[1][1] && s[1][1] == s[2][0])
	{
		if(s[0][2] == 'X')
			cout<<"X win";
		else if(s[0][2] == 'O')
			cout<<"O win";
		else
			return false;
		return true;		
	}
	else if(s[0][0] == s[1][0] && s[1][0] == s[2][0])
	{
		if(s[0][0] == 'X')
			cout<<"X win";
		else if(s[0][0] == 'O')
			cout<<"O win";
		else
			return false;
		return true;		
	}
	else if(s[0][1] == s[1][1] && s[1][1] == s[2][1])
	{
		if(s[0][1] == 'X')
			cout<<"X win";
		else if(s[0][1] == 'O')
			cout<<"O win";
		else
			return false;
		return true;		
	}
	else if(s[0][2] == s[1][2] && s[1][2] == s[2][2])
	{
		if(s[0][2] == 'X')
			cout<<"X win";
		else if(s[0][2] == 'O')
			cout<<"O win";
		else
			return false;
		return true;		
	}
	for(int i = 0;i < 3; i++)
	{
		for(int j = 0;j <3;j++)
		{
			if(s[i][j] == '_')
				return false;
		}
	}
	cout<< "Tie";
	return true;
}
