#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<time.h>
#include<windows.h>

#define MAX_ROW 3
#define MAX_COL 3
//��ά����ʵ�ּ򵥵�������
//������Ҫһ��Ŀ¼
//Ȼ��׼��һ�����飬������Ӻ͵�������
//�������
void player(char chessBoard[MAX_ROW][MAX_COL]){
	while (1){
		printf("�������������ӵ�λ��(x,y)\n");
		int x = 0;
		int y = 0;
		scanf("%d,%d", &x, &y);
		if (x < 0 || x >= MAX_ROW || y<0 || y>MAX_COL){
			printf("����Խ�磬����������\n");
			continue;
		}
		else if (chessBoard[x][y] != ' '){
			printf("��λ�������ӣ�����������");
			continue;
		}
		else{
			chessBoard[x][y] = 'x';
			break;
		}
	}
}
//��������
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
	printf("========��������Ϸ========\n");
	printf("1.��ʼһ����Ϸ\n");
	printf("0.�˳�\n");
	printf("==========================\n");
	int choice = 0;
	while (1){
		printf("����������ѡ��:");		
		scanf("%d", &choice);
		if (choice == 0 || choice == 1){
			break;
		}else{
			printf("�밴����ʾ����!\n");
		}
	}
	return choice;
}
//�ж������Ƿ����ˣ�0Ϊδ����1Ϊ����
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
//�ж��Ƿ�Ӯ��
//Ӯ�˷���1��ûӮ����-1,���巵��0
//ͬһ����ͬ��ͬһ����ͬ������
int isWin(char chessBoard[MAX_ROW][MAX_COL]){
	//ͬһ����ͬ
	for (int i = 0; i < MAX_ROW; i++){
		if (chessBoard[i][0] == chessBoard[i][1] && chessBoard[i][1] == chessBoard[i][2]&&chessBoard[i][0]!=' '){
			return 1;
		}
	}
	//ͬһ����ͬ
	for (int i = 0; i < MAX_COL; i++){
		if (chessBoard[0][i] == chessBoard[1][i] && chessBoard[1][i] == chessBoard[2][i] && chessBoard[0][i] != ' '){
			return 1;
		}
	}
	//�Խ�����ͬ
	if (chessBoard[0][0] == chessBoard[1][1] && chessBoard[1][1] == chessBoard[2][2] && chessBoard[2][2] != ' '){
		return 1;
	}
	else if (chessBoard[0][2] == chessBoard[1][1] && chessBoard[1][1] == chessBoard[2][0] && chessBoard[2][0] != ' '){
		return 1;
	}
	//����
	if (isFull(chessBoard) == 1){
		return 0;
	}
	return -1;
}
//��ӡ����
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
			printf("��ϲ�㣬Ӯ���˵��ԣ�\n");
			return;
		}else if (choice == 0){
			printf("����\n");
			return;
		}
		computer(chessBoard);
		printChessBoard(chessBoard);
		choice = isWin(chessBoard);
		if (choice == 1){
			printf("������������Զ�����!\n");
			return;
		}else if (choice == 0){
			printf("����\n");
			return;
		}
	}
}
//��ʼ������
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