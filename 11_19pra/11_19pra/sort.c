//#include<stdio.h>
//#include<windows.h>
//#include<stdlib.h>

//ģ��qsort�Ĺ���ʵ��һ��ͨ�õ�ð������
//����
//less:�����һ����Ӧ���ڵڶ�����֮ǰ����������
//���Ӧ���ڶ�����֮�󣬷��ظ���
//�����ȣ�����0��

//int less(const void* a,const void* b)
//{
//	return (*(int*)b - *(int*)a);
//}
//
//typedef int(*Cmp)(int, int);
//
//void bubbleSort(int arr[],int len,Cmp cmp)
//{
//	int temp=0;
//	//bound��һ���߽磬��ʾ��������[0,bound],bound����ѭ��������ֱ��bound=len-1,�������
//	//�������䣨bound,cur],ֱ��cur����bound+1,�������
//	//
//	for (int bound = 0; bound < len; bound++){
//		for (int cur = len - 1; cur>bound; cur--){
//			if (cmp(arr[cur-1],arr[cur])>0){
//				temp = arr[cur-1];
//				arr[cur-1] = arr[cur];
//				arr[cur] = temp;
//			}
//		}
//	}
//}

//int main()
//{
//	int arr[] = {9,3,5,7,4};
//	int len = sizeof(arr) / sizeof(arr[0]);
//	//bubbleSort(arr,len,less);
//	qsort(arr, 5, sizeof(int),less);
//	for (int i = 0; i < len; i++){
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//	system("pause");
//	return 0;
//}

//��ϰʹ�ÿ⺯����qsort����������͵�����
//������������
//#include<stdio.h>
//#include<windows.h>
//#include<stdlib.h>
//
//int less(const void *a, const void *b)
//{
//	return (*(int*)a - *(int*)b);
//}
//int main()
//{
//	int arr[] = { 8, 5, 3, 6, 9 };
//	int len = sizeof(arr) / sizeof(arr[0]);
//	qsort(arr,len, sizeof(int), less);
//	for (int i = 0; i < len; i++){
//		printf("%d", arr[i]);
//	}
//	printf("\n");
//	system("pause");
//	return 0;
//}

//�����ַ�����
//#include<stdio.h>
//#include<windows.h>
//#include<stdlib.h>
//
//int less(const void* a, const void*b)
//{
//	return (*(char*)a - *(char*)b);
//}
//int main()
//{
//	char arr[] = "cdaefg";
//	qsort(arr, strlen(arr), sizeof(char), less);
//	printf("%s\n", arr);
//	system("pause");
//	return 0;
//}

////����double��������
//#include<stdio.h>
//#include<windows.h>
//#include<stdlib.h>
//
//int less(const void* a, const void* b)
//{
//	return(*(double*)a - *(double*)b);
//}
//int main()
//{
//	double arr[] = { 2.3, 1.4, 5.2, 3.6 };
//	int len = sizeof(arr) / sizeof(arr[0]);
//	qsort(arr, len, sizeof(double), less);
//	for (int i = 0; i < len; i++){
//		printf("%f  ", arr[i]);
//	}
//	printf("\n");
//	system("pause");
//	return 0;
//}
