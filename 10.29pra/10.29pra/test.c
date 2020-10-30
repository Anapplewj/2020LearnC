//递归和非递归分别实现strlen
////非递归
//#include<stdio.h>
//#include<windows.h>
////用count计数，遇到'\0'就结束
//int strLen(char arr[])
//{
//	int count = 0;
//	for (int i = 0; arr[i] != '\0'; i++){
//		count++;
//	}
//	return count;
//}
//
//int main()
//{
//	char arr[] = "helloworld";
//	printf("字符串的长度为：%d\n", strLen(arr));
//	system("pause");
//	return 0;
//}
//递归
//如果是'\0'，就说明字符串为空，便结束
//否则继续递归，直到遇到'\0'
//#include<stdio.h>
//#include<windows.h>
//
//int strLen(char arr[])
//{
//	if (arr[0] == '\0'){
//		return 0;
//	}
//	return 1 + strLen(arr + 1);
//}
//int main()
//{
//	char arr[] = "helloworld";
//	printf("字符串的长度为：%d\n", strLen(arr));
//	system("pause");
//	return 0;
//}



//写一个递归函数DigitSum(n)，输入一个非负整数，返回组成它的数字之和
//例如，调用DigitSum(1729)，则应该返回1 + 7 + 2 + 9，它的和是19
//输入：1729，输出：19
//
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<windows.h>
//
//int DigitSum(int n)
//{
//	if (n <=9){
//		return n;
//	}
//	return n % 10 + DigitSum(n / 10);
//}
//int main()
//{
//	int n = 0;
//	printf("请输入一个数字：");
//	scanf("%d", &n);
//	printf("数字之和是：%d\n", DigitSum(n));
//	system("pause");
//	return 0;
//}


////编写一个函数实现n的k次方，使用递归实现。
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<windows.h>
//
//int power(int n,int k)
//{
//	if (k == 0){
//		return 1;
//	}
//	return n*power(n, k - 1);
//}
//int main()
//{
//	int n = 0;
//	int k = 0;
//	printf("请输入底数和幂：");
//	scanf("%d %d", &n, &k);
//	printf("%d的%d次方是:%d\n", n, k, power(n, k));
//	system("pause");
//	return 0;
//}

//递归和非递归分别实现求第n个斐波那契数
//递归
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<windows.h>
//
//int Fib(int n)
//{
//	if (n == 1 || n == 2){
//		return 1;
//	}
//	return Fib(n - 1) + Fib(n - 2);
//}
//int main()
//{
//	int n = 0;
//	printf("请输入一个数字：");
//	scanf("%d", &n);
//	printf("%d个斐波那契数是：%d\n", n, Fib(n));
//	system("pause");
//	return 0;
//}

////非递归
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<windows.h>
//
//int Fib(int n)
//{
//	int last1 = 1;
//	int last2 = 1;
//	int cur = 0;
//	for (int i = 3; i<=n; i++){
//		cur = last1 + last2;
//		last2 = last1;
//		last1 = cur;
//	}
//	return cur;
//}
//
//int main()
//{
//	int n = 0;
//	printf("请输入一个数字：");
//	scanf("%d", &n);
//	printf("%d个斐波那契数是：%d\n", n, Fib(n));
//	system("pause");
//	return 0;
//}


//编写一个函数 reverse_string(char * string)（递归实现）
//实现：将参数字符串中的字符反向排列。
//要求：不能使用C函数库中的字符串操作函数。
//按逆序将字符存入数组
//结束条件：如果字符串长度等于0或者等于1就停止交换
//首先保存字符串首元素
//最后一个字符和第一个字符交换位置
//为了完成指向字符串末尾的指针向前推进，最后一个设置为'\0'
//递归调用
//把保存的字符串首元素放回到字符串末尾
#include<stdio.h>
#include<windows.h>

int reverse_string(char *string)
{
	if (strlen(string) < 2){
		return string;
	}
	char ch = *string;
	int len = strlen(string) - 1;
	*string = *(string + len);
	*(string + len) = '\0';
	reverse_string(string + 1);
	*(string + len) = ch;
	return string;
	
}

int main()
{
	char string[] = "helloworld";
	printf("%s\n", reverse_string(string));
	system("pause");
	return 0;
}
