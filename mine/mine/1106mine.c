//创建两个地图，用数组表示
//一个地图表示玩家看到的(showmap)，另一个地图表示雷的地图(minemap)
//玩家输入坐标翻开
//翻开之后，是雷就结束；不是雷就显示出周围有几个雷
//把地图上所有不是雷的格子翻开，胜利
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>
#define MAX_ROW 9
#define MAX_COL 9

//打印地图
void printmap(char showmap[MAX_ROW][MAX_COL])
{
	printf("   0   1   2   3   4   5   6   7   8\n");
	printf(" +---+---+---+---+---+---+---+---+---+\n");
	for (int row = 0; row < MAX_ROW; row++){
		printf("%d",row);
		for (int col = 0; col < MAX_COL; col++){
			printf("| %c ", showmap[row][col]);
		}
		printf("|\n +---+---+---+---+---+---+---+---+---+\n");
	}
}

//计算玩家输入坐标处附近雷的个数,并且将个数更新到showmap中
void minenum(char showmap[MAX_ROW][MAX_COL],char minemap[MAX_ROW][MAX_COL], int row, int col)
{
	int count = 0;
	for (int r = row - 1; r <= row + 1; r++){
		for (int c = col - 1; c <= col + 1; c++){
			//判断是否越界
			if (r<0 || r>8 || c < 0 || c>8){
				continue;
			}
			if (minemap[r][c] == '1'){
				count++;
			}
		}
	}
	showmap[row][col] = count + '0';

}

//将minemap中的雷放到showmap中用#显示出来（用于游戏失败之时）
void putmine(char showmap[MAX_ROW][MAX_COL], char minemap[MAX_ROW][MAX_COL])
{
	for (int row = 0; row < MAX_ROW; row++){
		for (int col = 0; col < MAX_COL; col++){
			if (minemap[row][col] == '1'){
				showmap[row][col] = '#';
			}
		}
	}
}

//判断游戏是否胜利
//1表示胜利，0表示失败
int isWin(char showmap[MAX_ROW][MAX_COL], char minemap[MAX_ROW][MAX_COL])
{
	for (int row = 0; row < MAX_ROW; row++){
		for (int col = 0; col < MAX_COL; col++){
			if(showmap[row][col]=='*'&&minemap[row][col]!='1'){
				return 0;
			}
		}
	}
	return 1;
}

//玩家操作
//判断游戏胜利
//当所有不是雷的都被揭开，游戏胜利，即所有不是雷的地方都不是*
void playermove(char showmap[MAX_ROW][MAX_COL], char minemap[MAX_ROW][MAX_COL])
{
	int row = 0;
	int col = 0;
	while (1){
		if (isWin(showmap, minemap) == 1){
			system("cls");
			printf("-----------------------\n");
			printf("恭喜你胜利了！\n");
			printf("-----------------------\n");
			printmap(showmap);
			break;
		}
		printf("请输入您的行列：");
		scanf("%d %d", &row, &col);
		//检验是否输入正确
		if (row<0 || row>8 || col < 0 || col>8){
			printf("您的输入有误\n");
			continue;
		}
		//如果是雷
		//打印出地图
		//游戏失败
		if (minemap[row][col] == '1'){
			system("cls");
			printf("-----------------------\n");
			printf("很遗憾，(%d,%d)处是雷\n",row,col);
			printf("-----------------------\n");
			putmine(showmap, minemap);
			printmap(showmap);
			break;
		}
		//不是雷，坐标处的*就替换其附近雷的个数
		minenum(showmap,minemap,row,col);
		//打印showmap
		system("cls");
		printmap(showmap);
	}
}

//初始化地图
void init(char showmap[MAX_ROW][MAX_COL], char minemap[MAX_ROW][MAX_COL])
{
	//初始化玩家看到的地图，*
	for (int row = 0; row < MAX_ROW; row++){
		for (int col = 0; col < MAX_COL; col++){
			showmap[row][col] = '*';
		}
	}
	//初始化地雷的地图minemap全为0，有雷用1表示，没雷用0表示
	for (int row = 0; row < MAX_ROW; row++){
		for (int col = 0; col < MAX_COL; col++){
			minemap[row][col] = '0';
		}
	}
	//将1放到minemap中的十个随机位置,表示十个地雷
	//1表示雷，0表示无雷
	int minenumber = 0;
	while (minenumber < 10){
		int row = rand() % MAX_ROW;
		int col = rand() % MAX_COL;
		if (minemap[row][col] == '0'){
			minemap[row][col] = '1';
			minenumber++;
		}
	}

}

//游戏
void game()
{
	char showmap[MAX_ROW][MAX_COL] = {0};
	char minemap[MAX_ROW][MAX_COL] = {0};
	//初始化地图
	init(showmap, minemap);
	//打印出玩家看到的地图 showmap
	printmap(showmap);
	//玩家开始操作
	playermove(showmap, minemap);
}

//菜单
int menue(int choice)
{
	printf("***************************\n");
	printf("1.开始游戏\n");
	printf("0.退出游戏\n");
	printf("***************************\n");
	printf("请输入您的选择：");
	scanf("%d", &choice);
	return choice;
}

int main()
{
	srand((unsigned int)time(0));
	int choice = 0;
	while (1){
		choice = menue(choice);
		if (choice == 1){
			game();
		}else if(choice==0){
			printf("byebye！\n");
			break;
		}else{
			printf("您的输入有误，请重新输入\n");
		}
	}
	system("pause");
	return 0;
}