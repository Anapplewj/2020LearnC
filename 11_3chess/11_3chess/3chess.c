//首先创建一个3*3的棋盘
//初始化棋盘，用空格填充
//打印棋盘，使其有可见的边框
//玩家落子（检验）
//系统落子（检验）
//玩家赢；系统赢；和棋
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_ROW 3
#define MAX_COL 3
//玩家落子
char playermove(char chessboard[MAX_ROW][MAX_COL])
{
	int row = 0;
	int col = 0;
	while (1){
		printf("请输入您落子的位置：（row col）");
		scanf("%d %d", &row, &col);
		//校验
		//校验输入是否输入有误
		if (row < 0 || row >= MAX_ROW || col<0 || col>=MAX_COL){
			printf("您的输入越界!!\n");
			continue;
		}else if (chessboard[row][col]!=' '){
			printf("该位置已落子!!\n");
			continue;
		}else{
			chessboard[row][col] = 'x';
			return chessboard[row][col];
		}

	}
}
//电脑落子
void computermove(char chessboard[MAX_ROW][MAX_COL])
{
	while (1){
		int row = rand() % MAX_ROW;
		int col = rand() % MAX_COL;
		//校验落子位置是否已经落子
		if (chessboard[row][col] != ' '){
			continue;
		}
		chessboard[row][col] = 'o';
		break;
	}

}
//判断棋盘是否满
//满返回1，未满返回0
char isFull(char chessboard[MAX_ROW][MAX_COL])
{
	for (int row = 0; row < MAX_ROW; row++){
		for (int col = 0; col < MAX_COL; col++){
			//找到空格
			if (chessboard[row][col] == ' '){
				return 0;
			}
		}
	}
	//未找到，即满了
	return 1;
}
//判断是否赢
//'x'表示玩家获胜
//'o'表示电脑获胜
//' '表示胜负未分
//'h'表示和棋
char isWin(char chessboard[MAX_ROW][MAX_COL])
{
//同一行
	for (int row = 0; row < MAX_ROW; row++){
		if (chessboard[row][0]!=' '
			&&(chessboard[row][0] ==chessboard[row][1])
			&&(chessboard[row][0]== chessboard[row][2])){
			return chessboard[row][0];
		}
	}
//同一列
	for (int col = 0; col < MAX_COL; col++){
		if (chessboard[0][col]!=' '
			&&(chessboard[0][col] == chessboard[1][col])
			&&(chessboard[0][col] == chessboard[2][col])){
			return chessboard[0][col];
		}
	}
//对角线相同
	if (chessboard[0][0] != ' '
		&& (chessboard[0][0] == chessboard[1][1])
		&& (chessboard[0][0] == chessboard[2][2])){
		return chessboard[0][0];
	}
	if (chessboard[0][2] != ' ' 
		&&(chessboard[0][2] == chessboard[1][1])
		&&(chessboard[0][2] == chessboard[2][0])){
		return chessboard[0][2];
	}
//和棋
	if (isFull(chessboard)){
		return 'h';
	}
	return ' ';
}

//初始化棋盘
void init(char chessboard[MAX_ROW][MAX_COL])
{
	for (int row = 0; row < MAX_ROW; row++){
		for (int col = 0; col < MAX_COL; col++){
			chessboard[row][col] = ' ';
		}
	}
}
//打印棋盘
void printchessboard(char chessboard[MAX_ROW][MAX_COL])
{
	printf("+---+---+---+\n");
	for (int row = 0; row < MAX_ROW; row++){
		printf("| %c | %c | %c |\n", chessboard[row][0], chessboard[row][1], chessboard[row][2]);
		printf("+---+---+---+\n");
	}

}

void game()
{
	char chessboard[MAX_ROW][MAX_COL] = {0};
	init(chessboard);//初始化棋盘
	char winner = ' ';
	while (1){
		printchessboard(chessboard);//打印棋盘
		playermove(chessboard);//玩家落子
		//校验，是否赢是否和棋
		winner = isWin(chessboard);
		if (winner != ' '){
			break;
		}
		computermove(chessboard);//电脑落子
		winner = isWin(chessboard);
		if (winner != ' '){
			break;
		}
	}
	if (winner == 'x'){
		printchessboard(chessboard);
		printf("恭喜您赢了！\n");
	}else if (winner == 'o'){
		printchessboard(chessboard);
		printf("很遗憾您输了！\n");
	}else if (winner == 'h'){
		printchessboard(chessboard);
		printf("和棋！您和电脑棋技相当~\n");
	}
}
int menue(int choice)
{
	printf("************************\n");
	printf("1.开始游戏\n");
	printf("0.结束游戏\n");
	printf("************************\n");
	printf("请输入您的选择：");
	scanf("%d", &choice);
	return choice;
}

int main()
{
	srand(time(0));
	int choice = 0;
	while (1){
		choice=menue(choice);
		if (choice == 1){
			game();
		}
		else if (choice == 0){
			break;
		}
		else{
			printf("您的输入有误，请重新输入\n");
			continue;
		}
	}
	system("pause");
	return 0;
}
