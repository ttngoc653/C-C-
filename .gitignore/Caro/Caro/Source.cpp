#include<iostream>
#include<new>

using namespace std;

// khoi tao ban co
char** init(int &row,int &collum) {
	cout << "NHAP SO DONG: ";
	cin >> row;
	cout << "NHAP SO COT: ";
	cin >> collum;
	
	char** board = new char*[row];
	for (int i = 0; i < row; i++)
		board[i] = new char[collum];
	
	for (int i = 0; i < row; i++)
		for (int j = 0; j < collum; j++)
			board[i][j] = '.';

	return board;
}

// xuat ban co ra man hinh
void out(char** board, int r, int c) {
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cout << board[i][j] << '\t';
		}
		cout << '\n';
	}
}

// cho nguoi choi danh
char** goOn(char** board,int row,int collum, char player) {
	int x, y;
	while (true)
	{
		cout << "NGUOI CHOI" << player << " CHON COT MUON DI: ";
		cin >> x;
		cout << "NGUOI CHOI" << player << "  CHON DONG MUON DI: ";
		cin >> y;

		if ((x > 0) && (x <= collum) && (y > 0) && (y <= row))
			break;
		else
			cout << "SO LIEU NHAP KHONG HOP LE. HAY NHAP LAI \n";
	}
	
	board[y - 1][x - 1] = player;

	return board;
}

// kiem tra dieu kien danh
char test(char** board, int row, int collum, char player) {
	for (int  i = 0; i < row; i++)
	{
		for (int j = 0; j < collum; j++)
		{
			char c = board[i][j];
			// test row
			if (c != '.'&&j<collum - 4)
				if (board[i][j + 1] == c&&board[i][j + 2] == c&&board[i][j + 3] == c&&board[i][j + 4] == c) return c;

			//test column
			if (c != '.'&&i<row - 4)
				if (board[i + 1][j] == c&&board[i + 2][j] == c&&board[i + 3][j] == c&&board[i + 4][j] == c)
					return c;

			// test cross down
			if (c != '.'&&i<row - 4 && j<collum - 4)
				if (board[i + 1][j + 1] == c&&board[i + 2][j + 2] == c&&board[i + 3][j + 3] == c&&board[i + 4][j + 4] == c) return c;

			//test cross up
			if (c != '.'&&i>3 && j>3)
				if (board[i - 1][j - 1] == c&&board[i - 2][j - 2] == c&&board[i - 3][j - 3] == c&&board[i - 4][j - 4] == c)
					return c;
		}
	}
	return 'F';
}

void main() {
	// so cot, so dong cua ban co
	int row, collum;
	// xet truong hop co dang choi hay k?
	bool play = false;
	// khoi tao nguoi dau tien danh la X
	char player = 'X';
	// ban co
	char** matrix;
	while (true)
	{
		if (!play){
			matrix = init(row, collum);
			play = true;
		}

		matrix = goOn(matrix,row,collum,player);
		out(matrix, row, collum);

		char c = test(matrix, row, collum, player);
		if (c!='F')
		{
			cout << "%c THANG. CHUC MUNG.\n";
			play = false;
		}

		player = player == 'X' ? 'O' : 'X';
	}
}