//实现一个对整形数组的冒泡排序
//降序排列，从大到小，如果前面小于后面，则交换
//外层循环i控制趟数，有n个数比n-1趟,每执行完一趟就会找到一个最小的数
//注意再次比较时无须和之前找到的最小再比，所以内层循环执行j<len-i趟
//#include<stdio.h>
//#include<windows.h>
//
//void bubbleSort(int arr[],int len)
//{
//	int temp;
//	for (int i = 0; i < len-1; i++){
//		for (int j = 0; j < len-i; j++){
//			if (arr[j] < arr[j + 1]){
//				temp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = temp;
//			}
//		}
//	}
//}
//
//int main()
//{
//	int arr[] = { 2, 7, 5, 9, 12 };
//	int len = sizeof(arr) / sizeof(arr[0]);
//	bubbleSort(arr,len);
//	for (int i = 0; i < len; i++){
//		printf("%d  ", arr[i]);
//	}
//	printf("\n");
//	system("pause");
//	return 0;
//}

//创建一个整形数组，完成对数组的操作
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<windows.h>
//#define SIZE 5
////实现reverse()  函数完成数组元素的逆置。
//void reverse(int arr[])
//{
//	int swap[SIZE] = { 0 };
//	for (int i = 0; i < SIZE; i++){
//		swap[i] = arr[SIZE-1 - i];
//	}
//	for (int i = 0; i < SIZE; i++){
//		arr[i] = swap[i];
//	}
//}
////实现print()  打印数组的每个元素
//void print(int arr[]){
//	for (int i = 0; i < SIZE; i++){
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
////实现函数init() 初始化数组为全0
//void init(int arr[])
//{
//	for (int i = 0; i < SIZE; i++){
//		arr[i] = 0;
//	}
//	
//}
//int main()
//{
//	int arr[SIZE] = {0};
//	init(arr);
//	printf("请输入五个数字：");
//	for (int i = 0; i < SIZE; i++){
//		scanf("%d", &arr[i]);
//	}
//	printf("元素逆置前的数组是：");
//	print(arr);
//	printf("元素逆置后的数组是：");
//	reverse(arr);
//	print(arr);
//	system("pause");
//	return 0;
//}

//将数组A中的内容和数组B中的内容进行交换。
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<windows.h>
#define SIZE 5
//采用中间变量temp
//交换
void swap(int arr1[],int arr2[])
{
	int temp = 0;
	for (int i = 0; i < SIZE; i++){
		temp = arr1[i];
		arr1[i] = arr2[i];
		arr2[i] = temp;
	}
}
//打印数组
void print(int arr[]){
	for (int i = 0; i < SIZE; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}
int main()
{
	int arr1[SIZE] = { 2, 3, 4, 5, 6 };
	int arr2[SIZE] = { 9, 5, 2, 7, 1 };
	printf("交换前的数组arr1是：");
	print(arr1);
	printf("交换前的数组arr2是：");
	print(arr2);
	swap(arr1, arr2);
	printf("交换后的数组arr1是：");
	print(arr1);
	printf("交换前的数组arr2是：");
	print(arr2);
	system("pause");
	return 0;
}
