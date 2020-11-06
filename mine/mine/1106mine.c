//����������ͼ���������ʾ
//һ����ͼ��ʾ��ҿ�����(showmap)����һ����ͼ��ʾ�׵ĵ�ͼ(minemap)
//����������귭��
//����֮�����׾ͽ����������׾���ʾ����Χ�м�����
//�ѵ�ͼ�����в����׵ĸ��ӷ�����ʤ��
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>
#define MAX_ROW 9
#define MAX_COL 9

//��ӡ��ͼ
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

//��������������괦�����׵ĸ���,���ҽ��������µ�showmap��
void minenum(char showmap[MAX_ROW][MAX_COL],char minemap[MAX_ROW][MAX_COL], int row, int col)
{
	int count = 0;
	for (int r = row - 1; r <= row + 1; r++){
		for (int c = col - 1; c <= col + 1; c++){
			//�ж��Ƿ�Խ��
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

//��minemap�е��׷ŵ�showmap����#��ʾ������������Ϸʧ��֮ʱ��
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

//�ж���Ϸ�Ƿ�ʤ��
//1��ʾʤ����0��ʾʧ��
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

//��Ҳ���
//�ж���Ϸʤ��
//�����в����׵Ķ����ҿ�����Ϸʤ���������в����׵ĵط�������*
void playermove(char showmap[MAX_ROW][MAX_COL], char minemap[MAX_ROW][MAX_COL])
{
	int row = 0;
	int col = 0;
	while (1){
		if (isWin(showmap, minemap) == 1){
			system("cls");
			printf("-----------------------\n");
			printf("��ϲ��ʤ���ˣ�\n");
			printf("-----------------------\n");
			printmap(showmap);
			break;
		}
		printf("�������������У�");
		scanf("%d %d", &row, &col);
		//�����Ƿ�������ȷ
		if (row<0 || row>8 || col < 0 || col>8){
			printf("������������\n");
			continue;
		}
		//�������
		//��ӡ����ͼ
		//��Ϸʧ��
		if (minemap[row][col] == '1'){
			system("cls");
			printf("-----------------------\n");
			printf("���ź���(%d,%d)������\n",row,col);
			printf("-----------------------\n");
			putmine(showmap, minemap);
			printmap(showmap);
			break;
		}
		//�����ף����괦��*���滻�丽���׵ĸ���
		minenum(showmap,minemap,row,col);
		//��ӡshowmap
		system("cls");
		printmap(showmap);
	}
}

//��ʼ����ͼ
void init(char showmap[MAX_ROW][MAX_COL], char minemap[MAX_ROW][MAX_COL])
{
	//��ʼ����ҿ����ĵ�ͼ��*
	for (int row = 0; row < MAX_ROW; row++){
		for (int col = 0; col < MAX_COL; col++){
			showmap[row][col] = '*';
		}
	}
	//��ʼ�����׵ĵ�ͼminemapȫΪ0��������1��ʾ��û����0��ʾ
	for (int row = 0; row < MAX_ROW; row++){
		for (int col = 0; col < MAX_COL; col++){
			minemap[row][col] = '0';
		}
	}
	//��1�ŵ�minemap�е�ʮ�����λ��,��ʾʮ������
	//1��ʾ�ף�0��ʾ����
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

//��Ϸ
void game()
{
	char showmap[MAX_ROW][MAX_COL] = {0};
	char minemap[MAX_ROW][MAX_COL] = {0};
	//��ʼ����ͼ
	init(showmap, minemap);
	//��ӡ����ҿ����ĵ�ͼ showmap
	printmap(showmap);
	//��ҿ�ʼ����
	playermove(showmap, minemap);
}

//�˵�
int menue(int choice)
{
	printf("***************************\n");
	printf("1.��ʼ��Ϸ\n");
	printf("0.�˳���Ϸ\n");
	printf("***************************\n");
	printf("����������ѡ��");
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
			printf("byebye��\n");
			break;
		}else{
			printf("����������������������\n");
		}
	}
	system("pause");
	return 0;
}