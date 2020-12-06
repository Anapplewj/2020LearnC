#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#define MAX_PROCESS 10

//������Դ�ṹ��
typedef struct Resource
{
	int a;
	int b;
	int c;
	int d;
}Resource;

//�����б��൱��һ��ͨѶ¼
typedef struct List
{
	Resource Work[MAX_PROCESS];       //������Դ�ṹ������
	Resource Allocation[MAX_PROCESS]; 
	Resource Need[MAX_PROCESS];      
	//size��ʾ���н�����
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
	Resource* allo = &list->Allocation[currentSize];
	Resource* n = &list->Need[currentSize];
	printf("�����������ռA B C D��Դ���Ķ���:");
	scanf("%d%d%d%d", &allo->a, &allo->b, &allo->c, &allo->d);
	printf("�������������A B C D��Դ���Ķ���:");
	scanf("%d%d%d%d", &n->a, &n->b, &n->c, &n->d);
	list->size++;
	system("cls");
	printf("��ӽ��̳ɹ�!\n");

}
void showProcess(List* list)
{
	printf("��ʾ���н�����Ϣ!\n");
	int currentSize = list->size;
	printf("p[ID]\t\tAllocation\t\t\t\t  Need\n");
	printf("\tA\tB\tC\tD\t|\tA\tB\tC\tD\n");
	for (int i = 0; i < currentSize; i++){
		Resource* allo = &list->Allocation[i];
		Resource* n = &list->Need[i];
		printf("p[%d]\t%d\t%d\t%d\t%d\t|\t%d\t%d\t%d\t%d\n", i, allo->a, allo->b, allo->c, allo->d, \
			n->a, n->b, n->c, n->d);
	}
	printf("����ʾ���н�����Ϣ\n");
}
//�жϽ����Ƿ�ȫ
//�жϰ�ȫ��֪��avalible
void isSafe(List* list, Resource* ava)
{
	printf("�жϽ��������Ƿ�ȫ!\n");
	printf("������A B C D��ʣ��Դ��:");
	scanf("%d%d%d%d", &ava->a, &ava->b, &ava->c, &ava->d);
	int currentSize = list->size;
	int flag[MAX_PROCESS] = { 0 };//�����Ⱥ�˳�򱣴��Ѿ�ִ�н��̵����
	int arr[MAX_PROCESS] = { 0 }; //����һ��������飬��ʼ��Ϊȫ0���ͽ���������Ӧ
	                             //��ִ�е��滻��Ϊ1������ͨ���ж�1�ĸ����Ƿ���ڽ�������
	                             //�����жϽ����Ƿ�ִ����
	//ð�ݷ������ѭ������������ÿһ���ҳ�һ������Ҫ��Ľ��̣��м������̣���������
	for (int bound = 0; bound < currentSize; bound++){
		//�ڲ�ѭ��ͨ��������ͷ��β�ҳ�һ������Ҫ��Ľ���
		for (int cur = 0; cur<currentSize; cur++){
			Resource* allo = &list->Allocation[cur];
			Resource* n = &list->Need[cur];
			//Resource* w = &list->Work[cur];			
			//���������Դ����&&С�ڵ�����ʣ��Դ������ô��ִ��������̣���ʣ��Դ������
			if ((n->a <= ava->a) && (n->b <= ava->b) && (n->c <= ava->c) && (n->d <= ava->d)){
				if (arr[cur] == 1){
					//ÿ�����̽�ִ��һ�Σ����ظ�
					//��ʾ��������Ѿ�ִ�й��ˣ��Ǿ��ж���һ��
					continue;
				}
				//����avalible����Ϣ
				ava->a = ava->a + allo->a;
				ava->b = ava->b + allo->b;
				ava->c = ava->c + allo->c;
				ava->d = ava->d + allo->d;
				arr[cur] = 1; //��ǣ���Ϊ1����ʾ��ǰλ����ִ��
				flag[bound] = cur; //��¼�Ѿ�ִ�еĽ��̵ı��
				break;
			}
		}
	}
	//��num��ʾ1�ĸ�����Ҳ�����Ѿ�ִ�еĽ��̵ĸ���
	int num = 0;
	for (int i = 0; i < currentSize; i++){
		if (arr[i] == 1){
			num++;
		}
	}
	//���1�ĸ����������ܽ�������Ҳ����˵��С�ڣ���˵���н���ûִ�У��������ڰ�ȫ����
	if (num != currentSize){
		printf("�����ڰ�ȫ����!\n");
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
		printf("���ڰ�ȫ���У���ȫ����Ϊ��\n");
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
			printf("�밴����ʾ����!\n");
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