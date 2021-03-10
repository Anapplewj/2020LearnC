//����������ά���飬10*10�ģ�һ�ű����׵ģ�һ�ű�����ҵ�
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<time.h>
#define MAX_ROW 9
#define MAX_COL 9
//���㸽���м�����
//�����ǰ�㿪��λ���ڵ�0�е�0�У���ôֻ������������
//�����ǰ�㿪��λ���ڵ�0�У���ôֻ���ұߵ�
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
//�ж��Ƿ�Ӯ��
//�����ж��Ƿ�û���׵ĵط�ȫ��������
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
//��ӡ��ͼ
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
		printf("����������Ҫ�ߵ�λ��(row,col)\n");
		int row = 0;
		int col = 0;
		scanf("%d,%d", &row, &col);
		if (row < 0 || row >= MAX_ROW || col<0 || col>=MAX_COL){
			printf("����Խ�磬����������!\n");
			continue;
		}else if (playerMap[row][col] != '*'){
			printf("��ǰλ���Ѿ��㿪������������\n");
			continue;
		}else if (mineMap[row][col]=='$'){
			printf("�˴����ף���Ϸ������\n");
			twoMap(mineMap, playerMap);
			printMap(playerMap);
			return;
		}else{
			int number = num(mineMap, playerMap, row, col);
			playerMap[row][col] = number+'0';
			if (isWin(mineMap, playerMap) == 1){
				printf("��ϲ��ɹ���!\n");
				twoMap(mineMap, playerMap);
				printMap(playerMap);
				return;
			}
		}
		printMap(playerMap);
	}
}
//�˵�
int menue(){
	printf("========================\n");
	printf("1.��ʼһ����Ϸ\n");
	printf("0.�˳�\n");
	printf("========================\n");
	while (1){
		printf("����������ѡ��\n");
		int choice = 0;
		scanf("%d", &choice);
		if (choice == 0 || choice == 1){
			return choice;
		}else{
			printf("���������밴����ʾ����!\n");
		}
	}
}

//��ʼ���׵ĵ�ͼ
//һ�ŵ�ͼ����ʮ����
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
//��ʼ����ҵĵ�ͼ
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