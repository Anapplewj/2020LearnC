//����Ļ�ϴ�ӡ������ǡ�
//1
//1 1
//1 2 1
//1 3 3 1
//����
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

//�ձ�ĳ�ط�����һ��ıɱ��������ͨ���Ų�ȷ��ɱ�����ֱ�Ϊ4�����ɷ���һ����
//����Ϊ4�����ɷ��Ĺ��� :
//A˵�������ҡ�
//B˵����C��
//C˵����D��
//D˵��C�ں�˵
//��֪3����˵���滰��1����˵���Ǽٻ���
//�����������Щ��Ϣ��дһ��������ȷ������˭�����֡�
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

/*5λ�˶�Ա�μ���10��̨��ˮ����������������Ԥ����������
Aѡ��˵��B�ڶ����ҵ�����
Bѡ��˵���ҵڶ���E���ģ�
Cѡ��˵���ҵ�һ��D�ڶ���
Dѡ��˵��C����ҵ�����
Eѡ��˵���ҵ��ģ�A��һ��
����������ÿλѡ�ֶ�˵����һ�룬����ȷ�����������Ρ�
*/

//ÿ���˵����ζ��п���Ϊ 1��2��3��4��5
//�޲������Σ���������������Ϊ120
//���������֤��仰���仰�٣���һ�仰�е�������仰����Բ�ͬ��^ ��ͬΪ0����ͬΪ1
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
