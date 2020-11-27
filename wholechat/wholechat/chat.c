/*
ʵ��һ��ͨѶ¼��
ͨѶ¼���������洢1000���˵���Ϣ��ÿ���˵���Ϣ�������������Ա����䡢�绰��סַ
�ṩ������
�����ϵ����Ϣ
ɾ��ָ����ϵ����Ϣ
����ָ����ϵ����Ϣ
�޸�ָ����ϵ����Ϣ
��ʾ������ϵ����Ϣ
���������ϵ��
����������������ϵ��*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<windows.h>
#include<string.h>
#include<stdlib.h>
#define MAX_PERSON 1000
//����һ����ϵ�˽ṹ��
typedef struct Person
{
	char name[1024];
	char sex[1024];
	int age;
	char tel[1024];
	char address[1024];
}Person;

//����һ��ͨѶ¼�ṹ��
typedef struct AddressBook
{
	Person Persons[MAX_PERSON];
	//size��ʾͨѶ¼��������ϵ����
	int size;
}AddressBook;

int menue()
{
	printf("**************************\n");
	printf("1.�����ϵ��\n");
	printf("2.������ϵ��\n");
	printf("3.ɾ����ϵ��\n");
	printf("4.�޸���ϵ��\n");
	printf("5.�鿴������ϵ��\n");
	printf("6.���������ϵ��\n");
	printf("7.������������ϵ��\n");
	printf("0.�˳�\n");
	printf("**************************\n");
	printf("����������ѡ��:");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}
//�����ϵ��
//���ͨѶ¼���˾����ʧ��
void addPerson(AddressBook* addressBook)
{
	printf("�����ϵ��\n");
	int currentSize = addressBook->size;
	if (currentSize >= 1000){
		printf("ͨѶ¼���������ʧ�ܣ�\n");
		return;
	}
	Person* p = &addressBook->Persons[currentSize];
	printf("������������ϵ�˵�������\n");
	scanf("%s", p->name);
	printf("����������ϵ�˵��Ա�:\n");
	scanf("%s", p->sex);
	printf("������������ϵ�˵�����:\n");
	scanf("%d", &p->age);
	printf("������������ϵ�˵ĵ绰:\n");
	scanf("%s", p->tel);
	printf("������������ϵ�˵ĵ�ַ:\n");
	scanf("%s", p->address);
	addressBook->size++;
	system("cls");
	printf("�����ϵ�˳ɹ�!\n");
}
//������ϵ��
//������������
void findPerson(AddressBook* addressBook)
{
	printf("������ϵ��!\n");
	printf("������Ҫ������ϵ�˵�����:");
	char name[1024] = "";
	scanf("%s", name);
	for (int i = 0; i <addressBook->size; i++){
		Person* p = &addressBook->Persons[i];
		if (strcmp(p->name,name)==0){
			printf("���\t\t����\t\t�Ա�\t\t����\t\t�绰\t\t\tסַ\n");
			printf("[%d]\t\t%s\t\t%s\t\t%d\t\t%s\t\t\t%s\n", i, p->name, p->sex, p->age, p->tel, p->address);
			printf("���ҳɹ�!\n");
			return;
		}
	}
	printf("���޴���!\n");
}
//ɾ����ϵ��
//���ձ��ɾ��
void delPerson(AddressBook* addressBook)
{
	printf("ɾ����ϵ��!\n");
	printf("������Ҫɾ����ϵ�˵ı��:");
	int id = 0;
	scanf("%d", &id);
	int currentSize = addressBook->size;
	if (id<0 || id>currentSize){
		printf("ɾ��ʧ�ܣ��޴˱����ϵ��!\n");
		return;
	}
	if (id == currentSize){
		addressBook->size--;
	}else{
		addressBook->Persons[id] = addressBook->Persons[currentSize];
		addressBook->size--;
	}
	printf("ɾ����ϵ�˳ɹ�!\n");
}
//������ϵ�˵���Ϣ
void updataPerson(AddressBook* addressBook)
{
	printf("������ϵ�˵���Ϣ!\n");
	printf("������Ҫ������ϵ�˵ı��:");
	int id = 0;
	scanf("%d", &id);
	for (int i = 0; i < addressBook->size; i++){
		Person* p = &addressBook->Persons[i];
		if (i == id){
			while (1){
				system("cls");
				printf("���\t\t����\t\t�Ա�\t\t����\t\t�绰\t\t\tסַ\n");
				printf("[%d]\t\t%s\t\t%s\t\t%d\t\t%s\t\t\t%s\n", i, p->name, p->sex, p->age, p->tel, p->address);
				printf("*****************\n");
				printf("1.�޸�����\n");
				printf("2.�޸��Ա�\n");
				printf("3.�޸�����\n");
				printf("4.�޸ĵ绰\n");
				printf("5.�޸ĵ�ַ\n");
				printf("0.�޸����\n");
				printf("*****************\n");
				printf("����������ѡ��:");
				int choice = 0;
				scanf("%d", &choice);
				if (choice == 1){
					printf("�������µ�����:");
					scanf("%s", p->name);
				}else if (choice==2){
					printf("�������µ��Ա�:");
					scanf("%s", p->sex);
				}else if (choice == 3){
					printf("�������µ�����:");
					scanf("%d", &p->age);
				}else if (choice == 4){
					printf("�������µĵ绰:");
					scanf("%s", p->tel);
				}
				else if (choice == 5){
					printf("�������µĵ�ַ:");
					scanf("%s", p->address);
				}else if (choice == 0){
					printf("���\t\t����\t\t�Ա�\t\t����\t\t�绰\t\t\tסַ\n");
					printf("[%d]\t\t%s\t\t%s\t\t%d\t\t%s\t\t\t%s\n", i, p->name, p->sex, p->age, p->tel, p->address);
					printf("���³ɹ�!\n");
					return;
				}
				else{
					printf("��������!\n");
					continue;
				}
			}
		}
	}
}
//�鿴������ϵ��
void printPerson(AddressBook* addressBook)
{
	printf("�鿴������ϵ��!\n");
	printf("���\t\t����\t\t�Ա�\t\t����\t\t�绰\t\t\tסַ\n");
	for (int i = 0; i < addressBook->size; i++){
		Person* p = &addressBook->Persons[i];
		printf("[%d]\t\t%s\t\t%s\t\t%d\t\t%s\t\t\t%s\n", i, p->name, p->sex, p->age, p->tel, p->address);
	}
	printf("����ʾ������ϵ��!\n");
}
//��ʼ��ͨѶ¼
void init(AddressBook* addressBook)
{
	addressBook->size = 0;
}
//���������ϵ��
void clearPerson(AddressBook* addressBook)
{
	printf("���������ϵ��!\n");
	init(addressBook);
	printf("�����������ϵ��!\n");
}

void sortPerson(AddressBook* addressBook)
{
	printf("��������˳��������ϵ��!\n");
	Person* p = addressBook->Persons;
	Person temp;
	for (int bound = 0; bound <addressBook->size; bound++){
		for (int cur = addressBook->size - 1; cur >bound; cur--){
			if (strcmp(p[cur].name, p[cur - 1].name) < 0){
				temp = p[cur];
				p[cur] =p[cur - 1];
				p[cur - 1] = temp;
			}
		}
	}
	printPerson(addressBook);
	printf("����ɹ�!\n");
}
//����һ���ṹ��ָ�룬��������ΪAddressBook*
//����
typedef void(*Func)(AddressBook*);
AddressBook addressBook;
/*
�����ϵ����Ϣ
ɾ��ָ����ϵ����Ϣ
����ָ����ϵ����Ϣ
�޸�ָ����ϵ����Ϣ
��ʾ������ϵ����Ϣ
���������ϵ��
����������������ϵ��*/
int main()
{
	//����һ������ָ������
	Func funcs[] = { NULL, addPerson, findPerson, delPerson, updataPerson, printPerson, clearPerson,sortPerson };//
	init(&addressBook);
	while (1){
		int choice = menue();
		system("cls");
		//����
		if (choice<0 || choice>(sizeof(funcs) / sizeof(funcs[0]))){
			printf("�밴����ʾ����!\n");
			continue;
		}
		if (choice == 0){
			printf("�˳��ɹ�!\n");
			break;
		}
		//����
		funcs[choice](&addressBook);
	}
	system("pause");
	return 0;
}
