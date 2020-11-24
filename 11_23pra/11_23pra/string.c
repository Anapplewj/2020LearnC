//ʵ���ַ���strstr
//#include<stdio.h>
//#include<windows.h>
//
//char* myStrstr(const char* dest, const char* src)
//{
//	if (dest == NULL || src == NULL){
//		return NULL;
//	}
//	const char* black= dest;
//	while (*black != '\0'){
//		const char* red = black;
//		const char* psrc = src;
//		while (*red == *psrc && *red != '\0' && *psrc != '\0'){
//			red++;
//			psrc++;
//		}
//		if (*psrc == '\0'){
//			return black;
//		}
//		black++;
//	}
//	return NULL;
//}
//int main()
//{
//	char dest[] = "helloworld";
//	printf("%s\n", myStrstr(dest, "ow"));
//	system("pause");
//	return 0;
//}

//ʵ���ַ���strcat
//#include<stdio.h>
//#include<windows.h>
//
//char* myStrcat(char* str1, const char* str2)
//{
//	if (str1 == NULL || str2 == NULL){
//		return str1;
//	}
//	char* pstr1 = str1;
//	//!!!!
//	while (*pstr1 != '\0'){
//		pstr1++;
//	}
//	while (*str2 != '\0'){
//		*pstr1 = *str2;
//		pstr1++;
//		str2++;
//	}
//	*pstr1 = '\0';
//	return str1;
//}
//int main()
//{
//	char str1[50] = "hello";
//	//const char str2[] = "world";
//	printf("%s\n", myStrcat(str1,"world"));
//	system("pause");
//	return 0;
//}

//ʵ���ַ���strcmp
//����Ϸ���
//��str1��str2��û�б����������ͱȽ�
//str1<str2����-1   str1>str2����1  �����ȼ����Ƚ���һ��
//����str1��str2��һ����������(=='\0')
//�ͷ���str1-str2(����>0��˵��str1����δ������str2��������,str1>str2)
//����<0��˵��str1����������str2����δ������str1<str2
//���ص����㣬˵��str1��str2������������str1=str2
//#include<stdio.h>
//#include<windows.h>
//#include<assert.h>
//
//int myStrcmp(const char*str1, const char* str2)
//{
//	assert(str1!= NULL&&str2!=NULL);
//	while (*str1 != '\0'&&*str2 != '\0'){
//		if (*str1<*str2){
//			return -1;
//		}else if (*str1 > *str2){
//			return 1;
//		}else{
//			str1++;
//			str2++;
//		}
//	}
//	return *str1 - *str2;
//}
//int main()
//{
//	const char str1[] = "helloapple";
//	const char str2[] = "helloworld";
//	printf("%d\n", myStrcmp(str1, str2));
//	system("pause");
//	return 0;
//}

//ʵ���ַ���strcpy
//��Ҫע����ǣ�Ҫ��֤���Ƶ�Ŀ�ĵصĿռ��㹻
//#include<stdio.h>
//#include<windows.h>
//
//char* myStrcpy(char* dest, const char* src)
//{
//	if (dest == NULL || src == NULL){
//		return NULL;
//	}
//	char* pdest = dest;
//	const char* psrc = src;
//	while (*psrc != '\0'){
//		*pdest = *psrc;
//		pdest++;
//		psrc++;
//	}
//	*pdest = '\0';
//	return dest;
//}
//int main()
//{
//	char dest[1024] = "hello";
//	char src[] = "heihei";
//	printf("%s\n", myStrcpy(dest, src));
//	system("pause");
//	return 0;
//}

//ʵ���ַ���strlen
//#include<stdio.h>
//#include<windows.h>
//
//size_t myStrlen(const char* str)
//{
//	if (str == NULL){
//		return 0;
//	}
//	size_t len = 0;
//	while (str[len]!= '\0'){
//		len++;
//	}
//	return len;
//}
//int main()
//{
//	char str[] = "hello world";
//	printf("%d\n",myStrlen(str));
//	system("pause");
//	return 0;
//}

//ʵ��memCpy
//��Ҫһ���ֽ�һ���ֽڿ�����������Ҫǿ������ת��Ϊchar*
//#include<stdio.h>
//#include<windows.h>
//#include<assert.h>
//
//void* myMemcpy(void* dest, const void* src,size_t num)
//{
//	assert(dest!= NULL&&src!=NULL);
//	char* pdest = (char*)dest;
//	const char* psrc = (char*)src;
//	for (size_t i = 0; i < num; i++){
//		*(pdest+i) = *(psrc+i);
//	}
//	return dest;
//}
//int main()
//{
//	int dest1[4] = {1,0,2,4};
//	const int src1[4] = { 6, 6, 6, 6 };
//	char dest2[1024] = "hei";
//	const char src2[1024] = "helloworld";
//	for (int i = 0; i < (sizeof(dest1) / sizeof(dest1[0])); i++){
//		printf("%d", dest1[i]);
//	}
//	printf("\n%s\n", myMemcpy(dest2, src2, sizeof(src2)));
//	system("pause");
//	return 0;
//}

//ʵ��memmove
#include<stdio.h>
#include<windows.h>
#include<assert.h>

void* myMemcpy(void* dest, const void* src,size_t num)
{
	assert(dest!= NULL&&src!=NULL);
	char* pdest = (char*)dest;
	const char* psrc = (char*)src;
	for (size_t i = 0; i < num; i++){
		*(pdest+i) = *(psrc+i);
	}
	return dest;
}

void* myMemmove(void* dest, const void* src, size_t num)
{
	assert(dest != NULL&&src != NULL);
	char* pdest = (char*)dest;
	const char* psrc = (char*)src;
	if (pdest>=psrc&&pdest<=psrc){
		for (size_t i =num-1; i >= 0; i--){
			*(pdest + i) = *(psrc + i);
		}
		return dest;
	}
	return myMemcpy(dest, src, num);
}
int main()
{
	char str[] = "hello world ni hao shi jie..";
	printf("%s\n", myMemmove(str+11,str+12,18));
	system("pause");
	return 0;
}

