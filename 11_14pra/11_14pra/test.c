#include<stdio.h>
#include<windows.h>

int main()
{
	//һ��Ҫ�ǵ��������Ԫ�صĵ�ַ�Ϳ��Եõ���������
	//int arr[] = { 1, 2, 3, 4 };
	//printf("%d\n", sizeof(arr));//����ͨ����Ԫ�صĵ�ַ������������
	//                           ��Ϊ�����е�Ԫ�����ڴ�����������ŵ�
	//                          ����arr���������飬����sizeof����4*4=16
	//printf("%d\n", sizeof(arr + 0));//��ʽת����Ϊָ����Ԫ�ص�ָ�룬��sizeof(int*)=4
	//printf("%d\n", sizeof(*arr));//��������ʾ��Ԫ�صĵ�ַ��*ʹ����ʽת����Ϊָ��int*,��������þ���sizeof(int)=4
	//printf("%d\n", sizeof(arr + 1));//sizeof(int *)=4
	//printf("%d\n", sizeof(arr[1]));//����ĵڶ���Ԫ����ռ�ռ�Ĵ�С��sizeof(int)=4
	//printf("%d\n", sizeof(&arr));//���������Ԫ�صĵ�ַȡ��ַ�õ�һ��ָ��sizeof(int(*)[4])=4
	//printf("%d\n",sizeof(*&arr));//sizeof(int[4])=16
	//printf("%d\n", sizeof(&*arr));//sizeof(int*)=4
	//printf("%d\n", sizeof(&arr + 1));//sizeof(int(*)[4]+1)=4
	//printf("%d\n", sizeof(&arr[0]));//sizeof(int *)=4
	//printf("%d\n", sizeof(&arr[0] + 1));//sizeof(int *)=4

	//char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
	//printf("%d\n", sizeof(arr));//sizeof(char[6])=6
	//printf("%d\n", sizeof(arr + 0));//sizeof(char*)=4
	//printf("%d\n", sizeof(*arr));//sizeof(char)=1
	//printf("%d\n", sizeof(arr+1));//sizeof(char*)=4
	//printf("%d\n", sizeof(arr[1]));//sizeof(char)=1
	//printf("%d\n", sizeof(&arr));//sizeof(char(*)[6])=4
	//printf("%d\n", sizeof(*&arr)); //sizeof(char[6])=6
	//printf("%d\n", sizeof(&*arr)); //sizeof(char*)=4
	//printf("%d\n", sizeof(&arr[1]+1));//sizeof(char*)=4
	//printf("%d\n", sizeof(&arr + 1));//sizeof(char(*)[6])=4
	
	//printf("%d\n", strlen(arr));//δ������Ϊ
	//printf("%d\n", strlen(arr+0));//strlen(char*)???δ������Ϊ
	//printf("%d\n", strlen(*arr));//strlen(arr[0])???
	//printf("%d\n", strlen(arr[1]));//???
	//printf("%d\n", strlen(&arr));//???
	//printf("%d\n", strlen(&arr + 1));//???
	//printf("%d\n", strlen(&arr[0]) + 1);//???


	//char arr[] = "abcdef";
	//printf("%d\n", sizeof(arr));//sizeof(char[7])=7
	//printf("%d\n", sizeof(arr+0));//sizeof(char*)=4
	//printf("%d\n", sizeof(*arr));//sizeof(char)=1
	//printf("%d\n", sizeof(arr[1]));//sizeof(char)=1
	//printf("%d\n", sizeof(&arr[0]+1));//sizeof(char*)=4
	//printf("%d\n", sizeof(&arr));//sizeof(char(*)[7])=4
	//printf("%d\n", sizeof(*&arr));//sizeof(char[7])=7
	//printf("%d\n", sizeof(&*arr));//sizeof(char*)=4
	//printf("%d\n", sizeof(&arr+1));//sizeof(char(*)[4])=4

	//��̫��
	//printf("%d\n", strlen(arr));//6
	//printf("%d\n", strlen(arr+1));//5
	//printf("%d\n", strlen(&arr+1));//���Ͳ�ƥ��
	//printf("%p\n", strlen(&arr));//6  ���Ͳ�ƥ��  strlen(char(*)[7])=6    strlen(const char * str)
	//printf("%d\n", strlen(&arr[0]));//strlen(char*arr[7])=6
	//printf("%d\n", strlen(*&arr));//char(*)[7]->char[7]  strlen(char[7])=6
	//printf("%d\n", strlen(&*arr));//char*arr[0]->char arr[0]->char *arr[0] strlen(char *arr[0])=6
	//printf("%d\n", strlen(&arr[1]+1));//char* arr[1]->char* arr[2] strlen(char* arr[2])=4 

	//char* p = "abcdef";
	//printf("%d\n", sizeof(p));//sizeof(char*)=4
	//printf("%d\n", sizeof(p + 1));//sizeof(char*)=4
	//printf("%d\n", sizeof(*p));//sizeof(char)=1
	//printf("%d\n", sizeof(p[0]));//sizeof(char)=1
	//printf("%d\n", sizeof(&p));//sizeof(char**)=4
	//printf("%d\n", sizeof(&p[1]+1));//sizeof(char*)=4
	//printf("%d\n", sizeof(*&p));//sizeof(char*)=4
	//printf("%d\n", sizeof(&*p));//sizeof(char**)=4

	//printf("%d\n",strlen(p));//strlen(char*[0])=6
	//printf("%d\n", strlen(p + 1));//strlen(char*[1])=5
   //printf("%d\n", strlen(*p));//strlen(char[0]) ���Ͳ�ƥ��
	//printf("%d\n", strlen(p[1]));//���Ͳ�ƥ��
 //   printf("%d\n", strlen(&p));//���Ͳ�ƥ��
	//printf("%d\n", strlen(&p[1] + 1));//strlen(char *p[2])=4
	//printf("%d\n", strlen(*&p));//strlen(char*)=6
	//printf("%d\n", strlen(&*p));//strlen(char*)=6

	//int arr[3][4] = { 0 };
	//printf("%d\n", sizeof(arr)); //sizeof(int[3][4]))=12*4=48
	//printf("%d\n", sizeof(arr[0]));//sizeof(int[4])=4*4=16
	//printf("%d\n", sizeof(arr[0]+1));//sizeof(int*[4])=4
	//printf("%d\n", sizeof(&arr[0]+1));//sizeof(int**[4])=4
	//printf("%d\n", sizeof(arr[0][0]));//sizeof(int)=4
	//printf("%d\n", sizeof(*arr[0]));//sizeof(int)=4
	//printf("%d\n", sizeof(*arr));//sizeof(int[4])=4*4=16
	//printf("%d\n", sizeof(*(arr + 1)));//sizeof(int[4])=16
	//printf("%d\n", sizeof(&arr[0] + 1));//sizeof(int*[4])=4
	//printf("%d\n", sizeof(*(arr[0]) + 1));//sizeof(int)=4

	//int a = 5;
	//int b = 10;
	////int* const p = &a; //p����ĵ�ַ���ܱ��޸�
	////p = &b;
	//const int* p = &a; //p�б���ĵ�ַ��ָ������ݲ��ܱ��޸ģ���a��ֵ���ܱ��޸�
	//*p = 20;
	//printf("%d\n", *p);

	/*int a[5] = { 1, 2, 3, 4, 5 };
	int* ptr = (int*)(&a + 1);
	printf("%d %d\n", *(a + 1), *(ptr - 1));*/

   int a[4] = { 1, 2, 3, 4 };
   int* ptr1 = (int*)(&a + 1);
   int* ptr2 = (int*)((int)a + 1);
   printf("%x,%x", ptr1[-1], *ptr2);
	system("pause");
	return 0;
}

//#include<stdio.h>
//#include<windows.h>
//
//int main()
//{
//	system("pause");
//	return 0;
//}