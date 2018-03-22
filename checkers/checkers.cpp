#include <iostream>
using namespace std;

void printboard(char [][8]);
void actions(char board[][8],char player);
bool checkLeft(char board[][8],int row,int col,char player);
bool checkRight(char board[][8],int row,int col,char player);
void jump(char board[][8],int row,int col,char player);
void kjump(char board[][8],int row,int col,char player);
void jumpleft(char newboard[][8],int row,int col,char player,int &,int &);
void jumpright(char newboard[][8],int row,int col,char player,int &,int &);
bool leftEnd(char board[][8],int row,int col,char player);
bool rightEnd(char board[][8],int row,int col,char player);
void kjumpleft(char newboard[][8],int row,int col,char player,int &crow,int &ccol);
void kjumpright(char newboard[][8],int row,int col,char player,int &crow,int &ccol);
void ktopleft(char newboard[][8],int row,int col,char player,int &crow,int &ccol);
void ktopright(char newboard[][8],int row,int col,char player,int &crow,int &ccol);
bool kleftend(char board[][8],int row,int col,char player);
bool krightend(char board[][8],int row,int col,char player);
bool ktopleftend(char board[][8],int row,int col,char player);
bool ktoprightend(char board[][8],int row,int col,char player);

int main() 
{
	//char board[8][8];
	char board[8][8] = 
	{
		{'_','_','_','_','_','_','_','_'},
		{'_','_','_','_','_','_','_','_'},
		{'_','_','X','_','X','_','_','_'},
		{'_','_','_','_','_','P','_','_'},
		{'_','_','Y','_','X','_','_','_'},
		{'_','_','_','_','_','_','_','_'},
		{'_','_','_','_','X','_','_','_'},
		{'_','_','_','_','_','_','_','_'}
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
	actions(board,'O');
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
/*
Returns true if the current position of the player makes him a king
else false;
*/
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
bool leftEnd(char board[][8],int row,int col,char player)
/*
Returns true if you cannot make a left jump from the current
position (row,col) else false
*/
{
	int nrow,ncol;
	if(player == 'X')
	{
		nrow = row + 2;
		ncol = col - 2;
		if((nrow >= 0 && nrow <= 7 && ncol >= 0 && nrow <= 7 && board[nrow][ncol] == '_'))
		{
			if(board[nrow-1][ncol+1] == 'O' || board[nrow-1][ncol+1] == 'P')
			{
				//Then i can make a left jump
				//left doesn't end here
				return false;
			}
		}
	}
	else if(player == 'O')
	{
		nrow = row - 2;
		ncol = col - 2;
		if((nrow >= 0 && nrow <= 7 && ncol >= 0 && nrow <= 7 && board[nrow][ncol] == '_'))
		{
			if(board[nrow+1][ncol+1] == 'X' || board[nrow+1][ncol+1] == 'Y')
			{
				//Then i can make a left jump
				//left doesn't end here
				return false;
			}
		}	
	}
	return true;
}
bool rightEnd(char board[][8],int row,int col,char player)
/*
Returns true if you cannot make a right jump from the current
position (row,col) else false
*/
{
	int nrow,ncol;
	if(player == 'X')
	{
		nrow = row + 2;
		ncol = col + 2;
		if((nrow >= 0 && nrow <= 7 && ncol >= 0 && nrow <= 7 && board[nrow][ncol] == '_'))
		{
			if(board[nrow-1][ncol-1] == 'O' || board[nrow-1][ncol-1] == 'P')
			{
				//Then i can make a right jump
				//Right Doesn't end here
				return false;
			}
		}
	}
	else if(player == 'O')
	{
		nrow = row - 2;
		ncol = col + 2;
		if((nrow >= 0 && nrow <= 7 && ncol >= 0 && nrow <= 7 && board[nrow][ncol] == '_'))
		{
			if(board[nrow+1][ncol-1] == 'X' || board[nrow+1][ncol-1] == 'Y')
			{
				//Then i can make a right jump
				//Right Doesn't end here
				return false;
			}
		}	
	}
	return true;
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
					jump(board,i,j,player);
				}
				else if(player == 'O' && board[i][j] == 'O') //user normal player
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
					jump(board,i,j,player);
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
					cout<<"Calling kjump"<<endl;
					kjump(board,i,j,player);		
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
					cout<<"Calling kjump in user player turned king"<<endl;
					kjump(board,i,j,player);		
				}
			}
		}
	}
}
bool compareMatrix(char s[][8],char d[][8])
{
	for(int i = 0;i < 8;i++)
	{
		for(int j = 0;j < 8;j++)
		{
			if(s[i][j] != d[i][j])
				return false;
		}
	}
	return true;
}
void kjump(char board[][8],int row,int col,char player)
{
	int crow,ccol;
	crow = row;
	ccol = col;
	char newboard[8][8];
	copy(&board[0][0],&board[0][0]+8*8,&newboard[0][0]);

	kjumpleft(newboard,row,col,player,crow,ccol);
	if(!compareMatrix(board,newboard) && kleftend(newboard,crow,ccol,player) && krightend(newboard,crow,ccol,player) && ktopleftend(newboard,crow,ccol,player) && ktoprightend(newboard,crow,ccol,player)) 
	{
		printboard(newboard);
	}
	copy(&board[0][0],&board[0][0]+8*8,&newboard[0][0]);
	
	kjumpright(newboard,row,col,player,crow,ccol);
	if(!compareMatrix(board,newboard) && kleftend(newboard,crow,ccol,player) && krightend(newboard,crow,ccol,player) && ktopleftend(newboard,crow,ccol,player) && ktoprightend(newboard,crow,ccol,player))
	{
		printboard(newboard);
	}
	copy(&board[0][0],&board[0][0]+8*8,&newboard[0][0]);
	
	ktopleft(newboard,row,col,player,crow,ccol);
	if(!compareMatrix(board,newboard)  && kleftend(newboard,crow,ccol,player) && krightend(newboard,crow,ccol,player) && ktopleftend(newboard,crow,ccol,player) && ktoprightend(newboard,crow,ccol,player))
	{
		printboard(newboard);
	}
	copy(&board[0][0],&board[0][0]+8*8,&newboard[0][0]);

	ktopright(newboard,row,col,player,crow,ccol);
	if(!compareMatrix(board,newboard)  && kleftend(newboard,crow,ccol,player) && krightend(newboard,crow,ccol,player) && ktopleftend(newboard,crow,ccol,player) && ktoprightend(newboard,crow,ccol,player))
	{
		printboard(newboard);
	}
	copy(&board[0][0],&board[0][0]+8*8,&newboard[0][0]);
}
bool kleftend(char newboard[][8],int row,int col,char player)
{
	//cout<<"In kleftend"<<endl;
	int nrow,ncol;
	if(player == 'X')
	{
		nrow = row + 2;
		ncol = col - 2;
		if((nrow >= 0 && nrow <= 7 && ncol >= 0 && nrow <= 7 && newboard[nrow][ncol] == '_'))
		{
				if(newboard[nrow-1][ncol+1] == 'O' || newboard[nrow-1][ncol+1] == 'P')
				{
					return false;
				}
		}
	}
	else if(player == 'O')
	{
		nrow = row + 2;
		ncol = col - 2;
		if((nrow >= 0 && nrow <= 7 && ncol >= 0 && nrow <= 7 && newboard[nrow][ncol] == '_'))
		{
			if(newboard[nrow-1][ncol+1] == 'X' || newboard[nrow-1][ncol+1] == 'Y')
			{
				return false;
			}
		}
	}
	return true;
}
void kjumpleft(char newboard[][8],int row,int col,char player,int &crow,int &ccol)
{
	//cout<<"In kjumpleft"<<endl;
	int nrow,ncol;
	if(player == 'X')
	{
		nrow = row + 2;
		ncol = col - 2;
		if((nrow >= 0 && nrow <= 7 && ncol >= 0 && nrow <= 7 && newboard[nrow][ncol] == '_'))
		{
			if(newboard[nrow-1][ncol+1] == 'O' || newboard[nrow-1][ncol+1] == 'P')
			{
				newboard[nrow-1][ncol+1] = '_'; //remove opponent coin
				newboard[row][col] = '_'; //remove current coin
				crow = nrow;
				ccol = ncol;
				newboard[nrow][ncol] = 'Y';
				kjump(newboard,nrow,ncol,player);
			}
		}
	}
	else if(player == 'O')
	{
		nrow = row + 2;
		ncol = col - 2;
		if((nrow >= 0 && nrow <= 7 && ncol >= 0 && nrow <= 7 && newboard[nrow][ncol] == '_'))
		{
			if(newboard[nrow-1][ncol+1] == 'X' || newboard[nrow-1][ncol+1] == 'Y')
			{
				//Then i can make a left jump
				newboard[nrow-1][ncol+1] = '_'; //remove opponent coin
				newboard[row][col] = '_'; //remove current coin
				crow = nrow;
				ccol = ncol;
				newboard[nrow][ncol] = 'P';
				kjump(newboard,nrow,ncol,player);
			}
		}
	}
}
bool krightend(char newboard[][8],int row,int col,char player)
{
	//cout<<"In krightend"<<endl;
	int nrow,ncol;
	if(player == 'X')
	{
		nrow = row + 2;
		ncol = col + 2;
		if((nrow >= 0 && nrow <= 7 && ncol >= 0 && nrow <= 7 && newboard[nrow][ncol] == '_'))
		{
			if(newboard[nrow-1][ncol-1] == 'O' || newboard[nrow-1][ncol-1] == 'P')
			{
				return false;
			}
		}
	}
	else if(player == 'O')
	{
		nrow = row + 2;
		ncol = col + 2;
		if((nrow >= 0 && nrow <= 7 && ncol >= 0 && nrow <= 7 && newboard[nrow][ncol] == '_'))
		{
			if(newboard[nrow-1][ncol-1] == 'X' || newboard[nrow-1][ncol-1] == 'Y')
			{
				return false;
			}
		}
	}
	return true;	
}
void kjumpright(char newboard[][8],int row,int col,char player,int &crow,int &ccol)
{
	//cout<<"In kjumpright"<<endl;
	int nrow,ncol;
	if(player == 'X')
	{
		nrow = row + 2;
		ncol = col + 2;
		if((nrow >= 0 && nrow <= 7 && ncol >= 0 && nrow <= 7 && newboard[nrow][ncol] == '_'))
		{
			if(newboard[nrow-1][ncol-1] == 'O' || newboard[nrow-1][ncol-1] == 'P')
			{
				newboard[nrow-1][ncol-1] = '_'; //remove opponent coin
				newboard[row][col] = '_'; //remove current coin
				crow = nrow;
				ccol = ncol;
				newboard[nrow][ncol] = 'Y';
				kjump(newboard,nrow,ncol,player);
			}
		}
	}
	else if(player == 'O')
	{
		nrow = row + 2;
		ncol = col + 2;
		if((nrow >= 0 && nrow <= 7 && ncol >= 0 && nrow <= 7 && newboard[nrow][ncol] == '_'))
		{
			if(newboard[nrow-1][ncol-1] == 'X' || newboard[nrow-1][ncol-1] == 'Y')
			{
				//Then i can make a left jump
				newboard[nrow-1][ncol-1] = '_'; //remove opponent coin
				newboard[row][col] = '_'; //remove current coin
				crow = nrow;
				ccol = ncol;
				newboard[nrow][ncol] = 'P';
				kjump(newboard,nrow,ncol,player);
			}
		}
	}
}
bool ktopleftend(char newboard[][8],int row,int col,char player)
{
	//cout<<"In ktopleftend"<<endl;
	int nrow,ncol;
	if(player == 'X')
	{
		nrow = row - 2;
		ncol = col - 2;
		if((nrow >= 0 && nrow <= 7 && ncol >= 0 && nrow <= 7 && newboard[nrow][ncol] == '_'))
		{
			if(newboard[nrow+1][ncol+1] == 'O' || newboard[nrow+1][ncol+1] == 'P')
			{
				return false;
			}
		}
	}
	else if(player == 'O')
	{
		nrow = row - 2;
		ncol = col - 2;
		if((nrow >= 0 && nrow <= 7 && ncol >= 0 && nrow <= 7 && newboard[nrow][ncol] == '_'))
		{
			if(newboard[nrow+1][ncol+1] == 'X' || newboard[nrow+1][ncol+1] == 'Y')
			{
				return false;
			}
		}	
	}
	return true;		
}
void ktopleft(char newboard[][8],int row,int col,char player,int &crow,int &ccol)
{
	//cout<<"In ktopleft"<<endl;
	int nrow,ncol;
	if(player == 'X')
	{
		nrow = row - 2;
		ncol = col - 2;
		if((nrow >= 0 && nrow <= 7 && ncol >= 0 && nrow <= 7 && newboard[nrow][ncol] == '_'))
		{
			//cout<<"Program stopped here"<<endl;
			//cout<<"nrow is:"<<nrow<<endl;
			//cout<<"ncol is:"<<ncol<<endl;
			if(newboard[nrow+1][ncol+1] == 'O' || newboard[nrow+1][ncol+1] == 'P')
			{
				newboard[nrow+1][ncol+1] = '_'; //remove opponent coin
				newboard[row][col] = '_'; //remove current coin
				crow = nrow;
				ccol = ncol;
				newboard[nrow][ncol] = 'Y';
				kjump(newboard,nrow,ncol,player);
			}
			//cout<<"Yes here"<<endl;
		}
	}
	else if(player == 'O')
	{
		nrow = row - 2;
		ncol = col - 2;
		if((nrow >= 0 && nrow <= 7 && ncol >= 0 && nrow <= 7 && newboard[nrow][ncol] == '_'))
		{
			if(newboard[nrow+1][ncol+1] == 'X' || newboard[nrow+1][ncol+1] == 'Y')
			{
				//Then i can make a left jump
				newboard[nrow+1][ncol+1] = '_'; //remove opponent coin
				newboard[row][col] = '_'; //remove current coin
				crow = nrow;
				ccol = ncol;
				newboard[nrow][ncol] = 'P';
				kjump(newboard,nrow,ncol,player);
			}
		}	
	}
}
bool ktoprightend(char newboard[][8],int row,int col,char player)
{
	//cout<<"In ktoprightend"<<endl;
	int nrow,ncol;
	if(player == 'X')
	{
		nrow = row - 2;
		ncol = col + 2;
		if((nrow >= 0 && nrow <= 7 && ncol >= 0 && nrow <= 7 && newboard[nrow][ncol] == '_'))
		{
			if(newboard[nrow+1][ncol-1] == 'O' || newboard[nrow+1][ncol-1] == 'P')
			{
				return false;
			}
		}
	}
	else if(player == 'O')
	{
		nrow = row - 2;
		ncol = col + 2;
		if((nrow >= 0 && nrow <= 7 && ncol >= 0 && nrow <= 7 && newboard[nrow][ncol] == '_'))
		{
			if(newboard[nrow+1][ncol-1] == 'X' || newboard[nrow+1][ncol-1] == 'Y')
			{
				return false;
			}
		}
	}
	return true;		
}
void ktopright(char newboard[][8],int row,int col,char player,int &crow,int &ccol)
{
	//cout<<"In ktopright"<<endl;
	int nrow,ncol;
	if(player == 'X')
	{
		nrow = row - 2;
		ncol = col + 2;
		if((nrow >= 0 && nrow <= 7 && ncol >= 0 && nrow <= 7 && newboard[nrow][ncol] == '_'))
		{
			if(newboard[nrow+1][ncol-1] == 'O' || newboard[nrow+1][ncol-1] == 'P')
			{
				newboard[nrow+1][ncol-1] = '_'; //remove opponent coin
				newboard[row][col] = '_'; //remove current coin
				crow = nrow;
				ccol = ncol;
				newboard[nrow][ncol] = 'Y';
				kjump(newboard,nrow,ncol,player);
			}
		}
	}
	else if(player == 'O')
	{
		nrow = row - 2;
		ncol = col + 2;
		if((nrow >= 0 && nrow <= 7 && ncol >= 0 && nrow <= 7 && newboard[nrow][ncol] == '_'))
		{
			if(newboard[nrow+1][ncol-1] == 'X' || newboard[nrow+1][ncol-1] == 'Y')
			{
				//Then i can make a left jump
				newboard[nrow+1][ncol-1] = '_'; //remove opponent coin
				newboard[row][col] = '_'; //remove current coin
				crow = nrow;
				ccol = ncol;
				newboard[nrow][ncol] = 'P';
				kjump(newboard,nrow,ncol,player);
			}
		}
	}
}
void jump(char board[][8],int row,int col,char player)
{
	//create a copy of board
	int crow,ccol;
	crow = row;
	ccol = col;
	char newboard[8][8];
	copy(&board[0][0],&board[0][0]+8*8,&newboard[0][0]);
	jumpleft(newboard,row,col,player,crow,ccol);
	//Check if the newboard is changed --- compare newboard with board
	//If changed then it is an action print it and copy back board in newboard
	//and call jumpright 
	//else call jumpight
	if(!compareMatrix(board,newboard) && leftEnd(newboard,crow,ccol,player) && rightEnd(newboard,crow,ccol,player))  
	//add more conditions that the board cannot have any more jumps (left and right)
	{
		//board changed.It's an Action
		/*
		cout<<"Printing after jumpleft"<<endl;
		cout<<"Row is:"<<crow<<endl;
		cout<<"Col is:"<<ccol<<endl;
		cout<<"Left End is: "<<leftEnd(newboard,crow,ccol,player)<<endl;
		cout<<"Right End is: "<<rightEnd(newboard,crow,ccol,player)<<endl;
		*/
		printboard(newboard);
	}
	copy(&board[0][0],&board[0][0]+8*8,&newboard[0][0]);
	jumpright(newboard,row,col,player,crow,ccol);
	if(!compareMatrix(board,newboard) && leftEnd(newboard,crow,ccol,player) && rightEnd(newboard,crow,ccol,player))
	//add more conditions that the board cannot have any more jumps (left and right)
	{
		//board changed.It's an Action
		/*
		cout<<"Printing after jumpright"<<endl;
		cout<<"Row is:"<<crow<<endl;
		cout<<"Col is:"<<ccol<<endl;
		cout<<"Left End is: "<<leftEnd(newboard,row,col,player)<<endl;
		cout<<"Right End is: "<<rightEnd(newboard,row,col,player)<<endl;
		*/
		printboard(newboard);
	}
	copy(&board[0][0],&board[0][0]+8*8,&newboard[0][0]);
}
void jumpleft(char newboard[][8],int row,int col,char player,int &crow,int &ccol)
{
	int nrow,ncol;
	if(player == 'X')
	{
		nrow = row + 2;
		ncol = col - 2;
		if((nrow >= 0 && nrow <= 7 && ncol >= 0 && nrow <= 7 && newboard[nrow][ncol] == '_'))
		{
			if(newboard[nrow-1][ncol+1] == 'O' || newboard[nrow-1][ncol+1] == 'P')
			{
				//Then i can make a left jump
				newboard[nrow-1][ncol+1] = '_'; //remove opponent coin
				newboard[row][col] = '_'; //remove current coin
				//Checking if the new position will make the current player a king or not
				crow = nrow;
				ccol = ncol;
				if(checkKing(nrow,player))
					newboard[nrow][ncol] = 'Y';
				else
				{
					newboard[nrow][ncol] = 'X';
					jump(newboard,nrow,ncol,player);
				}
			}
		}
	}
	else if(player == 'O')
	{
		nrow = row - 2;
		ncol = col - 2;
		if((nrow >= 0 && nrow <= 7 && ncol >= 0 && nrow <= 7 && newboard[nrow][ncol] == '_'))
		{
			if(newboard[nrow+1][ncol+1] == 'X' || newboard[nrow+1][ncol+1] == 'Y')
			{
				//Then i can make a left jump
				newboard[nrow+1][ncol+1] = '_'; //remove opponent coin
				newboard[row][col] = '_'; //remove current coin
				//Checking if the new position will make the current player a king or not
				crow = nrow;
				ccol = ncol;
				if(checkKing(nrow,player))
					newboard[nrow][ncol] = 'P';
				else
				{
					newboard[nrow][ncol] = 'O';
					jump(newboard,nrow,ncol,player);
				}
			}
		}	
	}
}
void jumpright(char newboard[][8],int row,int col,char player,int &crow,int &ccol)
{
	int nrow,ncol;
	if(player == 'X')
	{
		nrow = row + 2;
		ncol = col + 2;
		if((nrow >= 0 && nrow <= 7 && ncol >= 0 && nrow <= 7 && newboard[nrow][ncol] == '_'))
		{
			if(newboard[nrow-1][ncol-1] == 'O' || newboard[nrow-1][ncol-1] == 'P')
			{
				//Then i can make a left jump
				newboard[nrow-1][ncol-1] = '_'; //remove opponent coin
				newboard[row][col] = '_'; //remove current coin
				crow = nrow;
				ccol = ncol;
				//Checking if the new position will make the current player a king or not
				if(checkKing(nrow,player))
					newboard[nrow][ncol] = 'Y';
				else
				{
					newboard[nrow][ncol] = 'X';
					jump(newboard,nrow,ncol,player);
				}
			}
		}
	}
	else if(player == 'O')
	{
		nrow = row - 2;
		ncol = col + 2;
		if((nrow >= 0 && nrow <= 7 && ncol >= 0 && nrow <= 7 && newboard[nrow][ncol] == '_'))
		{
			if(newboard[nrow+1][ncol-1] == 'X' || newboard[nrow+1][ncol-1] == 'Y')
			{
				//Then i can make a left jump
				newboard[nrow+1][ncol-1] = '_'; //remove opponent coin
				newboard[row][col] = '_'; //remove current coin
				crow = nrow;
				ccol = ncol;
				//Checking if the new position will make the current player a king or not
				if(checkKing(nrow,player))
					newboard[nrow][ncol] = 'P';
				else
				{
					newboard[nrow][ncol] = 'O';
					jump(newboard,nrow,ncol,player);
				}
			}
		}	
	}	
}
bool checkLeft(char board[][8],int row,int col,char player)
/*
Returns true if you can move left from the current position
(row,col) else false
*/
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
/*
Returns true if you can move right from the current position
(row,col) else false
*/
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