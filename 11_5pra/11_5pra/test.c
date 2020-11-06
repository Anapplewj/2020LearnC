//不允许创建临时变量，交换两个整数的内容
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<windows.h>
//
//int main()
//{
//	int num1 = 0;
//	int num2 = 0;
//	printf("请输入两个数字：");
//	scanf("%d %d", &num1, &num2);
//	num1 = num1 + num2;
//	num2 = num1 - num2;
//	num1 = num1 - num2;
//	printf("交换后两个数为：%d %d\n",num1,num2);
//	system("pause");
//	return 0;
//}

//统计二进制中1的个数
//写一个函数返回参数二进制中 1 的个数。
//比如： 15    0000 1111    4 个 1
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<windows.h>
//int binary(int num)
//{
//	int count = 0;
//	for (int i = 0; i < 32; i++){
//		if (num &(1 << i)){
//			count++;
//		}
//	}
//	return count;
//}
//int main()
//{
//	int num = 0;
//	printf("请输入一个数字：");
//	scanf("%d", &num);
//	printf("转化为二进制中1的个数为：%d\n", binary(num));
//	system("pause");
//	return 0;
//}

//打印整数二进制的奇数位和偶数位

//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<windows.h>
////打印偶数位
//void oddnum(int num)
//{
//	for (int i = 30; i >=0; i-=2){
//			if ((num &(1 << i))){
//				printf("1 ");
//			}else{
//				printf("0 ");
//			}
//	}
//	
//}
////打印奇数位
//void evennum(int num)
//{
//	for (int i = 31; i >=0; i -= 2){
//		if ((num &(1 << i))){
//			printf("1 ");
//		}
//		else{
//			printf("0 ");
//		}
//	}
//
//}
//
//int main()
//{
//	int num = 0;
//	printf("请输入一个数字：");
//	scanf("%x", &num);
//	printf("其二进制偶数位为：");
//	oddnum(num);
//	printf("\n其二进制奇数位为：");
//	evennum(num);
//	printf("\n");
//	system("pause");
//	return 0;
//}


//编程实现：两个int（32位）整数m和n的二进制表达中，有多少个位(bit)不同？
//输入例子 :
//1999 2299
//输出例子 : 7
//基本思想 操作符异或^，相同为0，不同为1.
//异或之后有多少个1就有多少位不同
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<windows.h>
//
//int bitEqual(int m, int n)
//{
//	int num = m^n;
//	int count = 0;
//	for (int i = 0; i < 32; i++){
//		if (num & (1 << i)){
//			count++;
//		}
//	}
//	return count;
//}
//int main()
//{
//	int m = 0;
//	int n = 0;
//	printf("请输入两个数字：");
//	scanf("%d %d", &m, &n);
//	printf("两个数字转化为二进制后有 %d 位不同\n", bitEqual(m, n));
//	system("pause");
//	return 0;
//}

//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<windows.h>
//
//int main()
//{
//	system("pause");
//	return 0;
//}

