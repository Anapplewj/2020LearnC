#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<time.h>
#include<windows.h>

#define MAX_ROW 3
#define MAX_COL 3
//二维数组实现简单的三子棋
//首先需要一个目录
//然后准备一个数组，玩家落子和电脑落子
//玩家落子
void player(char chessBoard[MAX_ROW][MAX_COL]){
	while (1){
		printf("请输入您想落子的位置(x,y)\n");
		int x = 0;
		int y = 0;
		scanf("%d,%d", &x, &y);
		if (x < 0 || x >= MAX_ROW || y<0 || y>MAX_COL){
			printf("输入越界，请重新输入\n");
			continue;
		}
		else if (chessBoard[x][y] != ' '){
			printf("该位置已落子，请重新输入");
			continue;
		}
		else{
			chessBoard[x][y] = 'x';
			break;
		}
	}
}
//电脑落子
void computer(char chessBoard[MAX_ROW][MAX_COL]){
	while (1){
		int x = rand() % 3;
		int y = rand() & 3;
		if (chessBoard[x][y] == ' '){
			chessBoard[x][y] = 'o';
			return;
		}
	}
}

int menue(){
	printf("========三子棋游戏========\n");
	printf("1.开始一局游戏\n");
	printf("0.退出\n");
	printf("==========================\n");
	int choice = 0;
	while (1){
		printf("请输入您的选择:");		
		scanf("%d", &choice);
		if (choice == 0 || choice == 1){
			break;
		}else{
			printf("请按照提示输入!\n");
		}
	}
	return choice;
}
//判断棋盘是否满了，0为未满，1为满了
int isFull(char chessBoard[MAX_ROW][MAX_COL]){
	for (int i = 0; i < MAX_ROW; i++){
		for (int j = 0; j < MAX_COL; j++){
			if (chessBoard[i][j] == ' '){
				return 0;
			}
		}
	}
	return 1;
}
//判断是否赢了
//赢了返回1，没赢返回-1,和棋返回0
//同一行相同，同一列相同，和棋
int isWin(char chessBoard[MAX_ROW][MAX_COL]){
	//同一行相同
	for (int i = 0; i < MAX_ROW; i++){
		if (chessBoard[i][0] == chessBoard[i][1] && chessBoard[i][1] == chessBoard[i][2]&&chessBoard[i][0]!=' '){
			return 1;
		}
	}
	//同一列相同
	for (int i = 0; i < MAX_COL; i++){
		if (chessBoard[0][i] == chessBoard[1][i] && chessBoard[1][i] == chessBoard[2][i] && chessBoard[0][i] != ' '){
			return 1;
		}
	}
	//对角线相同
	if (chessBoard[0][0] == chessBoard[1][1] && chessBoard[1][1] == chessBoard[2][2] && chessBoard[2][2] != ' '){
		return 1;
	}
	else if (chessBoard[0][2] == chessBoard[1][1] && chessBoard[1][1] == chessBoard[2][0] && chessBoard[2][0] != ' '){
		return 1;
	}
	//和棋
	if (isFull(chessBoard) == 1){
		return 0;
	}
	return -1;
}
//打印棋盘
void printChessBoard(char chessBoard[MAX_ROW][MAX_COL]){
	printf("+---+---+---+\n");
	for (int i = 0; i < MAX_ROW; i++){
		printf("| %c | %c | %c |\n", chessBoard[i][0], chessBoard[i][1], chessBoard[i][2]);
		printf("+---+---+---+\n");
	}
	
}
void game(char chessBoard[MAX_ROW][MAX_COL]){
	printChessBoard(chessBoard);
	while (1){
		int choice =100;
		player(chessBoard);
		printChessBoard(chessBoard);
		choice = isWin(chessBoard);
		if (choice == 1){
			printf("恭喜你，赢过了电脑！\n");
			return;
		}else if (choice == 0){
			printf("和棋\n");
			return;
		}
		computer(chessBoard);
		printChessBoard(chessBoard);
		choice = isWin(chessBoard);
		if (choice == 1){
			printf("很无语，你连电脑都不如!\n");
			return;
		}else if (choice == 0){
			printf("和棋\n");
			return;
		}
	}
}
//初始化棋盘
void init(char chessBoard[MAX_ROW][MAX_COL]){
	for (int i = 0; i < MAX_ROW; i++){
		for (int j = 0; j < MAX_COL; j++){
			chessBoard[i][j] = ' ';
		}
	}
}

int main(){
	srand(time(0));
	char chessBoard[MAX_ROW][MAX_COL] = { 0 };
	while (1){
		int choice = menue();
		if (choice == 0){
			printf("byebye~~\n");
			break;
		}else{
			init(chessBoard);
			game(chessBoard);
		}
	}
	system("pause");
	return 0;
}