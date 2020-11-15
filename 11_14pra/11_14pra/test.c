#include<stdio.h>
#include<windows.h>

int main()
{
	//一定要记得数组的首元素的地址就可以得到整个数组
	//int arr[] = { 1, 2, 3, 4 };
	//printf("%d\n", sizeof(arr));//可以通过首元素的地址访问整个数组
	//                           因为数组中的元素在内存中是连续存放的
	//                          所以arr是整个数组，对它sizeof就是4*4=16
	//printf("%d\n", sizeof(arr + 0));//隐式转化成为指向首元素的指针，即sizeof(int*)=4
	//printf("%d\n", sizeof(*arr));//数组名表示首元素的地址，*使其隐式转化成为指针int*,对其解引用就是sizeof(int)=4
	//printf("%d\n", sizeof(arr + 1));//sizeof(int *)=4
	//printf("%d\n", sizeof(arr[1]));//数组的第二个元素所占空间的大小即sizeof(int)=4
	//printf("%d\n", sizeof(&arr));//对数组的首元素的地址取地址得到一个指针sizeof(int(*)[4])=4
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
	
	//printf("%d\n", strlen(arr));//未定义行为
	//printf("%d\n", strlen(arr+0));//strlen(char*)???未定义行为
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

	//不太会
	//printf("%d\n", strlen(arr));//6
	//printf("%d\n", strlen(arr+1));//5
	//printf("%d\n", strlen(&arr+1));//类型不匹配
	//printf("%p\n", strlen(&arr));//6  类型不匹配  strlen(char(*)[7])=6    strlen(const char * str)
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
   //printf("%d\n", strlen(*p));//strlen(char[0]) 类型不匹配
	//printf("%d\n", strlen(p[1]));//类型不匹配
 //   printf("%d\n", strlen(&p));//类型不匹配
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
	////int* const p = &a; //p保存的地址不能被修改
	////p = &b;
	//const int* p = &a; //p中保存的地址所指向的内容不能被修改，即a的值不能被修改
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