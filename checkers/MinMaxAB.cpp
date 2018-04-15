#include <iostream>
#include <vector>
using namespace std;

int moveCount = 0;
int NodeCount = 0;
int options;

class Node
{
public:
	int utilityCount();
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
vector<Node> bestPath;
void printBoard(char s[][8]);

int Node::utility()
{
	if(options == 1)
	{
		if(childs.size() == 0)
		{
			if(player == 'X')
				return -20;
			else
				return 20;
		}
	}
	else if(options == 2)
	{
		if(childs.size() == 0)
		{
			if(player == 'X')
				return 20;
			else
				return -20;
		}
	}
	return utilityCount();
}
bool Node::terminal()
{
	//If there are no actions then return true
	if(childs.size() == 0)
		return true;
	if(move >= 1)
	{
		return true;
	}
	return false;
	//There can be many more conditions
	//1) The game continues and cannot stop i.e in like 100 steps or something like that
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
		if((nrow >= 0 && nrow <= 7 && ncol >= 0 && ncol <= 7 && board[nrow][ncol] == '_'))
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
		if((nrow >= 0 && nrow <= 7 && ncol >= 0 && ncol <= 7 && board[nrow][ncol] == '_'))
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
		if((nrow >= 0 && nrow <= 7 && ncol >= 0 && ncol <= 7 && board[nrow][ncol] == '_'))
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
		if((nrow >= 0 && nrow <= 7 && ncol >= 0 && ncol <= 7 && board[nrow][ncol] == '_'))
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
						NodeCount++;
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
						NodeCount++;
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
						NodeCount++;
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
						NodeCount++;
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
						NodeCount++;
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
						NodeCount++;
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
						NodeCount++;
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
						NodeCount++;
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
						NodeCount++;
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
						NodeCount++;
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
						NodeCount++;
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
						NodeCount++;
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
		NodeCount++;
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
		NodeCount++;
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
		NodeCount++;
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
		NodeCount++;
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
		if((nrow >= 0 && nrow <= 7 && ncol >= 0 && ncol <= 7 && newboard[nrow][ncol] == '_'))
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
		if((nrow >= 0 && nrow <= 7 && ncol >= 0 && ncol <= 7 && newboard[nrow][ncol] == '_'))
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
		if((nrow >= 0 && nrow <= 7 && ncol >= 0 && ncol <= 7 && newboard[nrow][ncol] == '_'))
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
		if((nrow >= 0 && nrow <= 7 && ncol >= 0 && ncol <= 7 && newboard[nrow][ncol] == '_'))
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
		if((nrow >= 0 && nrow <= 7 && ncol >= 0 && ncol <= 7 && newboard[nrow][ncol] == '_'))
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
		if((nrow >= 0 && nrow <= 7 && ncol >= 0 && ncol <= 7 && newboard[nrow][ncol] == '_'))
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
		if((nrow >= 0 && nrow <= 7 && ncol >= 0 && ncol <= 7 && newboard[nrow][ncol] == '_'))
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
		if((nrow >= 0 && nrow <= 7 && ncol >= 0 && ncol <= 7 && newboard[nrow][ncol] == '_'))
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
		if((nrow >= 0 && nrow <= 7 && ncol >= 0 && ncol <= 7 && newboard[nrow][ncol] == '_'))
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
		if((nrow >= 0 && nrow <= 7 && ncol >= 0 && ncol <= 7 && newboard[nrow][ncol] == '_'))
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
		if((nrow >= 0 && nrow <= 7 && ncol >= 0 && ncol <= 7 && newboard[nrow][ncol] == '_'))
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
		if((nrow >= 0 && nrow <= 7 && ncol >= 0 && ncol <= 7 && newboard[nrow][ncol] == '_'))
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
		if((nrow >= 0 && nrow <= 7 && ncol >= 0 && ncol <= 7 && newboard[nrow][ncol] == '_'))
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
		if((nrow >= 0 && nrow <= 7 && ncol >= 0 && ncol <= 7 && newboard[nrow][ncol] == '_'))
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
		if((nrow >= 0 && nrow <= 7 && ncol >= 0 && ncol <= 7 && newboard[nrow][ncol] == '_'))
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
		if((nrow >= 0 && nrow <= 7 && ncol >= 0 && ncol <= 7 && newboard[nrow][ncol] == '_'))
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
		NodeCount++;
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
		NodeCount++;
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
		if((nrow >= 0 && nrow <= 7 && ncol >= 0 && ncol <= 7 && newboard[nrow][ncol] == '_'))
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
		if((nrow >= 0 && nrow <= 7 && ncol >= 0 && ncol <= 7 && newboard[nrow][ncol] == '_'))
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
		if((nrow >= 0 && nrow <= 7 && ncol >= 0 && ncol <= 7 && newboard[nrow][ncol] == '_'))
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
		if((nrow >= 0 && nrow <= 7 && ncol >= 0 && ncol <= 7 && newboard[nrow][ncol] == '_'))
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

bool checkPlayersEquality(char u[][8],char a[][8])
{
	//Check if the 'O' or 'P' in u are in the same exact position in a
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
		{
			if((a[i][j] == 'O' || a[i][j] == 'P') && (u[i][j] != a[i][j]))
			{
				//cout<<"u[i][j]: "<<u[i][j]<<endl;
				//cout<<"a[i][j]: "<<a[i][j]<<endl;
				return false;
			}
		}
	}
	return true;
}
int Node::utilityCount()
{
	int xcount = 0,ocount = 0;
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
		{
			if(board[i][j] == 'X' || board[i][j] == 'Y')
				xcount++;
			else if(board[i][j] == 'O' || board[i][j] == 'P')
				ocount++;
		}
	}
	if(options == 1)
		return xcount - ocount;
	return ocount - xcount;
}
bool DeepEnough(int d)
{
	return d >= 2;
}	
Node MinMaxAB(Node &b,int depth,char player,int ut,int pt)
{
	if(DeepEnough(depth))
	{
		b.v = b.utility();
		return b;
	}
	b.actions(); // Generating one ply
	if(b.childs.size() == 0)
	{
		b.v = b.utility();
		return b;
	}
	for(int i = 0;i<b.childs.size();i++)
	{
		Node ResultSucc = MinMaxAB(b.childs[i],b.childs[i].move,b.childs[i].player,-1*pt,-1*ut);
		int newValue = -1 * ResultSucc.v;
		if(newValue > pt)
		{
			pt = newValue;
			bestPath.push_back(b.childs[i]);
			/*
			if(b.childs[i].move == 1)
			{
				cout<<"Depth 1 is pushed"<<endl;
				printBoard(b.childs[i].board);
			}
			else
			{
				cout<<"Depth 1 is not pushed"<<endl;
			}
			*/
		}
		if(pt >= ut)
		{
			b.childs[i].v = pt;
			return b.childs[i];
		}
	}
	b.v = pt;
	return b;
}
void comVcom(char &player,int &row,int &column,int &nrow,int &ncolumn,bool &flag,bool &flag2,char board[][8],char newboard[][8])
{
	while(flag2)
	{
		bestPath.clear();
		options = 1;
		Node test;
		test.setBoard(board);
		test.setPlayer('X');
		test.move = 0;
		//alpha_beta_search(test,board);
		Node comp1 = MinMaxAB(test,test.move,test.player,100,-120);
		for(int k=0;k<bestPath.size() -1;k++)
		{
			if(bestPath[k].move == 1)
			{
				for(int i=0;i<8;i++)
				{
					for(int j=0;j<8;j++)
					{
						//find child with move 0 and then store it into board
						board[i][j] = bestPath[k].board[i][j];
					}
				}
				break;
			}
		}
		cout<<"After Computer X Turn board is:"<<endl;
		moveCount++;
		printBoard(board);
		//cout<<"The selected v value is:"<<v<<endl;
		//cout<<"The printing board player is:"<<bestPath[bestPath.size() - 1].player;
		//cout<<"The printing board player v is:"<<bestPath[bestPath.size() - 1].v;
		//exit(0);  //for testing purpose
		Node test1;
		test1.setBoard(board);
		test1.setPlayer('O');
		test1.move = 0;
		test1.actions();
		//Subtract the size of actions() from NodeCount
		NodeCount -= test1.childs.size();
		if(test1.terminal())
		{
			cout<<"Length of Game Path:"<<moveCount<<endl;
			cout<<"No of Nodes Generated:"<<NodeCount<<endl;
			int w = test1.utility();
			if(w == 20)
			{
				cout<<"Computer X Won the game"<<endl;
				exit(0);
			}
		}
		if(moveCount >= 80)
		{
			cout<<"Game Tie"<<endl;
			cout<<"Length of Game Path:"<<moveCount<<endl;
			cout<<"No of Nodes Generated:"<<NodeCount<<endl;
			exit(0);
		}
		bestPath.clear();
		options = 2;
		Node test2;
		test2.setBoard(board);
		test2.setPlayer('O');
		test2.move = 0;
		comp1 = MinMaxAB(test2,test2.move,test2.player,120,-100);
		for(int k=0;k<bestPath.size() -1;k++)
		{
			if(bestPath[k].move == 1)
			{
				for(int i=0;i<8;i++)
				{
					for(int j=0;j<8;j++)
					{
						//find child with move 0 and then store it into board
						board[i][j] = bestPath[k].board[i][j];
					}
				}
				break;
			}
		}
		cout<<"After Computer O Turn board is:"<<endl;
		moveCount++;
		printBoard(board);
		Node test3;
		test3.setBoard(board);
		test3.setPlayer('X');
		test3.move = 0;
		test3.actions();
		//Subtract the size of actions() from NodeCount
		NodeCount -= test3.childs.size();
		if(test3.terminal())
		{
			cout<<"Length of Game Path:"<<moveCount<<endl;
			cout<<"No of Nodes Generated:"<<NodeCount<<endl;
			int w = test3.utility();
			if(w == 20)
			{
				cout<<"Computer O Won the game"<<endl;
				exit(0);
			}	
		}
		if(moveCount >= 80)
		{
			cout<<"Game Tie"<<endl;
			cout<<"Length of Game Path:"<<moveCount<<endl;
			cout<<"No of Nodes Generated:"<<NodeCount<<endl;
			exit(0);
		}
	}
}
/*
void comVuser(char &player,int &row,int &column,int &nrow,int &ncolumn,bool &flag,bool &flag2,char board[][8],char newboard[][8])
{
	while(flag2)
	{
		options = 1;
		Node test;
		test.setBoard(board);
		test.setPlayer('X');
		//test.move = count;
		test.move = 0;
		//count++;
		alpha_beta_search(test,board);
		cout<<"After Computer Turn board is:"<<endl;
		moveCount++;
		printBoard(board);
		Node test1;
		test1.setBoard(board);
		test1.setPlayer('O');
		//test1.move = count;
		test1.move = 0;
		//count++;
		test1.actions();
		//Subtract the size of actions() from NodeCount
		NodeCount -= test1.childs.size();
		if(test1.terminal())
		{
			cout<<"Length of Game Path:"<<moveCount<<endl;
			cout<<"No of Nodes Generated:"<<NodeCount<<endl;
			int w = test1.utility();
			if(w == 20)
			{
				cout<<"Computer Won the game"<<endl;
				exit(0);
			}
		}
		if(moveCount >= 80)
		{
			cout<<"Game Tie"<<endl;
			cout<<"Length of Game Path:"<<moveCount<<endl;
			cout<<"No of Nodes Generated:"<<NodeCount<<endl;
			exit(0);
		}
		options = 2;
		cout << "Your Turn"<<endl;
		
		int tempNodeCount = NodeCount;
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
			Node test2;
			test2.setBoard(newboard);
			test2.setPlayer('O');
			test2.move = 0;
			//count++;
			test2.actions();
			//Subtract the size of actions() from NodeCount
			NodeCount -= test2.childs.size();
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
		NodeCount -= tempNodeCount;
		moveCount++;
		printBoard(board);
		Node test3;
		test3.setBoard(board);
		test3.setPlayer('X');
		test3.move = 0;
		//count++;
		test3.actions();
		//Subtract the size of actions() from NodeCount
		NodeCount -= test3.childs.size();
		if(test3.terminal())
		{
			cout<<"Length of Game Path:"<<moveCount<<endl;
			cout<<"No of Nodes Generated:"<<NodeCount<<endl;
			int w = test3.utility();
			if(w == 20)
			{
				cout<<"You Won the game"<<endl;
				exit(0);
			}	
		}
		if(moveCount >= 80)
		{
			cout<<"Game Tie"<<endl;
			cout<<"Length of Game Path:"<<moveCount<<endl;
			cout<<"No of Nodes Generated:"<<NodeCount<<endl;
			exit(0);
		}
	}
}
*/
int main()
{
	char player = 'X';
	int row,column,nrow,ncolumn;
	bool flag = false;
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
	/*
	char board[8][8] =
	{
		{'_','_','_','_','_','_','_','_'},
		{'_','_','_','_','_','_','_','_'},
		{'_','_','_','_','_','_','_','_'},
		{'_','_','_','_','_','_','_','_'},
		{'_','_','_','_','_','_','_','X'},
		{'_','_','X','_','X','_','_','_'},
		{'_','_','_','X','_','_','_','X'},
		{'_','_','Y','_','P','_','_','_'}
	};
	*/
	cout<<"Available Options are:"<<endl;
	cout<<"1.Computer Vs User"<<endl;
	cout<<"2.Computer Vs Computer"<<endl;
	cout<<"3.Exit"<<endl;
	cout<<"Choose one of the above options: ";
	do
	{
		cin>>options;
	}while( options != 1 && options != 2 && options != 3);
	if(options == 1)
	{
		cout<<"Computer Turn...."<<endl;
		//comVuser(player,row,column,nrow,ncolumn,flag,flag2,board,newboard);
	}
	else if(options == 3)
	{
		cout<<"Thank You."<<endl;
		exit(0);
	}
	else if(options == 2)
	{
		//Computer Vs Computer
		comVcom(player,row,column,nrow,ncolumn,flag,flag2,board,newboard);
	}
}
