//ʵ��һ�������������ð������
//�������У��Ӵ�С�����ǰ��С�ں��棬�򽻻�
//���ѭ��i������������n������n-1��,ÿִ����һ�˾ͻ��ҵ�һ����С����
//ע���ٴαȽ�ʱ�����֮ǰ�ҵ�����С�ٱȣ������ڲ�ѭ��ִ��j<len-i��
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

//����һ���������飬��ɶ�����Ĳ���
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<windows.h>
//#define SIZE 5
////ʵ��reverse()  �����������Ԫ�ص����á�
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
////ʵ��print()  ��ӡ�����ÿ��Ԫ��
//void print(int arr[]){
//	for (int i = 0; i < SIZE; i++){
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
////ʵ�ֺ���init() ��ʼ������Ϊȫ0
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
//	printf("������������֣�");
//	for (int i = 0; i < SIZE; i++){
//		scanf("%d", &arr[i]);
//	}
//	printf("Ԫ������ǰ�������ǣ�");
//	print(arr);
//	printf("Ԫ�����ú�������ǣ�");
//	reverse(arr);
//	print(arr);
//	system("pause");
//	return 0;
//}

//������A�е����ݺ�����B�е����ݽ��н�����
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<windows.h>
#define SIZE 5
//�����м����temp
//����
void swap(int arr1[],int arr2[])
{
	int temp = 0;
	for (int i = 0; i < SIZE; i++){
		temp = arr1[i];
		arr1[i] = arr2[i];
		arr2[i] = temp;
	}
}
//��ӡ����
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
	printf("����ǰ������arr1�ǣ�");
	print(arr1);
	printf("����ǰ������arr2�ǣ�");
	print(arr2);
	swap(arr1, arr2);
	printf("�����������arr1�ǣ�");
	print(arr1);
	printf("����ǰ������arr2�ǣ�");
	print(arr2);
	system("pause");
	return 0;
}
