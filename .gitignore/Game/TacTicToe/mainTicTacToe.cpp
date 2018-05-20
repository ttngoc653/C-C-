#include<iostream>

using namespace std;

char** initBoard() {
	char** board = new char*[3];
	for (int i = 0; i < 3; i++)
	{
		board[i] = new char[3];
	}
	return board;
}

char** play(char** board, char player) {
	cout << "MOI " << player << " NHAP VI TRI DANH: ";
	int x, y;
	cin >> x >> y;
	if (x<1 || x>3 || y<0 || y>3)
	{
		cout << "VUOT QUA BAN CO. YEU CAU NHAP LAI." << endl;
		return play(board, player);
	}
	else if (board[x - 1][y - 1] != '.')
	{
		cout << "VI TRI NAY DA CO NGUOI DANH.YEU CAU NHAP LAI." << endl;
		return play(board, player);
	}
	board[x - 1][y - 1] = player;
	return board;
}

char process(char** board) {
	for (int i = 0; i < 3; i++)
	{
		if (board[i][1] == board[i][0] && board[i][1] == board[i][2] && board[i][1] != '.')
			return board[i][1];
		else if (board[1][i] == board[0][i] && board[1][i] == board[2][i] && board[1][i] != '.')
			return board[1][i];
	}
	if (board[1][1] != '.')
	{
		if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
		{
			return board[1][1];
		}
		else if (board[2][0] == board[1][1] && board[1][1] == board[0][2])
		{
			return board[1][1];
		}
	}
	return 'F';
}

void outBoard(char** board) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
		{
			cout << board[i][j] << '\t';
		}
		cout << '\n';
	}
}

int main() {
	char** board;
	bool playMode = false;
	char player = 'X';
	int scope = 0;
	while (true)
	{
		if (!playMode)
		{
			cout << "BAN CHOI DA KHOI TAO THANH CONG." << endl;
			board = initBoard();
			playMode = true;
		}
		board = play(board, player);
		outBoard(board);
		if (process(board) != 'F')
		{
			scope += process(board) == 'X' ? 100 : 1;
			cout << player << " DA THANG. TY SO HIEN TAI X = " << (int)scope / 100 << ", O = " << scope % 100 << endl;
		}
		player = player == 'X' ? 'O' : 'X';
	}
	return 0;
}