#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<windows.h>
#include<assert.h>

//�����ַ����ִ�
//�ж�str2�Ƿ�Ϊstr1���Ӵ�
//ֱ��blackstr��������
//const char* myStrstr(const char* str1, const char* str2)
//{
//	if (str1 == NULL || str2 == NULL){
//		return NULL;
//	}
//    const char* blackstr = str1;
//	while (*blackstr != '\0'){
//		const char* redstr = blackstr;
//		const char* substr = str2;
//		while(*redstr != '\0' && *substr != '\0' && *redstr == *substr){
//			redstr++;
//			substr++;
//		}
//		if (*substr == '\0'){
//			return blackstr;
//		}
//		blackstr++;
//	}
//
//	return NULL;
//}

//strcat��ʵ��
//char* myStrcat(char* dest, const char* source)
//{
//	if (dest == NULL || source == NULL){
//		return dest;
//	}
//	char* ret = dest;
//	while (*ret != '\0'){
//		ret++;
//	}
//	while (*source != '\0'){
//		*ret = *source;
//		ret++;
//		source++;
//	}
//	*ret = '\0';
//	return dest;
//}

//�ַ����ȽϺ���
//��һ���ȵڶ���С������С��0����
//������ͬ������0
//��һ���ȵڶ����󣬷��ش���0����

//int myStrcmp(const char* str1, const char* str2)
//{
//	assert(str1 != NULL&&str2 != NULL);
//	while (*str1 != '\0'&&*str2 != '\0'){
//		if (*str1 < *str2){
//			return -1;
//		}
//		else if (*str1>*str2){
//			return 1;
//		}
//		else{
//			str1++;
//			str2++;
//		}
//	}
//	//��������ѭ�����˻�û�д���return;
//	//��ô��˭�̣�˭��С
//	return *str1 - *str2;
//}

//strcp��ʵ��
//char * myStrcp(char *dest, const char* source)
//{
//	//�Ϸ��Ե�У��
//	if (dest == NULL || source == NULL){
//		return NULL;
//	}
//	//���θ��ƣ�ֱ��������\0��
//	char* ret = dest;
//	while (*source!= '\0'){
//		*ret= *source;
//		ret++;
//		source++;
//	}
//	//ע��dest���һ���ַ�Ϊ'\0'
//	*ret= '\0';
//	return dest;
//}

//strlen��ʵ��
size_t myStrlen(const char* str)
{
	if (str == NULL){
		return 0;
	}
	size_t len = 0;
	while (str[len] != '\0'){
		len++;
	}
	return len;
}

int main()
{
	/*char str1[1024] = "abcde";
	char str2[1024] = "";
	printf("%s\n", myStrcp(str2, str1));*/
	char str[] = "hello";
	printf("%d\n", myStrlen(str));
	/*char name1[1024] = "hello";
	printf("%s\n", myStrcat(name1, " zhangsan"));*/
	//printf("%d\n", myStrcmp("zhangsan", "zhangcan"));
	/*char str[] = "hello world";
	printf("%s\n", myStrstr(str, "llo"));*/
	system("pause");
	return 0;
}