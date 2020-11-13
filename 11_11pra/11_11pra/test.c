//在屏幕上打印杨辉三角。
//1
//1 1
//1 2 1
//1 3 3 1
//……
//#include<stdio.h>
//#include<windows.h>
//#define MAX_ROW 7
//#define MAX_COL 7
//void YH(int arr[MAX_ROW][MAX_COL])
//{
//	for (int row = 0; row < MAX_ROW; row++){
//		for (int col = 0; col <= row; col++){
//			if (col == 0){
//				arr[row][0] = 1;
//			}else{
//				arr[row][col] = arr[row - 1][col] + arr[row - 1][col - 1];
//			}
//			printf("%d\t", arr[row][col]);
//		}
//		printf("\n");
//	}
//	printf("\n");
//}
//
//int main()
//{
//	int arr[MAX_ROW][MAX_COL] = {0};
//	YH(arr);
//	system("pause");
//	return 0;
//}

//日本某地发生了一件谋杀案，警察通过排查确定杀人凶手必为4个嫌疑犯的一个。
//以下为4个嫌疑犯的供词 :
//A说：不是我。
//B说：是C。
//C说：是D。
//D说：C在胡说
//已知3个人说了真话，1个人说的是假话。
//现在请根据这些信息，写一个程序来确定到底谁是凶手。
//#include<stdio.h>
//#include<windows.h>
//int main()
//{
//	int killer = 0;
//	for (killer = 'A'; killer <= 'D'; killer++)
//	{
//		if ((killer != 'A') + (killer == 'C') + (killer == 'D') + (killer != 'D') == 3)
//		{
//			printf("killer=%c\n", killer);
//			system("pause");
//			return 0;
//		}
//	}
//	system("pause");
//	return 1;
//}

/*5位运动员参加了10米台跳水比赛，有人让他们预测比赛结果：
A选手说：B第二，我第三；
B选手说：我第二，E第四；
C选手说：我第一，D第二；
D选手说：C最后，我第三；
E选手说：我第四，A第一；
比赛结束后，每位选手都说对了一半，请编程确定比赛的名次。
*/

//每个人的名次都有可能为 1，2，3，4，5
//无并列名次，所以五个名次相乘为120
//用异或来保证半句话真半句话假，即一句话中的两个半句话真假性不同，^ 相同为0，不同为1
//#include<stdio.h>
//#include<windows.h>
//
//int main()
//{
//	for (int a = 1; a <= 5; a++){
//		for (int b = 1; b <= 5; b++){
//			for (int c = 1; c <= 5; c++){
//				for (int d = 1; d <= 5; d++){
//					for (int e = 1; e <= 5; e++){
//						if ((a*b*c*d*e == 120)
//							&& (b == 2 ^ a == 3)
//							&& (b == 2 ^ e == 4)
//							&& (c == 1 ^ d == 2)
//							&& (c == 5 ^ d == 3)
//							&& (e == 4 ^ a == 1)){
//							printf("A:%d B:%d C:%d D:%d E:%d\n", a, b, c, d, e);
//						}
//					}
//				}
//			}
//		}
//	}
//	system("pause");
//	return 0;
//}
