#include <iostream>
using namespace std;
void printboard(char [][8]);
void actions(char board[][8],char player);
bool checkLeft(char board[][8],int row,int col,char player);
bool checkRight(char board[][8],int row,int col,char player);
int main() 
{
	//char board[8][8];
	char board[8][8] = 
	{
		{'_','_','_','_','_','_','_','_'},
		{'_','_','_','_','_','_','_','_'},
		{'_','_','_','_','_','_','_','_'},
		{'_','_','_','_','_','_','_','_'},
		{'_','_','_','_','_','_','_','_'},
		{'_','_','_','_','_','_','_','_'},
		{'_','_','_','_','_','Y','_','_'},
		{'_','_','_','_','_','_','P','_'}
	};
	/*
	for(int i = 0;i < 8;i++)
	{
		for(int j = 0;j < 8;j++)
		{
			if(i == 0 || i == 2 || i == 6)
			{
				if(j % 2 != 0 && i != 6)
				{
					board[i][j] = 'X';
				}
				else if(j % 2 != 0)
				{
					board[i][j] = 'O';
				}
				else
				{
					board[i][j] = '_';
				}
			}
			else if(i == 1 || i == 5 || i == 7)
			{
				if( j % 2 == 0 && i != 1)
				{
					board[i][j] = 'O';
				}
				else if(j % 2 == 0)
				{
					board[i][j] = 'X';
				}
				else
				{
					board[i][j] = '_';
				}
			}
			else
			{
				board[i][j] = '_';
			}
		}
	}
	*/
	printboard(board);
	cout<<"Printing actions "<<endl;
	actions(board,'X');
	//cout << "Hello World!\n";
}
void printboard(char board[][8])
{
	cout<<endl<<"********************"<<endl;
	for(int i = 0;i < 8; i++)
	{
		if(i == 0)
		{
			cout<<"-------------------"<<endl;
			cout<<"R/C 0 1 2 3 4 5 6 7"<<endl;
			cout<<"-------------------";
			cout<<endl;
		}
		cout<<" |"<<i<<"|";
		for(int j = 0;j < 8;j++)
		{
			cout<<board[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl<<"********************"<<endl;
}
bool checkKing(int row,char player)
{
	if(player == 'X' && row == 7)
	{
			return true;
	}
	if(player == 'O' && row == 0)
	{
		return true;
	}
	return false;
}
void actions(char board[][8],char player)
{
	for(int i = 0;i < 8;i++)
	{
		for(int j = 0;j < 8;j++)
		{
			if(board[i][j] != '_')
			{
				if(player == 'X' && board[i][j] == 'X')//Computer normal player
				{
					cout<<"Computer Normal player"<<endl;
					char newboard[8][8];
					copy(&board[0][0],&board[0][0]+8*8,&newboard[0][0]);
					
					//Check left diagnoal
					if(checkLeft(board,i,j,player))
					{
						//I can move left
						if(checkKing(i+1,player))
							newboard[i+1][j-1] = 'Y';
						else
							newboard[i+1][j-1] = 'X';
						newboard[i][j] = '_';
						printboard(newboard);
						copy(&board[0][0],&board[0][0]+8*8,&newboard[0][0]);
					}
					//Check right diagnoal
					if(checkRight(board,i,j,player))
					{
						//I can move right
						if(checkKing(i+1,player))
							newboard[i+1][j+1] = 'Y';
						else
							newboard[i+1][j+1] = 'X';
						newboard[i][j] = '_';
						printboard(newboard);
						copy(&board[0][0],&board[0][0]+8*8,&newboard[0][0]);
					}
					//Check jumps
					
				}
				else if(player == 'O' && board[i][j] == 'X') //user normal player
				{
					cout<<"User Normal player"<<endl;
					char newboard[8][8];
					copy(&board[0][0],&board[0][0]+8*8,&newboard[0][0]);
					
					//Check left diagnoal
					if(checkLeft(board,i,j,player))
					{
						//I can move left
						if(checkKing(i-1,player))
							newboard[i-1][j-1] = 'P';
						else
							newboard[i-1][j-1] = 'O';
						newboard[i][j] = '_';
						printboard(newboard);
						copy(&board[0][0],&board[0][0]+8*8,&newboard[0][0]);
					}
					//Check right diagnoal
					if(checkRight(board,i,j,player))
					{
						//I can move right
						if(checkKing(i-1,player))
							newboard[i-1][j+1] = 'P';
						else
							newboard[i-1][j+1] = 'O';
						newboard[i][j] = '_';
						printboard(newboard);
						copy(&board[0][0],&board[0][0]+8*8,&newboard[0][0]);
					}
					//Check jumps
					
				}
				if(player == 'X' && board[i][j] == 'Y') //Computer player turned king
				{
					cout<<"Computer player turned king"<<endl;
					char newboard[8][8];
					copy(&board[0][0],&board[0][0]+8*8,&newboard[0][0]);
					//Check left diagnoal 'X'
					if(checkLeft(board,i,j,'X'))
					{
						//I can move left
						newboard[i+1][j-1] = 'Y';
						newboard[i][j] = '_';
						printboard(newboard);
						copy(&board[0][0],&board[0][0]+8*8,&newboard[0][0]);
					}
					//Check right diagnoal 'X'
					if(checkRight(board,i,j,'X'))
					{
						//I can move right
						newboard[i+1][j+1] = 'Y';
						newboard[i][j] = '_';
						printboard(newboard);
						copy(&board[0][0],&board[0][0]+8*8,&newboard[0][0]);
					}
					//Check left diagnoal 'O';
					if(checkLeft(board,i,j,'O'))
					{
						//I can move left
						newboard[i-1][j-1] = 'Y';
						newboard[i][j] = '_';
						printboard(newboard);
						copy(&board[0][0],&board[0][0]+8*8,&newboard[0][0]);
					}
					//Check right diagnoal 'O'
					if(checkRight(board,i,j,'O'))
					{
						//I can move right
						newboard[i-1][j+1] = 'Y';
						newboard[i][j] = '_';
						printboard(newboard);
						copy(&board[0][0],&board[0][0]+8*8,&newboard[0][0]);
					}		
					//Check jumps			
				}
				if(player == 'O' && board[i][j] == 'P') //User player turned king
				{
					cout<<"User player turned king"<<endl;
					char newboard[8][8];
					copy(&board[0][0],&board[0][0]+8*8,&newboard[0][0]);
					//Check left diagnoal 'X'
					if(checkLeft(board,i,j,'X'))
					{
						//I can move left
						newboard[i+1][j-1] = 'P';
						newboard[i][j] = '_';
						printboard(newboard);
						copy(&board[0][0],&board[0][0]+8*8,&newboard[0][0]);
					}
					//Check right diagnoal 'X'
					if(checkRight(board,i,j,'X'))
					{
						//I can move right
						newboard[i+1][j+1] = 'p';
						newboard[i][j] = '_';
						printboard(newboard);
						copy(&board[0][0],&board[0][0]+8*8,&newboard[0][0]);
					}
					//Check left diagnoal 'O';
					if(checkLeft(board,i,j,'O'))
					{
						//I can move left
						newboard[i-1][j-1] = 'P';
						newboard[i][j] = '_';
						printboard(newboard);
						copy(&board[0][0],&board[0][0]+8*8,&newboard[0][0]);
					}
					//Check right diagnoal 'O'
					if(checkRight(board,i,j,'O'))
					{
						//I can move right
						newboard[i-1][j+1] = 'P';
						newboard[i][j] = '_';
						printboard(newboard);
						copy(&board[0][0],&board[0][0]+8*8,&newboard[0][0]);
					}		
					//Check jumps			
				}
			}
		}
	}
}
bool checkLeft(char board[][8],int row,int col,char player)
{
	int lrow,lcol;
	if(player == 'X')
	{
		lrow = row+1;
		lcol = col-1;
	}
	else if(player == 'O')
	{
		lrow = row-1;
		lcol = col-1;
	}
	if(!(lrow >= 0 && lrow <= 7 && lcol >= 0 && lcol <= 7 && board[lrow][lcol] =='_'))
		return false;
	return true;
}
bool checkRight(char board[][8],int row,int col,char player)
{
	int lrow,lcol;
	if(player == 'X')
	{
		lrow = row+1;
		lcol = col+1;
	}
	else if(player == 'O')
	{
		lrow = row-1;
		lcol = col+1;
	}
	if(!(lrow >= 0 && lrow <= 7 && lcol >= 0 && lcol <= 7 && board[lrow][lcol] =='_'))
		return false;
	return true;		
}