#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#define MAX_PROCESS 10

//进程结构体
typedef struct Process
{
	int a;
	int b;
	int c;
	int d;
}Allocation,Need,Avalible;

//进程列表，相当于一个通讯录
typedef struct List
{
	Allocation allocation[MAX_PROCESS];
	Need need[MAX_PROCESS];
	//size表示有效进程数
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
	Allocation* allo = &list->allocation[currentSize];
	Need* n = &list->need[currentSize];
	printf("请输入进程所占a b c d资源数的多少:");
	scanf("%d%d%d%d", &allo->a, &allo->b, &allo->c, &allo->d);
	printf("请输入进程所需a b c d资源数的多少:");
	scanf("%d%d%d%d", &n->a, &n->b,&n->c,&n->d);
	list->size++;
	system("cls");
	printf("添加进程成功!\n");

}
void showProcess(List* list)
{
	printf("显示所有进程信息!\n");
	int currentSize = list->size;
	printf("\t\tAllocation\t\t\t    \tNeed\n");
	printf("\ta\tb\tc\td\t|\ta\tb\tc\td\n");
	for (int i = 0; i < currentSize; i++){
		Allocation* allo = &list->allocation[i];
		Need* n = &list->need[i];
		printf("p[%d]\t%d\t%d\t%d\t%d\t|\t%d\t%d\t%d\t%d\n",i,allo->a,allo->b,allo->c,allo->d,\
			n->a,n->b,n->c,n->d);
	}
	printf("已显示所有进程信息\n");
}
//判断进程是否安全
//安全返回1，不安全返回0
//判断安全得知道avalible
//Todo
int isSafe(List* list,Avalible* ava)
{
	printf("判断进程序列是否安全!\n");
	printf("请输入a b c d所剩资源数:");
	scanf("%d%d%d%d", &ava->a, &ava->b, &ava->c, &ava->d);
	int currentSize = list->size;
	int flag = 0;//设置一个标记，判断是否执行完所有进程
	//TODO FLAG
	
	for (bound = 0;bound<current)
    for (int i = 0; i < currentSize; i++){
		Allocation* allo = &list->allocation[i];
		Need* n = &list->need[i];
		//如果所需资源数均&&小于等于所剩资源数，那么就执行这个进程，所剩资源数更新
		//如果所需资源数大于||所剩资源数，那么不执行这个进程，
		if ()

		flag++;
	}
}
typedef void(*Func)(List* list);
List list;
int main()
{
	init(&list);
	Func funcs[] = { NULL, &addProcess, &showProcess };//&isSafe
	while (1){
		int choice = menue();
		if (choice<0 || choice>sizeof(funcs) / sizeof(funcs[0])){
			printf("请按照提示输入!\n");
			continue;
		}
		if (choice == 0){
			printf("byebye\n");
			break;
		}
		funcs[choice](&list);

	}
	system("pause");
	return 0;
}