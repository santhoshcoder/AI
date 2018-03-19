#include <iostream>
#include <vector>
#include <algorithm>
#include "Node.cpp"
using namespace std;

//Function Definitions Start************************************
void alpha_beta_search(Node n,char [][3]); // change so that it returns a 2-D array which
								// is the choosen action
int max_value(Node &n, int alpha, int beta);
int min_value(Node &n, int alpha, int beta);
void printBoard(char s[][3]);
//Function Definitions End**************************************

void printBoard(char array2D[][3])
{
	cout << endl << "***************" << endl;
	for(int i = 0;i < 3; i++)
	{
		for(int j = 0;j < 3;j++)
		{
			cout<<array2D[i][j]<<" ";
		}
		cout<<endl;
	}
	cout << endl << "***************" << endl;
}

void alpha_beta_search(Node n,char array2D[][3]) {
	n.v = max_value(n,-5, 5);
	cout<<"n.v is "<<n.v<<endl;
	cout<<"n.childs.size() is "<<n.childs.size()<<endl;
	for (int i = 0; i < n.childs.size(); i++)
	{
		cout<<"n.childs["<<i<<"].v is "<<n.childs[i].v<<endl;
	}
	for (int i = 0; i < n.childs.size(); i++) {
		if (n.childs[i].v == n.v) {
			// found store it into a 2-D array and return the array
			cout<<"Found"<<endl;
			for(int h = 0; h < 3 ;h++)
			{
				for(int w = 0; w < 3; w++)
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
	//cout<<"Called Max Function"<<endl;
	//cout<<"Checking win returned"<<n.checkingWin()<<endl;
	if(n.checkingWin() == true)
		return n.utility();
	n.v = -5;
	//Create actions
	//cout<<"Generating childs in max_value"<<endl;
	n.actions();
	for(int i = 0; i < n.childs.size(); i++)
	{
		n.v = max(n.v,min_value(n.childs[i],alpha,beta));
		if (n.v >= beta)
			return n.v;
		alpha = max(alpha,n.v);
	}
	return n.v;
}
int min_value(Node &n,int alpha,int beta)
{
	if(n.checkingWin())
		return n.utility();
	n.v = 5;
	//Create actions 
	n.actions();
	for(int i = 0; i < n.childs.size(); i++)
	{
		n.v = min(n.v,max_value(n.childs[i],alpha,beta));
		if (n.v <= alpha)
			return n.v;
		beta = min(beta,n.v);
	}
	return n.v;
}

int main() 
{
	char player = 'X';
	int row,column;
	char flag;
	bool flag2 = true;
	char array2D[3][3] = {{'_', '_', '_'}, {'_', '_', '_'}, {'_', '_', '_'}};

	//Print Initial Stage of the board
	
	while(flag2) //Need some condition on when to stop
	{
		Node temp;
		temp.setBoard(array2D);
		temp.setplayer(player);
		alpha_beta_search(temp,array2D);
		cout<<"After Computer Turn board is:"<<endl;
		printBoard(array2D);
		cout << "Your Turn"<<endl;
		do
		{
			cout << "Choose a Row (0-2): ";
			cin >> row;
			cout << "Choose a Column (0-2): "<<endl;
			cin >> column;
			if(array2D[row][column] != '_')
			{
				cout<<"It's already filled"<<endl;
				row = 3;
			}
		}while(!((row >=0 && row <=2) && (column >=0 && column <=2)));
		array2D[row][column] = 'O';
		cout<<"After Your Turn board is:"<<endl;
		printBoard(array2D);
	}
}