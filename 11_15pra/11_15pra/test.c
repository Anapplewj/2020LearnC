#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
//дһ���������ж�һ���ַ����Ƿ�Ϊ����һ���ַ�����ת֮����ַ�����
//���磺����s1 = AABCD��s2 = BCDAA������1
//����s1 = abcd��s2 = ACBD������0.
//AABCD����һ���ַ��õ�ABCDA
//AABCD���������ַ��õ�BCDAA
//AABCD����һ���ַ��õ�DAABC
  
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
	printf("��������Ҫ�Ƚϵ������ַ�����");
	scanf("%s %s", arr1, arr2);
	if (isRevolve(arr1, arr2,strlen(arr1)) == 1){
		printf("ͨ����ת�������ַ������\n");
	}else{
		printf("ͨ����ת�������ַ��������\n");
	}
	system("pause");
	return 0;
}




//ʵ��һ�����������������ַ����е�k���ַ���
//���磺
//ABCD����һ���ַ��õ�BCDA
//ABCD���������ַ��õ�CDAB

//������������k��Ԫ��ͨ���������������ַ��������ұߣ��������ַ�������-1����
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
//	printf("��תǰ���ַ���Ϊ:");
//	printf("%s\n", arr);
//	printf("����������Ҫ��ת��λ����");
//	scanf("%d", &k);
//	revolve(arr, k);
//	printf("����ת��Ľ��Ϊ��");
//	printf("%s\n", arr);
//	system("pause");
//	return 0;
//}

