#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<windows.h>
#include<assert.h>

//查找字符串字串
//判断str2是否为str1的子串
//直到blackstr遍历结束
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

//strcat的实现
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

//字符串比较函数
//第一个比第二个小，返回小于0的数
//两个相同，返回0
//第一个比第二个大，返回大于0的数

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
//	//如果上面的循环完了还没有触发return;
//	//那么看谁短，谁就小
//	return *str1 - *str2;
//}

//strcp的实现
//char * myStrcp(char *dest, const char* source)
//{
//	//合法性的校验
//	if (dest == NULL || source == NULL){
//		return NULL;
//	}
//	//依次复制，直到遇到‘\0’
//	char* ret = dest;
//	while (*source!= '\0'){
//		*ret= *source;
//		ret++;
//		source++;
//	}
//	//注意dest最后一个字符为'\0'
//	*ret= '\0';
//	return dest;
//}

//strlen的实现
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