#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<time.h>
#include<windows.h>
//��ӡ��n��쳲�������
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
//��N�Ľ׳�
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
//��һ���ַ����ó��ȣ�����������ʱ����
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
//��˳���ӡһ��������ÿһλ
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
//������������������
/**void swap(int* num1, int* num2){
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}
int main(){
	int num1 = 10;
	int num2 = 20;
	printf("����֮ǰ��num1=%d,num2=%d\n", num1, num2);
	swap(&num1, &num2);
	printf("����֮��num1=%d,num2=%d\n", num1, num2);
	system("pause");
	return 0;
}
**/
//�򵥵Ĳ�������Ϸ����ϰ����ð취���Ƕ��ô��룬��һ��ܿ�ͼ�ס�ˣ��ȿ�ʮ�黹���ã�
//srand(time(0))���Ե�ǰʱ�����Ϊ�������
//rand()%100,��ʾ[0,100)֮���һ�������
/**int menue(){
	printf("===============\n");
	printf("1.��ʼһ����Ϸ\n");
	printf("0.�˳�\n");
	printf("===============\n");
	printf("����������ѡ��");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}
void game(){
	int toFind = rand() % 100 + 1;//����һ��1~100�������
	while (1){
		int choice = menue();
		if (choice == 0){
			printf("bye~~\n");
			return;
		}else if (choice == 1){
			while (1){
				printf("��������Ҫ�µ�����(��Χ��1~100֮��)��");
				int num = 0;
				scanf("%d", &num);
				if (num < toFind){
					printf("����\n");
				}else if (num>toFind){
					printf("����\n");
				}else if (num == toFind){
					printf("��ϲ�㣬�¶���!\n");
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
//��ʾ����ַ������˻�ۣ����м��ƶ�
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
//���ֲ���
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
//����n�Ľ׳�
/***int jie(int val){
	int result = 1;
	for (int i = 1; i<=val; i++){
		result *= i;
	}
	return result;
}
int main(){
	printf("�������������Ľ׳�N\n");
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
	static int i = 0;//static ���εľֲ������������ڸı��ˣ������ȫ�ֵ�
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