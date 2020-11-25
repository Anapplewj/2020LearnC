#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<windows.h>
//����һ����ϵ����Ϣ�Ľṹ��
typedef struct Person
{
	char name[1024];
	char tel[1024];
}Person;
//����һ��ͨѶ¼�ṹ��
#define MAX_PERSON 1024
typedef struct AddressBook
{
	Person Persons[MAX_PERSON];
	//size��ʾ������ϵ����
	int size;
}AddressBook;


int menue()
{
	printf("**************************\n");
	printf("1.������ϵ��\n");
	printf("2.������ϵ��\n");
	printf("3.ɾ����ϵ��\n");
	printf("4.�޸���ϵ��\n");
	printf("5.�鿴������ϵ��\n");
	printf("6.���������ϵ��\n");
	printf("0.�˳�\n");
	printf("**************************\n");
	printf("����������ѡ��:");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}

//��ʼ��ͨѶ¼
void init(AddressBook* addressBook)
{
//ֻ��Ҫ��������ϵ�˵Ķ�����Ϊ0
	addressBook->size = 0;
}

//������ϵ��
void addPerson(AddressBook* addressBook)
{
	printf("������ϵ��!\n");
	int currentSize = addressBook->size;
	if (currentSize >= MAX_PERSON){
		printf("ͨѶ¼����������ʧ�ܣ�");
		return;
	}
	Person* p = &addressBook->Persons[currentSize];
	printf("������������ϵ�˵�������\n");
	scanf("%s",p->name);
	printf("������������ϵ�˵ĵ绰:\n");
	scanf("%s", p->tel);
	addressBook->size++;
	printf("������ϵ�˳ɹ�!\n");
}
void findPerson(AddressBook* addressBook)
{
//�������ֲ���
	printf("������ϵ��!\n");
	int currentSize = addressBook->size;
	printf("������Ҫ������ϵ�˵�����:");
	char name[1024] = {0};
	scanf("%s",name);
	for (int i = 0; i < currentSize; i++){
		Person* p = &addressBook->Persons[i];
		if (strcmp(name, p->name) == 0){
			printf("[%d]\t\t%s\t\t%s\n", i,p->name,p->tel);
			printf("������ϵ�����!\n");
		}else{
			printf("���޴��ˣ�\n");
		}
	}
}

//ɾ����ϵ��
void delPerson(AddressBook* addressBook)
{
	printf("ɾ����ϵ��!\n");
	printf("������Ҫɾ����ϵ�˵ı��:");
	int id = 0;
	scanf("%d", &id);
	if (id<0 || id>addressBook->size){
		printf("������ı������\n");
		return;
	}
	if (id == addressBook->size-1){
		addressBook->size--;
		printf("ɾ���ɹ���\n");
		return;
	}else{
		int currentSize = addressBook->size;
		addressBook->Persons[id] = addressBook->Persons[currentSize-1];
		addressBook->size--;
		printf("ɾ���ɹ���\n");
		return;
	}
}
//������ϵ�˵���Ϣ
void updataPerson(AddressBook* addressBook)
{
	printf("������ϵ��!\n");
	printf("������Ҫ������ϵ�˵ı��\n");
	int id = 0;
	scanf("%d", &id);
	Person* p = &addressBook->Persons[id];
	printf("[%d]\t\t%s\t\t%s\n", id, p->name, p->tel);
	while (1){
		printf("***********************************************\n");
		printf("1.�޸�����\t2.�޸ĵ绰\t0.�޸����\n");
		printf("***********************************************\n");
		printf("����������ѡ��:");
		int choice = 0;
		scanf("%d", &choice);
        if (choice<0 || choice>2){
			printf("�밴����ʾ����!\n");
			Sleep(500);
			system("cls");
			continue;
		}else if (choice == 1){
			printf("�������µ�����:");
			scanf("%s", p->name);
		}else if (choice == 2){
			printf("�������µĵ绰:");
			scanf("%s", p->tel);
		}else{
			printf("������ϵ����Ϣ���!\n");
			printf("[%d]\t\t%s\t\t%s\n", id, p->name, p->tel);
			break;
		}
	}

}

void printPerson(AddressBook* addressBook)
{
	printf("��ӡ������ϵ�ˣ�\n");
	for (int i = 0; i < addressBook->size; i++){
		Person* p = &addressBook->Persons[i];
		printf("[%d]\t\t%s\t\t%s\n", i,p->name,p->tel);
	}
	printf("����%d����Ϣ\n", addressBook->size);
}

void clearPerson(AddressBook* addressBook)
{
	printf("���������ϵ�ˣ�\n");
	init(addressBook);
	printf("�����������ϵ��\n");
}
//����һ���ṹ��ָ��Func
typedef void(*Func)(AddressBook*);
//����һ��AddressBook���͵ı���addressBook
AddressBook addressBook;

int main()
{
	Func funcs[] = { NULL, addPerson, findPerson, delPerson, updataPerson, printPerson, clearPerson };
	init(&addressBook);
	while (1){
		int choice = menue();
		system("cls");
		if (choice<0 || choice>(sizeof(funcs)/sizeof(funcs[0]))){
			printf("������������!\n");
			continue;
		}
		if (choice == 0){
			printf("goodbye!\n");
			break;
		}
		funcs[choice](&addressBook);
	}
	system("pause");
	return 0;
}