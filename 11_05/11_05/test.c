//写一个函数打印arr数组的内容，不使用数组下标，使用指针。
//arr是一个整形一维数组。
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

//写一个函数，可以逆序一个字符串的内容。
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

//求Sn = a + aa + aaa + aaaa + aaaaa的前5项之和，其中a是一个数字，
//例如：2 + 22 + 222 + 2222 + 22222
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
//	printf("请输入两个数字：(您想计算的某个数的前某项)");
//	scanf("%d %d", &a,&count);
//	printf("前%d项之和为%d\n", count,Sn(a, count));
//	system("pause");
//	return 0;
//}

//喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水，给20元，可以多少汽水（编程实现）。
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<windows.h>

struct Drink
{
	int price;         //汽水的单价
	int empty;         //几个空瓶可以兑换一瓶新的
	int embottle;      //空瓶的个数
	int money;         //用多少钱来喝
	int num;           //能喝多少
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
	printf("一瓶汽水多少元？\n");
	scanf("%d", &drink.price);
	printf("几个空瓶子可以换一瓶汽水？\n");
	scanf("%d", &drink.empty);
	printf("请问您用多少钱来喝汽水？\n");
	scanf("%d", &drink.money);
	howmany();
	printf("您可以喝%d瓶汽水\n", drink.num);
	system("pause");
	return 0;
}