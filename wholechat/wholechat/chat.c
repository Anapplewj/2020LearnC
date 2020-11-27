/*
实现一个通讯录；
通讯录可以用来存储1000个人的信息，每个人的信息包括：姓名、性别、年龄、电话、住址
提供方法：
添加联系人信息
删除指定联系人信息
查找指定联系人信息
修改指定联系人信息
显示所有联系人信息
清空所有联系人
以名字排序所有联系人*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<windows.h>
#include<string.h>
#include<stdlib.h>
#define MAX_PERSON 1000
//定义一个联系人结构体
typedef struct Person
{
	char name[1024];
	char sex[1024];
	int age;
	char tel[1024];
	char address[1024];
}Person;

//定义一个通讯录结构体
typedef struct AddressBook
{
	Person Persons[MAX_PERSON];
	//size表示通讯录的已有联系人数
	int size;
}AddressBook;

int menue()
{
	printf("**************************\n");
	printf("1.添加联系人\n");
	printf("2.查找联系人\n");
	printf("3.删除联系人\n");
	printf("4.修改联系人\n");
	printf("5.查看所有联系人\n");
	printf("6.清空所有联系人\n");
	printf("7.按名字排列联系人\n");
	printf("0.退出\n");
	printf("**************************\n");
	printf("请输入您的选择:");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}
//添加联系人
//如果通讯录满了就添加失败
void addPerson(AddressBook* addressBook)
{
	printf("添加联系人\n");
	int currentSize = addressBook->size;
	if (currentSize >= 1000){
		printf("通讯录已满，添加失败！\n");
		return;
	}
	Person* p = &addressBook->Persons[currentSize];
	printf("请输入新增联系人的姓名：\n");
	scanf("%s", p->name);
	printf("请输入增联系人的性别:\n");
	scanf("%s", p->sex);
	printf("请输入新增联系人的年龄:\n");
	scanf("%d", &p->age);
	printf("请输入新增联系人的电话:\n");
	scanf("%s", p->tel);
	printf("请输入新增联系人的地址:\n");
	scanf("%s", p->address);
	addressBook->size++;
	system("cls");
	printf("添加联系人成功!\n");
}
//查找联系人
//按照姓名查找
void findPerson(AddressBook* addressBook)
{
	printf("查找联系人!\n");
	printf("请输入要查找联系人的姓名:");
	char name[1024] = "";
	scanf("%s", name);
	for (int i = 0; i <addressBook->size; i++){
		Person* p = &addressBook->Persons[i];
		if (strcmp(p->name,name)==0){
			printf("编号\t\t姓名\t\t性别\t\t年龄\t\t电话\t\t\t住址\n");
			printf("[%d]\t\t%s\t\t%s\t\t%d\t\t%s\t\t\t%s\n", i, p->name, p->sex, p->age, p->tel, p->address);
			printf("查找成功!\n");
			return;
		}
	}
	printf("查无此人!\n");
}
//删除联系人
//按照编号删除
void delPerson(AddressBook* addressBook)
{
	printf("删除联系人!\n");
	printf("请输入要删除联系人的编号:");
	int id = 0;
	scanf("%d", &id);
	int currentSize = addressBook->size;
	if (id<0 || id>currentSize){
		printf("删除失败，无此编号联系人!\n");
		return;
	}
	if (id == currentSize){
		addressBook->size--;
	}else{
		addressBook->Persons[id] = addressBook->Persons[currentSize];
		addressBook->size--;
	}
	printf("删除联系人成功!\n");
}
//更新联系人的信息
void updataPerson(AddressBook* addressBook)
{
	printf("更新联系人的信息!\n");
	printf("请输入要更新联系人的编号:");
	int id = 0;
	scanf("%d", &id);
	for (int i = 0; i < addressBook->size; i++){
		Person* p = &addressBook->Persons[i];
		if (i == id){
			while (1){
				system("cls");
				printf("编号\t\t姓名\t\t性别\t\t年龄\t\t电话\t\t\t住址\n");
				printf("[%d]\t\t%s\t\t%s\t\t%d\t\t%s\t\t\t%s\n", i, p->name, p->sex, p->age, p->tel, p->address);
				printf("*****************\n");
				printf("1.修改姓名\n");
				printf("2.修改性别\n");
				printf("3.修改年龄\n");
				printf("4.修改电话\n");
				printf("5.修改地址\n");
				printf("0.修改完毕\n");
				printf("*****************\n");
				printf("请输入您的选择:");
				int choice = 0;
				scanf("%d", &choice);
				if (choice == 1){
					printf("请输入新的姓名:");
					scanf("%s", p->name);
				}else if (choice==2){
					printf("请输入新的性别:");
					scanf("%s", p->sex);
				}else if (choice == 3){
					printf("请输入新的年龄:");
					scanf("%d", &p->age);
				}else if (choice == 4){
					printf("请输入新的电话:");
					scanf("%s", p->tel);
				}
				else if (choice == 5){
					printf("请输入新的地址:");
					scanf("%s", p->address);
				}else if (choice == 0){
					printf("编号\t\t姓名\t\t性别\t\t年龄\t\t电话\t\t\t住址\n");
					printf("[%d]\t\t%s\t\t%s\t\t%d\t\t%s\t\t\t%s\n", i, p->name, p->sex, p->age, p->tel, p->address);
					printf("更新成功!\n");
					return;
				}
				else{
					printf("输入有误!\n");
					continue;
				}
			}
		}
	}
}
//查看所有联系人
void printPerson(AddressBook* addressBook)
{
	printf("查看所有联系人!\n");
	printf("编号\t\t姓名\t\t性别\t\t年龄\t\t电话\t\t\t住址\n");
	for (int i = 0; i < addressBook->size; i++){
		Person* p = &addressBook->Persons[i];
		printf("[%d]\t\t%s\t\t%s\t\t%d\t\t%s\t\t\t%s\n", i, p->name, p->sex, p->age, p->tel, p->address);
	}
	printf("已显示所有联系人!\n");
}
//初始化通讯录
void init(AddressBook* addressBook)
{
	addressBook->size = 0;
}
//清空所有联系人
void clearPerson(AddressBook* addressBook)
{
	printf("清空所有联系人!\n");
	init(addressBook);
	printf("已清空所有联系人!\n");
}

void sortPerson(AddressBook* addressBook)
{
	printf("按照名字顺序排列联系人!\n");
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
	printf("排序成功!\n");
}
//定义一个结构体指针，参数类型为AddressBook*
//不懂
typedef void(*Func)(AddressBook*);
AddressBook addressBook;
/*
添加联系人信息
删除指定联系人信息
查找指定联系人信息
修改指定联系人信息
显示所有联系人信息
清空所有联系人
以名字排序所有联系人*/
int main()
{
	//定义一个函数指针数组
	Func funcs[] = { NULL, addPerson, findPerson, delPerson, updataPerson, printPerson, clearPerson,sortPerson };//
	init(&addressBook);
	while (1){
		int choice = menue();
		system("cls");
		//不懂
		if (choice<0 || choice>(sizeof(funcs) / sizeof(funcs[0]))){
			printf("请按照提示输入!\n");
			continue;
		}
		if (choice == 0){
			printf("退出成功!\n");
			break;
		}
		//不懂
		funcs[choice](&addressBook);
	}
	system("pause");
	return 0;
}
