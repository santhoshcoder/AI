#include <iostream>
#include <vector>
using namespace std;
int moveCount = 0;
int utilityCount(char b[8][8]);
class Node
{
public:
	char board[8][8],player;
	vector<Node>childs;
	int v;
	int move;
	void setBoard(char b[][8]);
	void displayBoard();
	void setPlayer(char);
	void printActions();
	void actions();
	int  utility();
	bool checkKing(int row,char player);
	bool leftEnd(char board[][8],int row,int col,char player);
	bool rightEnd(char board[][8],int row,int col,char player);
	bool checkLeft(char board[][8],int row,int col,char player);
	bool checkRight(char board[][8],int row,int col,char player);	
	bool compareMatrix(char [][8],char [][8]);
	void kjump(char [][8],int,int,char);
	void jump(char [][8],int,int,char);
	void jumpleft(char newboard[][8],int row,int col,char player,int &,int &);
	void jumpright(char newboard[][8],int row,int col,char player,int &,int &);
	void kjumpleft(char newboard[][8],int row,int col,char player,int &crow,int &ccol);
	void kjumpright(char newboard[][8],int row,int col,char player,int &crow,int &ccol);
	void ktopleft(char newboard[][8],int row,int col,char player,int &crow,int &ccol);
	void ktopright(char newboard[][8],int row,int col,char player,int &crow,int &ccol);
	bool kleftend(char board[][8],int row,int col,char player);
	bool krightend(char board[][8],int row,int col,char player);
	bool ktopleftend(char board[][8],int row,int col,char player);
	bool ktoprightend(char board[][8],int row,int col,char player);
	bool terminal();
};
void alpha_beta_search(Node n,char [][8]);
int max_value(Node &n, int alpha, int beta);
int min_value(Node &n, int alpha, int beta);
void printBoard(char s[][8]);
int Node::utility()
{
	if(childs.size() == 0)
	{
		if(player == 'X')
			return -20;
		else
			return 20;
	}
	//else if(move >= 10)
	return utilityCount(board);
	//Need to add more functions to check if it's a Tie or if there are more no of moves
}
bool Node::terminal()
{
	//If there are no actions then return true
	if(childs.size() == 0)
		return true;
	if(move >= 10)
	{
		return true;
	}
	return false;
	//There can be many more conditions
	//1) The game contines and cannot stop i.e in like 100 steps or something like that
}
void Node::printActions()
{
	if(childs.size() == 0)
	{
		//cout<<"No Actions for the current Node"<<endl;
	}
	else
	{
		cout<<endl<<"***************************************"<<endl;
		cout<<"Printing Actions Start";
		cout<<endl<<"***************************************"<<endl;
		for(int i = 0;i < childs.size();i++)
		{
			childs[i].displayBoard();
		}
		cout<<endl<<"***************************************"<<endl;
		cout<<"Printing Actions End";
		cout<<endl<<"***************************************"<<endl;
	}
}
void Node::	displayBoard()
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
void Node::setBoard(char b[][8])
{
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
		{
			board[i][j] = b[i][j];
		}
	}
}
void Node::setPlayer(char p)
{
	player = p;
}
bool Node::checkKing(int row,char player)
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
bool Node::leftEnd(char board[][8],int row,int col,char player)
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
bool Node::rightEnd(char board[][8],int row,int col,char player)
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
void Node::actions()
{
	moveCount++;
	for(int i = 0;i < 8;i++)
	{
		for(int j = 0;j < 8;j++)
		{
			if(board[i][j] != '_')
			{
				if(player == 'X' && board[i][j] == 'X')//Computer normal player
				{
					//cout<<"Computer Normal player"<<endl;
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
						//printboard(newboard);
						//Action
						Node child1;
						child1.setBoard(newboard);
						char newplayer = (player == 'X')?'O':'X';
						child1.setPlayer(newplayer);
						child1.move = move+1;
						childs.push_back(child1);
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
						//printboard(newboard);
						//Action
						Node child1;
						child1.setBoard(newboard);
						char newplayer = (player == 'X')?'O':'X';
						child1.setPlayer(newplayer);
						child1.move = move+1;
						childs.push_back(child1);
						copy(&board[0][0],&board[0][0]+8*8,&newboard[0][0]);
					}
					//Check jumps
					jump(board,i,j,player);
				}
				else if(player == 'O' && board[i][j] == 'O') //user normal player
				{
					//cout<<"User Normal player"<<endl;
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
						//printboard(newboard);
						//Action
						Node child1;
						child1.setBoard(newboard);
						char newplayer = (player == 'X')?'O':'X';
						child1.setPlayer(newplayer);
						child1.move = move+1;
						childs.push_back(child1);
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
						//printboard(newboard);
						//Action
						Node child1;
						child1.setBoard(newboard);
						char newplayer = (player == 'X')?'O':'X';
						child1.setPlayer(newplayer);
						child1.move = move+1;
						childs.push_back(child1);
						copy(&board[0][0],&board[0][0]+8*8,&newboard[0][0]);
					}
					//Check jumps
					jump(board,i,j,player);
				}
				if(player == 'X' && board[i][j] == 'Y') //Computer player turned king
				{
					//cout<<"Computer player turned king"<<endl;
					char newboard[8][8];
					copy(&board[0][0],&board[0][0]+8*8,&newboard[0][0]);
					//Check left diagnoal 'X'
					if(checkLeft(board,i,j,'X'))
					{
						//I can move left
						newboard[i+1][j-1] = 'Y';
						newboard[i][j] = '_';
						//printboard(newboard);
						//Action
						Node child1;
						child1.setBoard(newboard);
						char newplayer = (player == 'X')?'O':'X';
						child1.setPlayer(newplayer);
						child1.move = move+1;
						childs.push_back(child1);
						copy(&board[0][0],&board[0][0]+8*8,&newboard[0][0]);
					}
					//Check right diagnoal 'X'
					if(checkRight(board,i,j,'X'))
					{
						//I can move right
						newboard[i+1][j+1] = 'Y';
						newboard[i][j] = '_';
						//printboard(newboard);
						//Action
						Node child1;
						child1.setBoard(newboard);
						char newplayer = (player == 'X')?'O':'X';
						child1.setPlayer(newplayer);
						child1.move = move+1;
						childs.push_back(child1);
						copy(&board[0][0],&board[0][0]+8*8,&newboard[0][0]);
					}
					//Check left diagnoal 'O';
					if(checkLeft(board,i,j,'O'))
					{
						//I can move left
						newboard[i-1][j-1] = 'Y';
						newboard[i][j] = '_';
						//printboard(newboard);
						//Action
						Node child1;
						child1.setBoard(newboard);
						char newplayer = (player == 'X')?'O':'X';
						child1.setPlayer(newplayer);
						child1.move = move+1;
						childs.push_back(child1);
						copy(&board[0][0],&board[0][0]+8*8,&newboard[0][0]);
					}
					//Check right diagnoal 'O'
					if(checkRight(board,i,j,'O'))
					{
						//I can move right
						newboard[i-1][j+1] = 'Y';
						newboard[i][j] = '_';
						//printboard(newboard);
						//Action
						Node child1;
						child1.setBoard(newboard);
						char newplayer = (player == 'X')?'O':'X';
						child1.setPlayer(newplayer);
						child1.move = move+1;
						childs.push_back(child1);
						copy(&board[0][0],&board[0][0]+8*8,&newboard[0][0]);
					}		
					//Check jumps
					//cout<<"Calling kjump"<<endl;
					kjump(board,i,j,player);		
				}
				if(player == 'O' && board[i][j] == 'P') //User player turned king
				{
					//cout<<"User player turned king"<<endl;
					char newboard[8][8];
					copy(&board[0][0],&board[0][0]+8*8,&newboard[0][0]);
					//Check left diagnoal 'X'
					if(checkLeft(board,i,j,'X'))
					{
						//I can move left
						newboard[i+1][j-1] = 'P';
						newboard[i][j] = '_';
						//printboard(newboard);
						//Action
						Node child1;
						child1.setBoard(newboard);
						char newplayer = (player == 'X')?'O':'X';
						child1.setPlayer(newplayer);
						child1.move = move+1;
						childs.push_back(child1);
						copy(&board[0][0],&board[0][0]+8*8,&newboard[0][0]);
					}
					//Check right diagnoal 'X'
					if(checkRight(board,i,j,'X'))
					{
						//I can move right
						newboard[i+1][j+1] = 'P';
						newboard[i][j] = '_';
						//printboard(newboard);
						//Action
						Node child1;
						child1.setBoard(newboard);
						char newplayer = (player == 'X')?'O':'X';
						child1.setPlayer(newplayer);
						child1.move = move+1;
						childs.push_back(child1);
						copy(&board[0][0],&board[0][0]+8*8,&newboard[0][0]);
					}
					//Check left diagnoal 'O';
					if(checkLeft(board,i,j,'O'))
					{
						//I can move left
						newboard[i-1][j-1] = 'P';
						newboard[i][j] = '_';
						//printboard(newboard);
						//Action
						Node child1;
						child1.setBoard(newboard);
						char newplayer = (player == 'X')?'O':'X';
						child1.setPlayer(newplayer);
						child1.move = move+1;
						childs.push_back(child1);
						copy(&board[0][0],&board[0][0]+8*8,&newboard[0][0]);
					}
					//Check right diagnoal 'O'
					if(checkRight(board,i,j,'O'))
					{
						//I can move right
						newboard[i-1][j+1] = 'P';
						newboard[i][j] = '_';
						//printboard(newboard);
						//Action
						Node child1;
						child1.setBoard(newboard);
						char newplayer = (player == 'X')?'O':'X';
						child1.setPlayer(newplayer);
						child1.move = move+1;
						childs.push_back(child1);
						copy(&board[0][0],&board[0][0]+8*8,&newboard[0][0]);
					}		
					//Check jumps
					//cout<<"Calling kjump in user player turned king"<<endl;
					kjump(board,i,j,player);		
				}
			}
		}
	}	
}
bool Node::compareMatrix(char s[][8],char d[][8])
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
void Node::kjump(char board[][8],int row,int col,char player)
{
	int crow,ccol;
	crow = row;
	ccol = col;
	char newboard[8][8];
	copy(&board[0][0],&board[0][0]+8*8,&newboard[0][0]);

	kjumpleft(newboard,row,col,player,crow,ccol);
	if(!compareMatrix(board,newboard) && kleftend(newboard,crow,ccol,player) && krightend(newboard,crow,ccol,player) && ktopleftend(newboard,crow,ccol,player) && ktoprightend(newboard,crow,ccol,player)) 
	{
		//printboard(newboard);
		//Action
		Node child1;
		child1.setBoard(newboard);
		char newplayer = (player == 'X')?'O':'X';
		child1.setPlayer(newplayer);
		child1.move = move+1;
		childs.push_back(child1);
	}
	copy(&board[0][0],&board[0][0]+8*8,&newboard[0][0]);
	
	kjumpright(newboard,row,col,player,crow,ccol);
	if(!compareMatrix(board,newboard) && kleftend(newboard,crow,ccol,player) && krightend(newboard,crow,ccol,player) && ktopleftend(newboard,crow,ccol,player) && ktoprightend(newboard,crow,ccol,player))
	{
		//printboard(newboard);
		//Action
		Node child1;
		child1.setBoard(newboard);
		char newplayer = (player == 'X')?'O':'X';
		child1.setPlayer(newplayer);
		child1.move = move+1;
		childs.push_back(child1);
	}
	copy(&board[0][0],&board[0][0]+8*8,&newboard[0][0]);
	
	ktopleft(newboard,row,col,player,crow,ccol);
	if(!compareMatrix(board,newboard)  && kleftend(newboard,crow,ccol,player) && krightend(newboard,crow,ccol,player) && ktopleftend(newboard,crow,ccol,player) && ktoprightend(newboard,crow,ccol,player))
	{
		//printboard(newboard);
		//Action
		Node child1;
		child1.setBoard(newboard);
		char newplayer = (player == 'X')?'O':'X';
		child1.setPlayer(newplayer);
		child1.move = move+1;
		childs.push_back(child1);
	}
	copy(&board[0][0],&board[0][0]+8*8,&newboard[0][0]);

	ktopright(newboard,row,col,player,crow,ccol);
	if(!compareMatrix(board,newboard)  && kleftend(newboard,crow,ccol,player) && krightend(newboard,crow,ccol,player) && ktopleftend(newboard,crow,ccol,player) && ktoprightend(newboard,crow,ccol,player))
	{
		//printboard(newboard);
		//Action
		Node child1;
		child1.setBoard(newboard);
		char newplayer = (player == 'X')?'O':'X';
		child1.setPlayer(newplayer);
		child1.move = move+1;
		childs.push_back(child1);
	}
	copy(&board[0][0],&board[0][0]+8*8,&newboard[0][0]);
}
bool Node::kleftend(char newboard[][8],int row,int col,char player)
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
void Node::kjumpleft(char newboard[][8],int row,int col,char player,int &crow,int &ccol)
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
bool Node::krightend(char newboard[][8],int row,int col,char player)
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
void Node::kjumpright(char newboard[][8],int row,int col,char player,int &crow,int &ccol)
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
bool Node::ktopleftend(char newboard[][8],int row,int col,char player)
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
void Node::ktopleft(char newboard[][8],int row,int col,char player,int &crow,int &ccol)
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
bool Node::ktoprightend(char newboard[][8],int row,int col,char player)
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
void Node::ktopright(char newboard[][8],int row,int col,char player,int &crow,int &ccol)
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
void Node::jump(char board[][8],int row,int col,char player)
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
		//printboard(newboard);
		//Action
		Node child1;
		child1.setBoard(newboard);
		char newplayer = (player == 'X')?'O':'X';
		child1.setPlayer(newplayer);
		child1.move = move+1;
		childs.push_back(child1);
	}
	copy(&board[0][0],&board[0][0]+8*8,&newboard[0][0]);
	jumpright(newboard,row,col,player,crow,ccol);
	if(!compareMatrix(board,newboard) && leftEnd(newboard,crow,ccol,player) && rightEnd(newboard,crow,ccol,player))
	//add more conditions that the board cannot have any more jumps (left and right)
	{
		//board changed.It's an Action
		//printboard(newboard);
		//Action
		Node child1;
		child1.setBoard(newboard);
		char newplayer = (player == 'X')?'O':'X';
		child1.setPlayer(newplayer);
		child1.move = move+1;
		childs.push_back(child1);
	}
	copy(&board[0][0],&board[0][0]+8*8,&newboard[0][0]);
}
void Node::jumpleft(char newboard[][8],int row,int col,char player,int &crow,int &ccol)
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
void Node::jumpright(char newboard[][8],int row,int col,char player,int &crow,int &ccol)
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
bool Node::checkLeft(char board[][8],int row,int col,char player)
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
bool Node::checkRight(char board[][8],int row,int col,char player)
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

