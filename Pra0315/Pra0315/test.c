#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
//1.实现一个字符串求长度的函数
//首先最重要的是进行合法性校验
//然后，使用循环计算长度
size_t myStrlen(const char* str){
	if (str == NULL){
		return 0;
	}
	size_t num = 0;
/*	while (*str != '\0'){
		num++;
		str++;
	}*/
	while (str[num] != '\0'){
		num++;
	}
	return num;
}
//2.实现字符串拷贝函数，strcpy
//值得注意的是，我们要人为的保证目的地的空间足够大
//源不能为空
char* myStrcpy(char* dest, const char* res){
	if (dest==NULL||res==NULL){
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
//3.实现strcat函数，实现字符串的拼接
char* myStrcat(char* dest, const char* res){
	if (dest == NULL||res==NULL){
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
//实现字符串比较函数strcmp
int myStrcmp(const char* str1, const char* str2){
	assert(str1 != NULL&&str2 != NULL);//assert断言，如果括号中为真，那么不触发任何效果
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
//实现字符串查找子串的起始位置strstr
const char* myStrstr(const char* str1, const char* str2){
	if (str1 == NULL || str2 == NULL){
		return -1;
	}
	const char* black = str1;
	while (*black != '\0'){
		const char* red = black;
		const char* sub = str2;
		while (*red!='\0'&& *sub!='\0'&& *red == *sub){
			red++;
			sub++;
		}
		//触发第一种情况：继续往后找
		//触发第二种情况：说明找到了
		//触发第三种情况：继续往后找
		if (*sub == '\0'){
			return black;
		}
		black++;
	}
	return NULL;
}
//实现内存拷贝函数,memcpy
//类型为void*,也就意味着可以拷贝任何类型的数据
//注意：由于要拷贝不同类型的数据，那么就要保证所有类型的数据都能拷贝到
//所以需要一个字节一个字节的拷贝，所以在这里将其强转为char*类型的
//num表示的是要拷贝的字节数
void* myMemcpy(void* dest, const void* res, size_t num){
	assert(dest != NULL && res != NULL);
	char* dest1 = (char*)dest;
	const char* res1 = (char*)res;
	for (size_t i = 0; i < num; i++){
		*dest1= *res1;
		dest1++;
		res1++;
	}
	return dest;
}
//实现内存拷贝函数memmove(实现拷贝的功能)，和memcpy的不同在于，
//memmove可以支持空间重叠的情况
void* myMemmove(char* dest, const char* res, size_t num){
	assert(dest != NULL&&res != NULL);
	char* pdest = (char*)dest;
	char* pres = (char*)res;
	//如果空间重叠，则反向拷贝
	if (pres <= pdest&&pdest <= pres + num){
		for (size_t i = num; i >= 0; i--){
			*(pdest + i) = *(pres + i);
		}
		return dest;
	}
	else{
		return myMemcpy(dest, res, num);
	}
}
int main(){
	//char arr[] = "world";
	//char arr2[1024];
	//char arr3[1024] = "hello";
	//if (arr != NULL){
		//size_t len = myStrlen(arr);
		//printf("%u\n", len);
	//}
	//C中如果没有对一个字符数组初始化会怎么样？
	//printf("%s\n", myStrcpy(arr, "hei"));
	//printf("%s\n", myStrcpy(arr2, arr));
	//printf("%s\n", myStrcpy(arr2, arr));
	//printf("%s\n", myStrcat(arr3, "ttlxbb"));
	//printf("%d\n", myStrcmp(arr, arr3));
	//printf("%s\n", myStrstr("hello world", "llo"));
	/**char arr1[1024]="";
	char arr2[] = "ttlxbb";
	printf("%s\n", myMemcpy(arr1, arr2, sizeof(arr2)));
	int arr3[] = { 1, 2, 3 };
	int arr4[14];
	myMemcpy(arr4,arr3,sizeof(arr3));
	for (int i = 0; i < sizeof(arr3) / sizeof(arr3[0]); i++){
		printf("%d\n", arr4[i]);
	}**/
	char arr1[] = "ttlxbb";
	myMemmove(arr1, arr1+3, 3);
	printf("%s\n", arr1);
	printf("%d\n", sizeof(arr1));
	system("pause");
	return 0;
}