//#define _crt_secure_no_warnings
//#include<stdio.h>
//#include<windows.h>
//
////实现一个函数，打印乘法口诀表，口诀表的行数和列数自己指定
//void mutiForm(int num1){
//	for (int i = 1; i <= num1; i++){
//		for (int j = 1; j <= i; j++){
//			printf("%d*%d=%d\t", j, i, i*j);
//		}
//		printf("\n");
//	}
//}
//int main()
//{
//	int num = 0;
//	printf("请输入自定义乘法口诀表的数字：");
//	scanf("%d",&num);
//	mutiForm(num);
//	system("pause");
//	return 0;
//}

//#define _crt_secure_no_warnings
//#include<stdio.h>
//#include<windows.h>
////实现一个函数来交换两个整数的内容
//int swap(int* x, int* y){
//	int temp = *x;
//	*x = *y;
//	*y = temp;
//}
//int main()
//{
//	int a = 10;
//	int b = 20;
//	printf("交换前的两个数为：%d %d\n", a, b);
//	swap(&a, &b);
//	printf("交换后的两个数为：%d %d\n", a, b);
//	system("pause");
//	return 0;
//}

//#define _crt_secure_no_warnings
//#include<stdio.h>
//#include<windows.h>
//
////实现函数判断year是不是润年
//int isleapyear(int year){
//	if (year % 4 == 0 && year%100!=0){
//			return 1;
//	}else if (year % 400 == 0){
//		return 1;
//	}else{
//		return 0;
//	}	
//}
//
//int main()
//{
//	int year = 0;
//	printf("请输入要判断的年份：");
//	scanf("%d", &year);
//	if (isleapyear(year)==1){
//		printf("%d年是闰年\n", year);
//	}else{
//		printf("%d年不是闰年\n", year);
//	}
//	system("pause");
//	return 0;
//}
//
//#define _crt_secure_no_warnings
//#include<stdio.h>
//#include<windows.h>
////利用上面实现的函数打印100到200之间的素数
//int isprime(int num)
//{
//	for (int i = 2; i<num; i++){
//		if (num % i == 0){
//			return 0;
//		}
//	}
//	return 1;
//}
//
//int main()
//{
//	printf("100~200之间的素数有：\n");
//	for (int i = 100; i < 200; i++){
//		if (isPrime(i) == 1){
//			printf("%d  ", i);
//		}
//	}
//	printf("\n");
//	system("pause");
//	return 0;
//}
////函数判断素数  1表示是，0表示不是
//int main()
//{
//	int num = 0;
//	int rep = 0;
//	printf("请输入一个数字：");
//	scanf("%d",&num);
//	if (isPrime(num) == 0){
//		printf("%d不是素数\n",num);
//	}else{
//		printf("%d是素数\n", num);
//	}
//	system("pause");
//	return 0;
//}


#define _crt_secure_no_warnings
#include<stdio.h>
#include<windows.h>
//非递归
int JC(int num)
{
	int sum = 1;
	for (int i = 1; i <= num; i++)
	{
		sum *= i;
	}
	return sum;
}

int main()
{
	int num = 0;
	printf("请输入一个数字：");
	scanf("%d", &num);
	printf("%d的阶乘是：%d\n", num, JC(num));
	system("pause");
	return 0;	
}

#define _crt_secure_no_warnings
#include<stdio.h>
#include<windows.h>
//递归和非递归分别实现求n的阶乘（不考虑溢出的问题）
//递归的方法
int JC(int num)
{
	if (num == 1){
		return 1;
	}
	return num*JC(num - 1);
}


int main()
{
	int num = 0;
	int sum = 1;
	printf("请输入一个数字：");
	scanf("%d", &num);
	printf("%d的阶乘是：%d\n", num, JC(num));
	system("pause");
	return 0;

}
//#define _crt_secure_no_warnings
//#include<stdio.h>
//#include<windows.h>
//
////递归方式实现打印一个整数的每一位
//void printNum(int num)
//{
//	if (num >9){
//		printNum(num / 10); 
//	}
//	printf("%d", num % 10);
//}
//
//int main()
//{
//	int num = 1234;
//	printf("%d的每一位分别是:",num);
//	printNum(num);
//	printf("\n");
//	system("pause");
//	return 0;
//}
//























