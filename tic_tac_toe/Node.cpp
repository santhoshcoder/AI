#include <iostream>
#include <vector>
using namespace std;
class Node {
public:
	char board[3][3];
	int v;
	char player;
	vector<Node> childs;
	void setBoard(char s[3][3]);
	void actions();
	void displayBoard();
	bool checkingWin(); // Acts as Terminal Function
	int utility();
	void printActions();
	void setplayer(char);
};
void Node::setplayer(char p) {
	player = p;
}
void Node::setBoard(char s[3][3]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
			board[i][j] = s[i][j];
	}
}
void Node::actions() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (board[i][j] != '_')
				continue;
			else {
				board[i][j] = player;
				// boarddisplay(s);
				Node n;
				n.setBoard(board);
				char nextPlayer = (player == 'X') ? 'O' : 'X';
				n.setplayer(nextPlayer);
				childs.push_back(n);
				board[i][j] = '_';
			}
		}
	}
}
void Node::printActions() {
	if (childs.size() == 0) {
		cout << "No actions" << endl;
	} else {
		for (int i = 0; i < childs.size(); i++) {
			// cout<<"Player is: "<<childs[i].player;
			childs[i].displayBoard();
		}
	}
}
void Node::displayBoard() {
	cout << endl << "***************" << endl;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl << "***************" << endl;
}
bool Node::checkingWin() {
	if (board[0][0] == board[0][1] && board[0][1] == board[0][2] && board[0][0] != '_') {
		if (board[0][0] == 'X')
			cout << "X win";
		else if (board[0][0] == 'O')
			cout << "O win";
		return true;
	} else if (board[1][0] == board[1][1] && board[1][1] == board[1][2]  && board[1][0] != '_') {
		if (board[1][0] == 'X')
			cout << "X win";
		else if (board[1][0] == 'O')
			cout << "O win";
		return true;
	} else if (board[2][0] == board[2][1] && board[2][1] == board[2][2]  && board[2][0] != '_') {
		if (board[2][0] == 'X')
			cout << "X win";
		else if (board[2][0] == 'O')
			cout << "O win";
		return true;
	} else if (board[0][0] == board[1][1] && board[1][1] == board[2][2]  && board[0][0] != '_') {
		if (board[0][0] == 'X')
			cout << "X win";
		else if (board[0][0] == 'O')
			cout << "O win";
		return true;
	} else if (board[0][2] == board[1][1] && board[1][1] == board[2][0]  && board[0][2] != '_') {
		if (board[0][2] == 'X')
			cout << "X win";
		else if (board[0][2] == 'O')
			cout << "O win";
		return true;
	} else if (board[0][0] == board[1][0] && board[1][0] == board[2][0]  && board[0][0] != '_') {
		if (board[0][0] == 'X')
			cout << "X win";
		else if (board[0][0] == 'O')
			cout << "O win";
		return true;
	} else if (board[0][1] == board[1][1] && board[1][1] == board[2][1]  && board[0][1] != '_') {
		if (board[0][1] == 'X')
			cout << "X win";
		else if (board[0][1] == 'O')
			cout << "O win";
		return true;
	} else if (board[0][2] == board[1][2] && board[1][2] == board[2][2]  && board[0][2] != '_') {
		if (board[0][2] == 'X')
			cout << "X win";
		else if (board[0][2] == 'O')
			cout << "O win";
		return true;
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (board[i][j] == '_')
				return false;
		}
	}
	cout << "Tie";
	return true;
}
int Node::utility() {
	if (board[0][0] == board[0][1] && board[0][1] == board[0][2]) {
		if (board[0][0] == 'X')
			return 1;
		else if (board[0][0] == 'O')
			return -1;
	} else if (board[1][0] == board[1][1] && board[1][1] == board[1][2]) {
		if (board[1][0] == 'X')
			return 1;
		else if (board[1][0] == 'O')
			return -1;
	} else if (board[2][0] == board[2][1] && board[2][1] == board[2][2]) {
		if (board[2][0] == 'X')
			return 1;
		else if (board[2][0] == 'O')
			return -1;
	} else if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
		if (board[0][0] == 'X')
			return 1;
		else if (board[0][0] == 'O')
			return -1;
	} else if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
		if (board[0][2] == 'X')
			return 1;
		else if (board[0][2] == 'O')
			return -1;
	} else if (board[0][0] == board[1][0] && board[1][0] == board[2][0]) {
		if (board[0][0] == 'X')
			return 1;
		else
			return -1;
	} else if (board[0][1] == board[1][1] && board[1][1] == board[2][1]) {
		if (board[0][1] == 'X')
			return 1;
		else if (board[0][1] == 'O')
			return -1;
	}
	if (board[0][2] == board[1][2] && board[1][2] == board[2][2]) {
		if (board[0][2] == 'X')
			return 1;
		else if (board[0][2] == 'O')
			return -1;
	}
	return 0;
}