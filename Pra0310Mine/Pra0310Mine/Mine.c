//创建两个二维数组，10*10的，一张保存雷的，一张保存玩家的
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<time.h>
#define MAX_ROW 9
#define MAX_COL 9
//计算附近有几个雷
//如果当前点开的位置在第0行第0列，那么只有两个附近的
//如果当前点开的位置在第0列，那么只有右边的
int num(char mineMap[MAX_ROW][MAX_COL], char playerMap[MAX_ROW][MAX_COL],int row,int col){
	int count = 0;
	for (int i = row - 1; i <=row+ 1; i++){
		for (int j = col - 1; j <= col + 1; j++){
			if (i<0 || i>8 || j<0 || j>8){
				continue;
			}
			if (mineMap[i][j] == '$'){
				count++;
			}
		}
	}
	return count;
}
//判断是否赢了
//就是判断是否没有雷的地方全都被翻开
int isWin(char mineMap[MAX_ROW][MAX_COL], char playerMap[MAX_ROW][MAX_COL]){
	for (int i = 0; i < MAX_ROW; i++){
		for (int j = 0; j < MAX_COL; j++){
			if (mineMap[i][j] != '$'&&playerMap[i][j] == '*'){
				return 0;
			}
		}
	}
	return 1;
}
//打印地图
void printMap(char map[MAX_ROW][MAX_COL]){
	printf("   0    1    2    3    4    5    6    7    8\n");
	printf(" +---+----+----+----+----+----+----+----+----+\n");
	for (int i = 0; i < MAX_ROW; i++){
		printf("%d|",i);
		for (int j = 0; j < MAX_COL; j++){
			printf(" %c | ", map[i][j]);
		}
		printf("\n +---+----+----+----+----+----+----+----+----+\n");
	}
}
void twoMap(char mineMap[MAX_ROW][MAX_COL], char playerMap[MAX_ROW][MAX_COL]){
	for (int i = 0; i < MAX_ROW; i++){
		for (int j = 0; j < MAX_COL; j++){
			if (mineMap[i][j] == '$'){
				playerMap[i][j] = mineMap[i][j];
			}
		}
	}
}
void game(char mineMap[MAX_ROW][MAX_COL],char playerMap[MAX_ROW][MAX_COL]){
	printMap(playerMap);
	while (1){
		printf("请输入您想要走的位置(row,col)\n");
		int row = 0;
		int col = 0;
		scanf("%d,%d", &row, &col);
		if (row < 0 || row >= MAX_ROW || col<0 || col>=MAX_COL){
			printf("输入越界，请重新输入!\n");
			continue;
		}else if (playerMap[row][col] != '*'){
			printf("当前位置已经点开，请重新输入\n");
			continue;
		}else if (mineMap[row][col]=='$'){
			printf("此处是雷，游戏结束！\n");
			twoMap(mineMap, playerMap);
			printMap(playerMap);
			return;
		}else{
			int number = num(mineMap, playerMap, row, col);
			playerMap[row][col] = number+'0';
			if (isWin(mineMap, playerMap) == 1){
				printf("恭喜你成功了!\n");
				twoMap(mineMap, playerMap);
				printMap(playerMap);
				return;
			}
		}
		printMap(playerMap);
	}
}
//菜单
int menue(){
	printf("========================\n");
	printf("1.开始一局游戏\n");
	printf("0.退出\n");
	printf("========================\n");
	while (1){
		printf("请输入您的选择\n");
		int choice = 0;
		scanf("%d", &choice);
		if (choice == 0 || choice == 1){
			return choice;
		}else{
			printf("输入有误，请按照提示输入!\n");
		}
	}
}

//初始化雷的地图
//一张地图中有十个雷
void initMineMap(char mineMap[MAX_ROW][MAX_COL]){
	int num = 0;
	while (1){
		int row = rand() % 9;
		int col = rand() % 9;
		if (mineMap[row][col] != '$'){
			mineMap[row][col] = '$';
			num++;
		}
		if (num == 10){
			return;
		}
	}
}
//初始化玩家的地图
void init(char playerMap[MAX_ROW][MAX_COL]){
	for (int i = 0; i < MAX_ROW; i++){
		for (int j = 0; j < MAX_COL; j++){
			playerMap[i][j] = '*';
		}
	}
}
int main(){
	srand(time(0));
	char mineMap[MAX_ROW][MAX_COL] = { 0 };
	char playerMap[MAX_ROW][MAX_COL] = { 0 };
	while (1){
		int choice = menue();
		if (choice== 1){
			initMineMap(mineMap);
			init(playerMap);
			game(mineMap,playerMap);
		}else{
			printf("byebye~~\n");
			break;
		}
	}
	system("pause");
	return 0;
}