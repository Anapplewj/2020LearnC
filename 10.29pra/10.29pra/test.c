//�ݹ�ͷǵݹ�ֱ�ʵ��strlen
////�ǵݹ�
//#include<stdio.h>
//#include<windows.h>
////��count����������'\0'�ͽ���
//int strLen(char arr[])
//{
//	int count = 0;
//	for (int i = 0; arr[i] != '\0'; i++){
//		count++;
//	}
//	return count;
//}
//
//int main()
//{
//	char arr[] = "helloworld";
//	printf("�ַ����ĳ���Ϊ��%d\n", strLen(arr));
//	system("pause");
//	return 0;
//}
//�ݹ�
//�����'\0'����˵���ַ���Ϊ�գ������
//��������ݹ飬ֱ������'\0'
//#include<stdio.h>
//#include<windows.h>
//
//int strLen(char arr[])
//{
//	if (arr[0] == '\0'){
//		return 0;
//	}
//	return 1 + strLen(arr + 1);
//}
//int main()
//{
//	char arr[] = "helloworld";
//	printf("�ַ����ĳ���Ϊ��%d\n", strLen(arr));
//	system("pause");
//	return 0;
//}



//дһ���ݹ麯��DigitSum(n)������һ���Ǹ����������������������֮��
//���磬����DigitSum(1729)����Ӧ�÷���1 + 7 + 2 + 9�����ĺ���19
//���룺1729�������19
//
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<windows.h>
//
//int DigitSum(int n)
//{
//	if (n <=9){
//		return n;
//	}
//	return n % 10 + DigitSum(n / 10);
//}
//int main()
//{
//	int n = 0;
//	printf("������һ�����֣�");
//	scanf("%d", &n);
//	printf("����֮���ǣ�%d\n", DigitSum(n));
//	system("pause");
//	return 0;
//}


////��дһ������ʵ��n��k�η���ʹ�õݹ�ʵ�֡�
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<windows.h>
//
//int power(int n,int k)
//{
//	if (k == 0){
//		return 1;
//	}
//	return n*power(n, k - 1);
//}
//int main()
//{
//	int n = 0;
//	int k = 0;
//	printf("������������ݣ�");
//	scanf("%d %d", &n, &k);
//	printf("%d��%d�η���:%d\n", n, k, power(n, k));
//	system("pause");
//	return 0;
//}

//�ݹ�ͷǵݹ�ֱ�ʵ�����n��쳲�������
//�ݹ�
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<windows.h>
//
//int Fib(int n)
//{
//	if (n == 1 || n == 2){
//		return 1;
//	}
//	return Fib(n - 1) + Fib(n - 2);
//}
//int main()
//{
//	int n = 0;
//	printf("������һ�����֣�");
//	scanf("%d", &n);
//	printf("%d��쳲��������ǣ�%d\n", n, Fib(n));
//	system("pause");
//	return 0;
//}

////�ǵݹ�
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<windows.h>
//
//int Fib(int n)
//{
//	int last1 = 1;
//	int last2 = 1;
//	int cur = 0;
//	for (int i = 3; i<=n; i++){
//		cur = last1 + last2;
//		last2 = last1;
//		last1 = cur;
//	}
//	return cur;
//}
//
//int main()
//{
//	int n = 0;
//	printf("������һ�����֣�");
//	scanf("%d", &n);
//	printf("%d��쳲��������ǣ�%d\n", n, Fib(n));
//	system("pause");
//	return 0;
//}


//��дһ������ reverse_string(char * string)���ݹ�ʵ�֣�
//ʵ�֣��������ַ����е��ַ��������С�
//Ҫ�󣺲���ʹ��C�������е��ַ�������������
//�������ַ���������
//��������������ַ������ȵ���0���ߵ���1��ֹͣ����
//���ȱ����ַ�����Ԫ��
//���һ���ַ��͵�һ���ַ�����λ��
//Ϊ�����ָ���ַ���ĩβ��ָ����ǰ�ƽ������һ������Ϊ'\0'
//�ݹ����
//�ѱ�����ַ�����Ԫ�طŻص��ַ���ĩβ
#include<stdio.h>
#include<windows.h>

int reverse_string(char *string)
{
	if (strlen(string) < 2){
		return string;
	}
	char ch = *string;
	int len = strlen(string) - 1;
	*string = *(string + len);
	*(string + len) = '\0';
	reverse_string(string + 1);
	*(string + len) = ch;
	return string;
	
}

int main()
{
	char string[] = "helloworld";
	printf("%s\n", reverse_string(string));
	system("pause");
	return 0;
}
