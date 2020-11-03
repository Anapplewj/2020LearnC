//���ȴ���һ��3*3������
//��ʼ�����̣��ÿո����
//��ӡ���̣�ʹ���пɼ��ı߿�
//������ӣ����飩
//ϵͳ���ӣ����飩
//���Ӯ��ϵͳӮ������
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_ROW 3
#define MAX_COL 3
//�������
char playermove(char chessboard[MAX_ROW][MAX_COL])
{
	int row = 0;
	int col = 0;
	while (1){
		printf("�����������ӵ�λ�ã���row col��");
		scanf("%d %d", &row, &col);
		//У��
		//У�������Ƿ���������
		if (row < 0 || row >= MAX_ROW || col<0 || col>=MAX_COL){
			printf("��������Խ��!!\n");
			continue;
		}else if (chessboard[row][col]!=' '){
			printf("��λ��������!!\n");
			continue;
		}else{
			chessboard[row][col] = 'x';
			return chessboard[row][col];
		}

	}
}
//��������
void computermove(char chessboard[MAX_ROW][MAX_COL])
{
	while (1){
		int row = rand() % MAX_ROW;
		int col = rand() % MAX_COL;
		//У������λ���Ƿ��Ѿ�����
		if (chessboard[row][col] != ' '){
			continue;
		}
		chessboard[row][col] = 'o';
		break;
	}

}
//�ж������Ƿ���
//������1��δ������0
char isFull(char chessboard[MAX_ROW][MAX_COL])
{
	for (int row = 0; row < MAX_ROW; row++){
		for (int col = 0; col < MAX_COL; col++){
			//�ҵ��ո�
			if (chessboard[row][col] == ' '){
				return 0;
			}
		}
	}
	//δ�ҵ���������
	return 1;
}
//�ж��Ƿ�Ӯ
//'x'��ʾ��һ�ʤ
//'o'��ʾ���Ի�ʤ
//' '��ʾʤ��δ��
//'h'��ʾ����
char isWin(char chessboard[MAX_ROW][MAX_COL])
{
//ͬһ��
	for (int row = 0; row < MAX_ROW; row++){
		if (chessboard[row][0]!=' '
			&&(chessboard[row][0] ==chessboard[row][1])
			&&(chessboard[row][0]== chessboard[row][2])){
			return chessboard[row][0];
		}
	}
//ͬһ��
	for (int col = 0; col < MAX_COL; col++){
		if (chessboard[0][col]!=' '
			&&(chessboard[0][col] == chessboard[1][col])
			&&(chessboard[0][col] == chessboard[2][col])){
			return chessboard[0][col];
		}
	}
//�Խ�����ͬ
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
//����
	if (isFull(chessboard)){
		return 'h';
	}
	return ' ';
}

//��ʼ������
void init(char chessboard[MAX_ROW][MAX_COL])
{
	for (int row = 0; row < MAX_ROW; row++){
		for (int col = 0; col < MAX_COL; col++){
			chessboard[row][col] = ' ';
		}
	}
}
//��ӡ����
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
	init(chessboard);//��ʼ������
	char winner = ' ';
	while (1){
		printchessboard(chessboard);//��ӡ����
		playermove(chessboard);//�������
		//У�飬�Ƿ�Ӯ�Ƿ����
		winner = isWin(chessboard);
		if (winner != ' '){
			break;
		}
		computermove(chessboard);//��������
		winner = isWin(chessboard);
		if (winner != ' '){
			break;
		}
	}
	if (winner == 'x'){
		printchessboard(chessboard);
		printf("��ϲ��Ӯ�ˣ�\n");
	}else if (winner == 'o'){
		printchessboard(chessboard);
		printf("���ź������ˣ�\n");
	}else if (winner == 'h'){
		printchessboard(chessboard);
		printf("���壡���͵����弼�൱~\n");
	}
}
int menue(int choice)
{
	printf("************************\n");
	printf("1.��ʼ��Ϸ\n");
	printf("0.������Ϸ\n");
	printf("************************\n");
	printf("����������ѡ��");
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
			printf("����������������������\n");
			continue;
		}
	}
	system("pause");
	return 0;
}