/* Main Functions Alpha-Beta-Search */
void printBoard(char array2D[][8])
{
	cout << endl << "***************" << endl;
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
			cout<<array2D[i][j]<<" ";
		}
		cout<<endl;
	}
	cout << endl << "***************" << endl;
}

void alpha_beta_search(Node n,char array2D[][8]) 
{
	n.v = max_value(n,-100,100);
	//cout<<"Selected v value in alpha_beta_search is:"<<n.v<<endl;
	//cout<<"No of Chils for this node are: "<<n.childs.size()<<endl;
	for(int i = 0; i < n.childs.size();i++)
	{
		//cout<<"Action "<<(i+1)<<"Utility value is: "<<n.childs[i].utility()<<endl;
		if(n.childs[i].childs.size() == 0 && n.childs[i].utility() != 0)
		{
			for(int h = 0; h < 8;h++)
			{
				for(int w = 0; w < 8; w++)
				{
					array2D[h][w] = n.childs[i].board[h][w];
				}
			}
			return ;
		}
	}
	for (int i = 0; i < n.childs.size(); i++) 
	{
		if (n.childs[i].v == n.v) 
		{
			// found store it into a 2-D array and return the array
			//cout<<"Found"<<endl;
			for(int h = 0; h < 8 ;h++)
			{
				for(int w = 0; w < 8; w++)
				{
					array2D[h][w] = n.childs[i].board[h][w];
				}
			}
			return ;
		}
	}
}
int max_value(Node &n,int alpha,int beta)
{
	//cout<<"Max Start"<<endl;
	//cout<<"Called Max Function"<<endl;
	//cout<<"Checking win returned"<<n.checkingWin()<<endl;
	//cout<<"Action Start"<<endl;
	n.actions();
	//cout<<"Actions End"<<endl;
	//cout<<"If Called"<<endl;
	if(n.terminal() == true)
	{
		n.v = n.utility();
		//cout<<"Max End"<<endl;
		return n.utility();
	}
	//cout<<"If End"<<endl;
	n.v = -5;
	//cout<<"Childs size is:"<<<<endl;
	//n.displayBoard();
	//cout<<"For loop Started"<<endl;
	//cout<<"MoveCount is:"<<moveCount<<endl;
	for(int i = 0; i < n.childs.size(); i++)
	{
		n.v = max(n.v,min_value(n.childs[i],alpha,beta));
		//cout<<"Called Max Again"<<endl;
		if (n.v >= beta)
		{
			//cout<<"Max End"<<endl;
			return n.v;
		}
		alpha = max(alpha,n.v);
	}
	//cout<<"For Loop End"<<endl;
	//cout<<"Max End"<<endl;
	return n.v;
}
int min_value(Node &n,int alpha,int beta)
{
	//cout<<"Min Start"<<endl;
	n.actions();
	if(n.terminal())
	{
		n.v = n.utility();
		//cout<<"Min End"<<endl;
		return n.utility();
	}
	n.v = 5;
	for(int i = 0; i < n.childs.size(); i++)
	{
		n.v = min(n.v,max_value(n.childs[i],alpha,beta));
		if (n.v <= alpha)
		{
			//cout<<"Min End"<<endl;
			return n.v;
		}
		beta = min(beta,n.v);
	}
	//cout<<"Min End"<<endl;
	return n.v;
}
bool checkPlayersEquality(char u[][8],char a[][8])
{
	//Check if the 'O' or 'P' in u are in the same exact position in a
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
		{
			if((u[i][j] == 'O' || u[i][j] == 'P') && (u[i][j] != a[i][j]))
			{
				//cout<<"u[i][j]: "<<u[i][j]<<endl;
				//cout<<"a[i][j]: "<<a[i][j]<<endl;
				return false;
			}
		}
	}
	return true;
}
int utilityCount(char b[8][8])
{
	int xcount = 0,ocount = 0;
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
		{
			if(b[i][j] == 'X' || b[i][j] == 'Y')
				xcount++;
			else if(b[i][j] == 'O' || b[i][j] == 'P')
				ocount++;
		}
	}
	return xcount - ocount;
}
int main()
{
	char player = 'X';
	int row,column,nrow,ncolumn;
	char flag = false;
	bool flag2 = true;
	char newboard[8][8];
	int  count = 0;
	char board[8][8] = 
	{
		{'_','X','_','X','_','X','_','X'},
		{'X','_','X','_','X','_','X','_'},
		{'_','X','_','X','_','X','_','X'},
		{'_','_','_','_','_','_','_','_'},
		{'_','_','_','_','_','_','_','_'},
		{'O','_','O','_','O','_','O','_'},
		{'_','O','_','O','_','O','_','O'},
		{'O','_','O','_','O','_','O','_'}
	};

	while(flag2)
	{
		Node test;
		test.setBoard(board);
		test.setPlayer('X');
		//test.move = count;
		test.move = 0;
		count++;
		alpha_beta_search(test,board);
		cout<<"After Computer Turn board is:"<<endl;
		//moveCount++;
		printBoard(board);
		Node test1;
		test1.setBoard(board);
		test1.setPlayer('O');
		//test1.move = count;
		test1.move = 0;
		count++;
		test1.actions();
		//if(moveCount >=200)
		//{
		//moveCount = 0;
		//}
		if(test1.terminal())
		{
			int w = test1.utility();
			if(w == 1)
			{
				cout<<"Computer Won the game"<<endl;
				exit(0);
			}
			else if(w == -1)
			{
				cout<<"You Won the game"<<endl;
				exit(0);
			}
			else
			{
				cout<<"Game Tie"<<endl;
				exit(0);
			}
		}
		cout << "Your Turn"<<endl;
		//Create a copy of board and store it in newboard and do the following changed on new board
		for(int i=0;i<8;i++)
		{
			for(int j=0;j<8;j++)
			{
				newboard[i][j] = board[i][j];
			}
		}
		do
		{
			do
			{
				cout << "Choose a Row to move from(0-7): ";
				cin >> row;
				cout << "Choose a Column to move from(0-7): "<<endl;
				cin >> column;
				cout <<"Choose a Row to make a move to that position(0-7): ";
				cin>>nrow;
				cout<<"Choose a Column to make a move to that position(0-7): ";
				cin>>ncolumn;
				//Both the columns should match and that move should be valid
				if(!((row >=0 && row <=7) && (column >=0 && column <=7) && (nrow >=0 && nrow <=7) && (ncolumn >=0 && ncolumn <=7)))
				{
					cout<<"Invalid row and Column Selected"<<endl;
					flag = true;
				}
				else
				{
					flag = false;
				}
			}while(flag);
			if(flag)
				cout<<"True"<<endl;
			else
				cout<<"False"<<endl;
			Node test2;
			test2.setBoard(newboard);
			test2.setPlayer('O');
			test2.move = 0;
			count++;
			test2.actions();
			//cout<<"Printing Actions"<<endl;
			//test2.printActions();
			//The move can make the player coin a king
			if(nrow == 0)
			{
				newboard[nrow][ncolumn] = 'P';
			}
			else
			{
				newboard[nrow][ncolumn] = newboard[row][column];
			}
			newboard[row][column] = '_';
			//printBoard(newboard);
			//To make sure that the move is valid derive the actions of the board(test object) after the computer move and check if the user
			//move can be allowed
			int count = 0;
			for(int i=0;i<test2.childs.size();i++)
			{
				if(checkPlayersEquality(newboard,test2.childs[i].board))
				{
					//copy the action into board
					//cout<<"Action Found"<<endl;
					for(int j=0;j<8;j++)
					{
						for(int k=0;k<8;k++)
							board[j][k] = test2.childs[i].board[j][k];
					}
					count++;
					break;
				}
			}
			if(count == 0)
			{
				//Action cannot be made
				flag = true;
				cout<<"Action Cannot be made.Choose a Valid Action"<<endl;
				for(int i=0;i<8;i++)
				{
					for(int j=0;j<8;j++)
					{
						newboard[i][j] = board[i][j];
					}
				}
			}
			else
			{
				//Action can be made
				flag = false;
			}
		}while(flag);
		cout<<"After Your Turn board is:"<<endl;
		//moveCount++;
		printBoard(board);
		Node test3;
		test3.setBoard(board);
		test3.setPlayer('X');
		test3.move = 0;
		count++;
		test3.actions();
		//if(moveCount >=200)
		//{
		//moveCount = 0;
		//}
		if(test3.terminal())
		{
			int w = test3.utility();
			if(w == 1)
			{
				cout<<"Computer Won the game"<<endl;
				exit(0);
			}
			else if(w == -1)
			{
				cout<<"You Won the game"<<endl;
				exit(0);
			}
			else
			{
				cout<<"Game Tie"<<endl;
				exit(0);
			}	
		}
	}
}
