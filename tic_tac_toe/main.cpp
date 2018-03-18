#include <iostream>
#include <vector>
#include <algorithm>
#include "Node.cpp"
using namespace std;

//Function Definitions Start************************************
void alpha_beta_search(Node n,char [][3]); // change so that it returns a 2-D array which
								// is the choosen action
int max_value(Node n, int alpha, int beta);
int min_value(Node n, int alpha, int beta);
//Function Definitions End**************************************

void alpha_beta_search(Node n,char array2D[][3]) {
	n.v = max_value(n,-5, 5);
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
int max_value(Node n,int alpha,int beta)
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
int min_value(Node n,int alpha,int beta)
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

int main() {
	char player = 'X';
	char initial[3][3] = {{'_', '_', '_'}, {'_', '_', '_'}, {'_', '_', '_'}};
	
	Node n;
	n.setBoard(initial);
	n.setplayer(player);
	cout << "Initial Board State is:" << endl;
	n.displayBoard();
	char array2D[3][3] = {{'I', 'I', 'I'}, {'I', 'I', 'I'}, {'I', 'I', 'I'}};
	alpha_beta_search(n,array2D);
	cout<<"After Computer Turn board is:"<<endl;
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