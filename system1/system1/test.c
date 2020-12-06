#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#define MAX_PROCESS 10

//进程资源结构体
typedef struct Resource
{
	int a;
	int b;
	int c;
	int d;
}Resource;

//进程列表，相当于一个通讯录
typedef struct List
{
	Resource Work[MAX_PROCESS];       //进程资源结构体数组
	Resource Allocation[MAX_PROCESS]; 
	Resource Need[MAX_PROCESS];      
	//size表示已有进程数
	int size;
}List;
//菜单
int menue()
{
	printf("**************************\n");
	printf("1.添加进程信息\n");
	printf("2.显示所有进程信息\n");
	printf("3.判断进程序列的安全性\n");
	printf("0.退出银行家算法\n");
	printf("**************************\n");
	printf("请输入您的选择:");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}
//初始化进程列表
void init(List* list)
{
	list->size = 0;
}
//添加进程信息
void addProcess(List* list)
{
	printf("添加进程!\n");
	//判断进程列表是否满了，如果满了，添加失败
	if (list->size >= MAX_PROCESS){
		printf("进程列表已满，添加失败!\n");
		return;
	}
	int currentSize = list->size;
	Resource* allo = &list->Allocation[currentSize];
	Resource* n = &list->Need[currentSize];
	printf("请输入进程所占A B C D资源数的多少:");
	scanf("%d%d%d%d", &allo->a, &allo->b, &allo->c, &allo->d);
	printf("请输入进程所需A B C D资源数的多少:");
	scanf("%d%d%d%d", &n->a, &n->b, &n->c, &n->d);
	list->size++;
	system("cls");
	printf("添加进程成功!\n");

}
void showProcess(List* list)
{
	printf("显示所有进程信息!\n");
	int currentSize = list->size;
	printf("p[ID]\t\tAllocation\t\t\t\t  Need\n");
	printf("\tA\tB\tC\tD\t|\tA\tB\tC\tD\n");
	for (int i = 0; i < currentSize; i++){
		Resource* allo = &list->Allocation[i];
		Resource* n = &list->Need[i];
		printf("p[%d]\t%d\t%d\t%d\t%d\t|\t%d\t%d\t%d\t%d\n", i, allo->a, allo->b, allo->c, allo->d, \
			n->a, n->b, n->c, n->d);
	}
	printf("已显示所有进程信息\n");
}
//判断进程是否安全
//判断安全得知道avalible
void isSafe(List* list, Resource* ava)
{
	printf("判断进程序列是否安全!\n");
	printf("请输入A B C D所剩资源数:");
	scanf("%d%d%d%d", &ava->a, &ava->b, &ava->c, &ava->d);
	int currentSize = list->size;
	int flag[MAX_PROCESS] = { 0 };//按照先后顺序保存已经执行进程的序号
	int arr[MAX_PROCESS] = { 0 }; //设置一个标记数组，初始化为全0，和进程序号相对应
	                             //已执行的替换成为1，最终通过判断1的个数是否等于进程总数
	                             //用于判断进程是否执行完
	//冒泡法，外层循环控制趟数，每一趟找出一个符合要求的进程，有几个进程，遍历几趟
	for (int bound = 0; bound < currentSize; bound++){
		//内层循环通过遍历从头到尾找出一个符合要求的进程
		for (int cur = 0; cur<currentSize; cur++){
			Resource* allo = &list->Allocation[cur];
			Resource* n = &list->Need[cur];
			//Resource* w = &list->Work[cur];			
			//如果所需资源数均&&小于等于所剩资源数，那么就执行这个进程，所剩资源数更新
			if ((n->a <= ava->a) && (n->b <= ava->b) && (n->c <= ava->c) && (n->d <= ava->d)){
				if (arr[cur] == 1){
					//每个进程仅执行一次，不重复
					//表示这个进程已经执行过了，那就判断下一个
					continue;
				}
				//更新avalible的信息
				ava->a = ava->a + allo->a;
				ava->b = ava->b + allo->b;
				ava->c = ava->c + allo->c;
				ava->d = ava->d + allo->d;
				arr[cur] = 1; //标记，置为1，表示当前位置已执行
				flag[bound] = cur; //记录已经执行的进程的编号
				break;
			}
		}
	}
	//用num表示1的个数，也就是已经执行的进程的个数
	int num = 0;
	for (int i = 0; i < currentSize; i++){
		if (arr[i] == 1){
			num++;
		}
	}
	//如果1的个数不等于总进程数（也可以说是小于），说明有进程没执行，即不存在安全序列
	if (num != currentSize){
		printf("不存在安全序列!\n");
	}
	else{
		printf("p[ID]\t\tAllocation\t\t\t\t  Need\n");
		printf("\tA\tB\tC\tD\t|\tA\tB\tC\tD\n");
		for (int i = 0; i < currentSize; i++){
			int flager=flag[i];
			Resource* allo = &list->Allocation[flager];
			Resource* n = &list->Need[flager];
			printf("p[%d]\t%d\t%d\t%d\t%d\t|\t%d\t%d\t%d\t%d\n", flager, allo->a, allo->b, allo->c, allo->d, \
			n->a, n->b, n->c, n->d);
			}
		printf("存在安全序列！安全序列为：\n");
		for (int i = 0; i < currentSize; i++){
			printf("%d->", flag[i]);
		}
		printf("\n");
	}
}
List list;
Resource ava;
int main()
{
	init(&list);
	while (1){
		int choice = menue();
		if (choice<0 || choice>3){
			printf("请按照提示输入!\n");
			continue;
		}else if (choice == 1){
			addProcess(&list);
		}else if (choice == 2){
			showProcess(&list);
		}else if (choice == 3){
			isSafe(&list, &ava);
		}else if (choice == 0){
			printf("byebye\n");
			break;
		}
	}
	system("pause");
	return 0;
}