//#define _crt_secure_no_warnings
//#include<stdio.h>
//#include<windows.h>
//
////ʵ��һ����������ӡ�˷��ھ����ھ���������������Լ�ָ��
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
//	printf("�������Զ���˷��ھ�������֣�");
//	scanf("%d",&num);
//	mutiForm(num);
//	system("pause");
//	return 0;
//}

//#define _crt_secure_no_warnings
//#include<stdio.h>
//#include<windows.h>
////ʵ��һ��������������������������
//int swap(int* x, int* y){
//	int temp = *x;
//	*x = *y;
//	*y = temp;
//}
//int main()
//{
//	int a = 10;
//	int b = 20;
//	printf("����ǰ��������Ϊ��%d %d\n", a, b);
//	swap(&a, &b);
//	printf("�������������Ϊ��%d %d\n", a, b);
//	system("pause");
//	return 0;
//}

//#define _crt_secure_no_warnings
//#include<stdio.h>
//#include<windows.h>
//
////ʵ�ֺ����ж�year�ǲ�������
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
//	printf("������Ҫ�жϵ���ݣ�");
//	scanf("%d", &year);
//	if (isleapyear(year)==1){
//		printf("%d��������\n", year);
//	}else{
//		printf("%d�겻������\n", year);
//	}
//	system("pause");
//	return 0;
//}
//
//#define _crt_secure_no_warnings
//#include<stdio.h>
//#include<windows.h>
////��������ʵ�ֵĺ�����ӡ100��200֮�������
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
//	printf("100~200֮��������У�\n");
//	for (int i = 100; i < 200; i++){
//		if (isPrime(i) == 1){
//			printf("%d  ", i);
//		}
//	}
//	printf("\n");
//	system("pause");
//	return 0;
//}
////�����ж�����  1��ʾ�ǣ�0��ʾ����
//int main()
//{
//	int num = 0;
//	int rep = 0;
//	printf("������һ�����֣�");
//	scanf("%d",&num);
//	if (isPrime(num) == 0){
//		printf("%d��������\n",num);
//	}else{
//		printf("%d������\n", num);
//	}
//	system("pause");
//	return 0;
//}


#define _crt_secure_no_warnings
#include<stdio.h>
#include<windows.h>
//�ǵݹ�
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
	printf("������һ�����֣�");
	scanf("%d", &num);
	printf("%d�Ľ׳��ǣ�%d\n", num, JC(num));
	system("pause");
	return 0;	
}

#define _crt_secure_no_warnings
#include<stdio.h>
#include<windows.h>
//�ݹ�ͷǵݹ�ֱ�ʵ����n�Ľ׳ˣ���������������⣩
//�ݹ�ķ���
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
	printf("������һ�����֣�");
	scanf("%d", &num);
	printf("%d�Ľ׳��ǣ�%d\n", num, JC(num));
	system("pause");
	return 0;

}
//#define _crt_secure_no_warnings
//#include<stdio.h>
//#include<windows.h>
//
////�ݹ鷽ʽʵ�ִ�ӡһ��������ÿһλ
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
//	printf("%d��ÿһλ�ֱ���:",num);
//	printNum(num);
//	printf("\n");
//	system("pause");
//	return 0;
//}
//























