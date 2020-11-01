#include"Game.hpp"
#include<iostream>
#include<Windows.h>
void hidecursor() {

	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &info);
}
void Board::ShowBoard() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position;
	position.X = 0;
	position.Y = 0;
	SetConsoleCursorPosition(hConsole, position);
	for (int x = 0; x < this->SizeX; x++) {
		for (int y = 0; y < this->SizeY; y++) {
			std::cout << (char)this->Arr[x][y]<<' ';
		}
		std::cout << '\n';
	}
}
GameSituation Game::GameEnd() {
	int** Arr = this->board.GetArr();
	int X3 = 0;
	int O3 = 0;
	int X4 = 0;
	int O4 = 0;
	for (int x = 0; x < this->board.GetSizeX(); x++) {
		int X1 = 0;
		int O1 = 0;
		int X2 = 0;
		int O2 = 0;
		for (int y = 0; y < this->board.GetSizeY(); y++) {
			if (Arr[x][y] == 'X') {
				X1++;
			}
			if ((char)Arr[y][x] == 'X') {
				X2++;
			}
			if ((char)Arr[x][y] == 'O') {
				O1++;
			}
			if ((char)Arr[y][x] == 'O') {
				O2++;
			}
			if (x == y && (char)Arr[x][y] == 'X') {
				X3++;
			}
			if (x == y && (char)Arr[x][y] == 'O') {
				O3++;
			}
			if (x + y == this->board.GetSizeY() && (char)Arr[x][y] == 'X') {
				X4++;
			}
			if (x + y == this->board.GetSizeY() && (char)Arr[x][y] == 'O') {
				O4++;
			}
		}
		if (X1 == this->board.GetSizeX() || X2 == this->board.GetSizeX() || X3 == this->board.GetSizeX() || X4 == this->board.GetSizeX()) {
			this->GInfo = WINFIRST;
			break;
		}
		if (O1 == this->board.GetSizeY() || O2 == this->board.GetSizeY() || O3 == this->board.GetSizeY() || O4 == this->board.GetSizeY()) {
			this->GInfo = WINSECOND;
			break;
		}
	}
	return this->GInfo;
}
void Game::ShowGameEnd() {
	int** Arr =this->board.GetArr();
	for (int i = 0; i < this->board.GetSizeX(); i++) {
		for (int j = 0; j < this->board.GetSizeY(); j++) {
			Arr[i][j] = (int)' ';
		}
	}
	Arr[0][0] = (int)'P';
	if (this->GInfo == WINFIRST) {
		Arr[0][1] = (int)'1';
	}
	if (this->GInfo == WINSECOND) {
		Arr[0][1] = (int)'2';
	}
	Arr[1][0] = (int)'W';
	Arr[1][1] = (int)'I';
	Arr[1][2] = (int)'N';
	this->board.SetArr(Arr);
	this->board.ShowBoard();
}
void Game::GameStart() {
	while (this->GameEnd() == PLAYING) {
		this->board.ShowBoard();
		std::cin >> this->PlayerTurn.x >> this->PlayerTurn.y;
		if (this->PlayerTurn.x < this->board.GetSizeX() && this->PlayerTurn.y < this->board.GetSizeY()) {
			int** Arr = this->board.GetArr();
				if (this->player == FIRST) {
					Arr[this->PlayerTurn.x][this->PlayerTurn.y] = (int)'X';
				}
				else {
					Arr[this->PlayerTurn.x][this->PlayerTurn.y] = (int)'O';
				}
			this->board.SetArr(Arr);
				if (this->player == FIRST) {
					this->player = SECOND;
				}
				else {
					this->player = FIRST;
				}
		}
	}
	this->ShowGameEnd();
}