#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#define MAX_PROCESS 10

//���̽ṹ��
typedef struct Process
{
	int a;
	int b;
	int c;
	int d;
}Allocation,Need,Avalible;

//�����б��൱��һ��ͨѶ¼
typedef struct List
{
	Allocation allocation[MAX_PROCESS];
	Need need[MAX_PROCESS];
	//size��ʾ��Ч������
	int size;
}List;
//�˵�
int menue()
{
	printf("**************************\n");
	printf("1.��ӽ�����Ϣ\n");
	printf("2.��ʾ���н�����Ϣ\n");
	printf("3.�жϽ������еİ�ȫ��\n");
	printf("0.�˳����м��㷨\n");
	printf("**************************\n");
	printf("����������ѡ��:");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}
//��ʼ�������б�
void init(List* list)
{
	list->size = 0;
}
//��ӽ�����Ϣ
void addProcess(List* list)
{
	printf("��ӽ���!\n");
    //�жϽ����б��Ƿ����ˣ�������ˣ����ʧ��
	if (list->size >= MAX_PROCESS){
		printf("�����б����������ʧ��!\n");
		return;
	}
	int currentSize = list->size;
	Allocation* allo = &list->allocation[currentSize];
	Need* n = &list->need[currentSize];
	printf("�����������ռa b c d��Դ���Ķ���:");
	scanf("%d%d%d%d", &allo->a, &allo->b, &allo->c, &allo->d);
	printf("�������������a b c d��Դ���Ķ���:");
	scanf("%d%d%d%d", &n->a, &n->b,&n->c,&n->d);
	list->size++;
	system("cls");
	printf("��ӽ��̳ɹ�!\n");

}
void showProcess(List* list)
{
	printf("��ʾ���н�����Ϣ!\n");
	int currentSize = list->size;
	printf("\t\tAllocation\t\t\t    \tNeed\n");
	printf("\ta\tb\tc\td\t|\ta\tb\tc\td\n");
	for (int i = 0; i < currentSize; i++){
		Allocation* allo = &list->allocation[i];
		Need* n = &list->need[i];
		printf("p[%d]\t%d\t%d\t%d\t%d\t|\t%d\t%d\t%d\t%d\n",i,allo->a,allo->b,allo->c,allo->d,\
			n->a,n->b,n->c,n->d);
	}
	printf("����ʾ���н�����Ϣ\n");
}
//�жϽ����Ƿ�ȫ
//��ȫ����1������ȫ����0
//�жϰ�ȫ��֪��avalible
//Todo
int isSafe(List* list,Avalible* ava)
{
	printf("�жϽ��������Ƿ�ȫ!\n");
	printf("������a b c d��ʣ��Դ��:");
	scanf("%d%d%d%d", &ava->a, &ava->b, &ava->c, &ava->d);
	int currentSize = list->size;
	int flag = 0;//����һ����ǣ��ж��Ƿ�ִ�������н���
	//TODO FLAG
	
	for (bound = 0;bound<current)
    for (int i = 0; i < currentSize; i++){
		Allocation* allo = &list->allocation[i];
		Need* n = &list->need[i];
		//���������Դ����&&С�ڵ�����ʣ��Դ������ô��ִ��������̣���ʣ��Դ������
		//���������Դ������||��ʣ��Դ������ô��ִ��������̣�
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
			printf("�밴����ʾ����!\n");
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