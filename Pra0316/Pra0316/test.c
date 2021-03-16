#include <stdio.h>
#include<windows.h>
#include<assert.h>
//1.实现字符串求长度函数
size_t myStrlen(const char* str){
	if (str == NULL){
		return 0;
	}
	size_t num = 0;
	while (*str != '\0'){
		str++;
		num++;
	}
	return num;
}
//2.实现字符串拷贝函数strcpy
char* myStrcpy(char* dest, const char* res){
	if (dest == NULL || res == NULL){
		return NULL;
	}
	char* ret = dest;
	while (*res != '\0'){
		*ret = *res;
		ret++;
		res++;
	}
	*ret = '\0';
	return dest;
}
//3.实现字符串比较函数
int myStrcmp(const char* str1, const char* str2){
	assert(str1 != NULL && str2 != NULL);
	while (str1 != '\0'&&str2 != '\0'){
		if (*str1 > *str2){
			return 1;
		}else if (*str1 < *str2){
			return -1;
		}else{
			str1++;
			str2++;
		}
	}
	return *str1 - *str2;
}
//4.实现字符串拼接函数
char* myStrcat(char* dest, const char* res){
	if (dest == NULL || res == NULL){
		return dest;
	}
	char* ret = dest;
	while (*ret != '\0'){
		ret++;
	}
	while (*res != '\0'){
		*ret = *res;
		ret++;
		res++;
	}
	*ret = '\0';
	return dest;
}
//5.实现字符串查找子串函数
char* myStrstr(const char* str1, const char* str2){
	if (str1 == NULL || str2 == NULL){
		return NULL;
	}
	char* black = str1;
	while (*black != '\0'){
		char* red = black;
		char* sub = str2;
		while (*red != '\0'&& *sub != '\0'&& *red == *sub){
			red++;
			sub++;
		}
		if (*sub == '\0'){
			return black;
		}
		black++;
	}
	return NULL;
}
//6.实现内存拷贝函数,按照字节来拷贝，所以要将其强转为字符类型
void* myMemcpy(void* dest, const void* res, size_t num){
	if (dest == NULL || res == NULL){
		return NULL;
	}
	char* pdest = (char*)dest;
	char* pres = (char*)res;
	for (int i = 0; i < num; i++){
		*(pdest + i) = *(pres + i);
	}
	return dest;
}
//7.实现内存拷贝函数，memmove,可以支持内存空间重叠
void* myMemmove(void* dest, const void* res, size_t num){
	if (dest == NULL || res == NULL){
		return NULL;
	}
	char* pdest = (char*)dest;
	char* pres = (char*)res;
	if (pres <= pdest && pdest <= pres + num){
		for (int i = num - 1; i >= 0; i--){
			*(pdest) = *(pres);
		}
		return dest;
	}
	return myMemcpy(dest, res, num);
}
int main(){
	printf("%u\n", myStrlen("heihie"));
	char arr1[1024];
	printf("%s\n", myStrcpy(arr1, "ttlxbb"));
	printf("%d\n", myStrcmp(arr1, "ttbb"));
	printf("%s\n", myStrcat(arr1, ",I love you"));
	printf("%s\n", myStrstr(arr1, "love"));
	int arr2[1024] = { 0 };
	int arr3[] = { 1, 2, 3 };
	myMemmove(arr2, arr3, sizeof(arr3));
	for (int i = 0; i < sizeof(arr3)/sizeof(arr3[0]); i++){
		printf("%d\n", arr2[i]);
	}
	char arr4[] ="My love ttlxbb";
	myMemmove(arr4, arr4 + 3, 12);
	printf("%s\n", arr4);
	system("pause");
	return 0;
}