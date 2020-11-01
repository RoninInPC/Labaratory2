#define SIZEX 3
#define SIZEY 3
enum Player {
	FIRST,
	SECOND
};
enum GameSituation {
	PLAYING,
	WINFIRST,
	WINSECOND
};
struct MyPoint {
	int x;
	int y;
};
class Board {
private:
	int SizeX;
	int SizeY;
	int** Arr;
public:
	Board() {
		this->SizeX = SIZEX; 
		this->SizeY = SIZEY; 
		Arr = new int* [SizeX]; 
		for (int i = 0; i < SizeX; i++) {
			Arr[i] = new int[SizeY]; 
			for (int j = 0; j < SizeY; j++) { 
				Arr[i][j] = 'Z'; 
			}
		}
	};
	int GetSizeX() { return this->SizeX; };
	int GetSizeY() { return this->SizeY; };
	void SetSizeX(int Size) { this->SizeX = Size; };
	void SetSizeY(int Size) { this->SizeY = Size; };
	int** GetArr() { return this->Arr; }
	void SetArr(int** NewArr) { this->Arr = NewArr; };
	void ShowBoard();
	~Board() {
		for (int i = 0; i < this->SizeX; i++) {
			delete[] this->Arr[i];
		}
		delete[] this->Arr;
	}
};
class Game {
private:
	Board board;
	GameSituation GInfo;
	Player player;
	MyPoint PlayerTurn;
public:
	Board GetBoard() { return this->board; };
	void SetBoard(Board board) { this->board = board; };
	Game() { this->board; this->player = FIRST; this->PlayerTurn = { -1,-1 }; this->GInfo = PLAYING; };
	void GameStart();
	GameSituation GameEnd();
	void ShowGameEnd();
};