//дһ��������ӡarr��������ݣ���ʹ�������±꣬ʹ��ָ�롣
//arr��һ������һά���顣
//
//#include<stdio.h>
//#include<windows.h>
//#define len 5
//void printarr(int* arr)
//{
//	for (int i = 0; i < len; i++){
//		printf("%d ", *(arr + i));
//	}
//}
//
//int main()
//{
//	int arr[5] = { 1, 2, 3, 4, 5 };
//	printarr(arr);
//	printf("\n");
//	system("pause");
//	return 0;
//}

//дһ����������������һ���ַ��������ݡ�
//#include<stdio.h>
//#include<windows.h>
//#include<stdlib.h>
//
//void reversestr(char* str)
//{
//	for (int i = strlen(str) - 1; i >= 0; i--)
//	{
//		printf("%c", *(str + i));
//	}
//}
//
//int main()
//{
//	char str[] = "helloworld";
//	reversestr(str);
//	printf("\n");
//	system("pause");
//	return 0;
//}

//��Sn = a + aa + aaa + aaaa + aaaaa��ǰ5��֮�ͣ�����a��һ�����֣�
//���磺2 + 22 + 222 + 2222 + 22222
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<windows.h>
//
//int Sn(int a, int count)
//{
//	int sum = 0;
//	for (int i = 0; i<count; i++){
//		if (i == 0){
//			sum = a;
//		}else{
//			a = a % 10 + a * 10;
//			sum = sum + a;
//		}
//	}
//	return sum;
//}
//
//int main()
//{
//	int a = 0;
//	int count = 0;
//	printf("�������������֣�(��������ĳ������ǰĳ��)");
//	scanf("%d %d", &a,&count);
//	printf("ǰ%d��֮��Ϊ%d\n", count,Sn(a, count));
//	system("pause");
//	return 0;
//}

//����ˮ��1ƿ��ˮ1Ԫ��2����ƿ���Ի�һƿ��ˮ����20Ԫ�����Զ�����ˮ�����ʵ�֣���
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<windows.h>

struct Drink
{
	int price;         //��ˮ�ĵ���
	int empty;         //������ƿ���Զһ�һƿ�µ�
	int embottle;      //��ƿ�ĸ���
	int money;         //�ö���Ǯ����
	int num;           //�ܺȶ���
}drink;

void howmany()
{
	drink.num = 0;
	drink.embottle = 0;
	for (int i = 1; i <= drink.money; i+=drink.price){
		drink.num++;
		drink.embottle++;
		if (drink.embottle==drink.empty){
			drink.num++;
			drink.embottle = 1;
		}
	}
}
int main()
{
	printf("һƿ��ˮ����Ԫ��\n");
	scanf("%d", &drink.price);
	printf("������ƿ�ӿ��Ի�һƿ��ˮ��\n");
	scanf("%d", &drink.empty);
	printf("�������ö���Ǯ������ˮ��\n");
	scanf("%d", &drink.money);
	howmany();
	printf("�����Ժ�%dƿ��ˮ\n", drink.num);
	system("pause");
	return 0;
}