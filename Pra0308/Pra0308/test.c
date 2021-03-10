#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<time.h>
#include<windows.h>
//打印第n个斐波那契数
int fib(int n){
	if (n <= 2){
		return 1;
	}
	return fib(n - 1) + fib(n - 2);
}
int main(){
	printf("%d\n", fib(4));
	system("pause");
	return 0;
}
//求N的阶乘
/**int jie(int val){
	if (val == 1){
		return 1;
	}
	return val*jie(val-1);
}
int main(){
	printf("%d\n", jie(4));
	system("pause");
	return 0;
}**/
//求一个字符串得长度，不允许创建临时变量
/**int length(const char* str){
	if (*str == '\0'){
		return 0;
	}else{
		return 1 + length(str + 1);
	}
}
int main(){
	char s[] = "Anapple";
	printf("%d\n", length(s));
	system("pause");
	return 0;
}**/
//按顺序打印一个整数的每一位
/**void myPrint2(int num){
	if (num > 9){
		myPrint2(num/10);
	}
	printf("%d ", num % 10);
}
int main(){
	myPrint2(123);
	printf("\n");
	system("pause");
	return 0;
}**/
//交换两个变量的内容
/**void swap(int* num1, int* num2){
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}
int main(){
	int num1 = 10;
	int num2 = 20;
	printf("交换之前，num1=%d,num2=%d\n", num1, num2);
	swap(&num1, &num2);
	printf("交换之后，num1=%d,num2=%d\n", num1, num2);
	system("pause");
	return 0;
}
**/
//简单的猜数字游戏（复习的最好办法就是多敲代码，敲一遍很快就记住了，比看十遍还管用）
//srand(time(0))，以当前时间戳作为随机种子
//rand()%100,表示[0,100)之间的一个随机数
/**int menue(){
	printf("===============\n");
	printf("1.开始一局游戏\n");
	printf("0.退出\n");
	printf("===============\n");
	printf("请输入您的选择：");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}
void game(){
	int toFind = rand() % 100 + 1;//产生一个1~100的随机数
	while (1){
		int choice = menue();
		if (choice == 0){
			printf("bye~~\n");
			return;
		}else if (choice == 1){
			while (1){
				printf("请输入您要猜的数字(范围在1~100之间)：");
				int num = 0;
				scanf("%d", &num);
				if (num < toFind){
					printf("低了\n");
				}else if (num>toFind){
					printf("高了\n");
				}else if (num == toFind){
					printf("恭喜你，猜对了!\n");
					return;
				}
			}
		}
	}

}
int main(){
	srand(time(0));
	game();
	system("pause");
	return 0;
}
**/
//演示多个字符从两端汇聚，向中间移动
/**int main(){
	char arr1[] = "##########";
	char arr2[] = "I love ttl";
	int left = 0;
	int right = strlen(arr1)-1;
	while (left <= right){
		Sleep(1000);
		system("cls");
		arr1[left] = arr2[left];
		arr1[right] = arr2[right];
		printf("%s", arr1);
		left++;
		right--;
	}
	system("pause");
	return 0;
}
**/
//二分查找
/**int mySearch(int arr[], int len,int val){
	int left = 0;
	int right = len - 1;
	while (left <= right){
		int mid = (left + right) / 2;
		if (val < arr[mid]){
			right = mid - 1;
		}else if (val>arr[mid]){
			left = mid + 1;
		}else if (val == arr[mid]){
			return mid;
		}
	}
	return -1;
}
int main(){
	int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
	int result=mySearch(arr,sizeof(arr)/sizeof(arr[0]), 2);
	printf("%d\n", result);
	system("pause");
	return 0;
}
**/
//计算n的阶乘
/***int jie(int val){
	int result = 1;
	for (int i = 1; i<=val; i++){
		result *= i;
	}
	return result;
}
int main(){
	printf("请输入您想计算的阶乘N\n");
	int n = 0;
	scanf("%d", &n);
	printf("%d", jie(n));
	system("pause");
	return 0;
}
***/
/*****  extern int g_val;
void test()
{
	static int i = 0;//static 修饰的局部变量生命周期改变了，变成了全局的
	i++;
	printf("%d ", i);
}
int main()
{
	int i = 0;
	for (i = 0; i<10; i++)
	{
		test();
	}
	printf("%d\n", g_val);
	myPrint();
	system("pause");
	return 0;
}
*****/