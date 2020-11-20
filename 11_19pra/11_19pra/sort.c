//#include<stdio.h>
//#include<windows.h>
//#include<stdlib.h>

//模仿qsort的功能实现一个通用的冒泡排序
//升序
//less:如果第一个数应该在第二个数之前，返回正数
//如果应该在二个数之后，返回负数
//如果相等，返回0；

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
//	//bound是一个边界，表示已排区间[0,bound],bound控制循环次数，直到bound=len-1,排序结束
//	//待排区间（bound,cur],直到cur等于bound+1,排序结束
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

//练习使用库函数，qsort排序各种类型的数据
//排序整形数组
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

//排列字符数组
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

////排列double类型数据
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
