#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<windows.h>
//定义一个联系人信息的结构体
typedef struct Person
{
	char name[1024];
	char tel[1024];
}Person;
//定义一个通讯录结构体
#define MAX_PERSON 1024
typedef struct AddressBook
{
	Person Persons[MAX_PERSON];
	//size表示已有联系人数
	int size;
}AddressBook;


int menue()
{
	printf("**************************\n");
	printf("1.新增联系人\n");
	printf("2.查找联系人\n");
	printf("3.删除联系人\n");
	printf("4.修改联系人\n");
	printf("5.查看所有联系人\n");
	printf("6.清空所有联系人\n");
	printf("0.退出\n");
	printf("**************************\n");
	printf("请输入您的选择:");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}

//初始化通讯录
void init(AddressBook* addressBook)
{
//只需要将现有联系人的多少置为0
	addressBook->size = 0;
}

//新增联系人
void addPerson(AddressBook* addressBook)
{
	printf("新增联系人!\n");
	int currentSize = addressBook->size;
	if (currentSize >= MAX_PERSON){
		printf("通讯录已满，新增失败！");
		return;
	}
	Person* p = &addressBook->Persons[currentSize];
	printf("请输入新增联系人的姓名：\n");
	scanf("%s",p->name);
	printf("请输入新增联系人的电话:\n");
	scanf("%s", p->tel);
	addressBook->size++;
	printf("新增联系人成功!\n");
}
void findPerson(AddressBook* addressBook)
{
//按照名字查找
	printf("查找联系人!\n");
	int currentSize = addressBook->size;
	printf("请输入要查找联系人的姓名:");
	char name[1024] = {0};
	scanf("%s",name);
	for (int i = 0; i < currentSize; i++){
		Person* p = &addressBook->Persons[i];
		if (strcmp(name, p->name) == 0){
			printf("[%d]\t\t%s\t\t%s\n", i,p->name,p->tel);
			printf("查找联系人完成!\n");
		}else{
			printf("查无此人！\n");
		}
	}
}

//删除联系人
void delPerson(AddressBook* addressBook)
{
	printf("删除联系人!\n");
	printf("请输入要删除联系人的编号:");
	int id = 0;
	scanf("%d", &id);
	if (id<0 || id>addressBook->size){
		printf("您输入的编号有误！\n");
		return;
	}
	if (id == addressBook->size-1){
		addressBook->size--;
		printf("删除成功！\n");
		return;
	}else{
		int currentSize = addressBook->size;
		addressBook->Persons[id] = addressBook->Persons[currentSize-1];
		addressBook->size--;
		printf("删除成功！\n");
		return;
	}
}
//更新联系人的信息
void updataPerson(AddressBook* addressBook)
{
	printf("更新联系人!\n");
	printf("请输入要更新联系人的编号\n");
	int id = 0;
	scanf("%d", &id);
	Person* p = &addressBook->Persons[id];
	printf("[%d]\t\t%s\t\t%s\n", id, p->name, p->tel);
	while (1){
		printf("***********************************************\n");
		printf("1.修改姓名\t2.修改电话\t0.修改完毕\n");
		printf("***********************************************\n");
		printf("请输入您的选择:");
		int choice = 0;
		scanf("%d", &choice);
        if (choice<0 || choice>2){
			printf("请按照提示输入!\n");
			Sleep(500);
			system("cls");
			continue;
		}else if (choice == 1){
			printf("请输入新的姓名:");
			scanf("%s", p->name);
		}else if (choice == 2){
			printf("请输入新的电话:");
			scanf("%s", p->tel);
		}else{
			printf("更新联系人信息完毕!\n");
			printf("[%d]\t\t%s\t\t%s\n", id, p->name, p->tel);
			break;
		}
	}

}

void printPerson(AddressBook* addressBook)
{
	printf("打印所有联系人！\n");
	for (int i = 0; i < addressBook->size; i++){
		Person* p = &addressBook->Persons[i];
		printf("[%d]\t\t%s\t\t%s\n", i,p->name,p->tel);
	}
	printf("共计%d条信息\n", addressBook->size);
}

void clearPerson(AddressBook* addressBook)
{
	printf("清空所有联系人！\n");
	init(addressBook);
	printf("已清空所有联系人\n");
}
//定义一个结构体指针Func
typedef void(*Func)(AddressBook*);
//定义一个AddressBook类型的变量addressBook
AddressBook addressBook;

int main()
{
	Func funcs[] = { NULL, addPerson, findPerson, delPerson, updataPerson, printPerson, clearPerson };
	init(&addressBook);
	while (1){
		int choice = menue();
		system("cls");
		if (choice<0 || choice>(sizeof(funcs)/sizeof(funcs[0]))){
			printf("您的输入有误!\n");
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