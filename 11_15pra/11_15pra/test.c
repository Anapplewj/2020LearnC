#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
//写一个函数，判断一个字符串是否为另外一个字符串旋转之后的字符串。
//例如：给定s1 = AABCD和s2 = BCDAA，返回1
//给定s1 = abcd和s2 = ACBD，返回0.
//AABCD左旋一个字符得到ABCDA
//AABCD左旋两个字符得到BCDAA
//AABCD右旋一个字符得到DAABC
  
int isRevolve(char arr1[],char arr2[],int k)
{
	for (int i = 0; i < k; i++){
		for (int j = 0; j < k - 1; j++){
			char temp = arr1[j];
			arr1[j] = arr1[j + 1];
			arr1[j + 1] = temp;
			if (strcmp(arr1, arr2) == 0){
				return 1;
			}
		}
	}
	return 0;
}
int main()
{
	char arr1[20] = "";
	char arr2[20] = "";
	printf("请输入您要比较的两个字符串：");
	scanf("%s %s", arr1, arr2);
	if (isRevolve(arr1, arr2,strlen(arr1)) == 1){
		printf("通过旋转，两个字符串相等\n");
	}else{
		printf("通过旋转，两个字符串不相等\n");
	}
	system("pause");
	return 0;
}




//实现一个函数，可以左旋字符串中的k个字符。
//例如：
//ABCD左旋一个字符得到BCDA
//ABCD左旋两个字符得到CDAB

//左旋函数，将k个元素通过交换，交换到字符串的最右边，交换（字符串长度-1）次
//void revolve(char arr[],int k)
//{
//	int temp = 0;
//	for (int i = 0; i <k; i++){
//		for (int j = 0; j < strlen(arr) - 1; j++){
//			temp = arr[j];
//			arr[j] = arr[j + 1];
//			arr[j + 1] = temp;
//		}
//	}
//}
//
//int main()
//{
//	int k = 0;
//	char arr[] = "ABCD";
//	printf("旋转前的字符串为:");
//	printf("%s\n", arr);
//	printf("请输入您想要旋转的位数：");
//	scanf("%d", &k);
//	revolve(arr, k);
//	printf("左旋转后的结果为：");
//	printf("%s\n", arr);
//	system("pause");
//	return 0;
//}

