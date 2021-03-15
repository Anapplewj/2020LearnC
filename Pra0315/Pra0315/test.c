#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
//1.ʵ��һ���ַ����󳤶ȵĺ���
//��������Ҫ���ǽ��кϷ���У��
//Ȼ��ʹ��ѭ�����㳤��
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
//2.ʵ���ַ�������������strcpy
//ֵ��ע����ǣ�����Ҫ��Ϊ�ı�֤Ŀ�ĵصĿռ��㹻��
//Դ����Ϊ��
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
//3.ʵ��strcat������ʵ���ַ�����ƴ��
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
//ʵ���ַ����ȽϺ���strcmp
int myStrcmp(const char* str1, const char* str2){
	assert(str1 != NULL&&str2 != NULL);//assert���ԣ����������Ϊ�棬��ô�������κ�Ч��
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
//ʵ���ַ��������Ӵ�����ʼλ��strstr
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
		//������һ�����������������
		//�����ڶ��������˵���ҵ���
		//�������������������������
		if (*sub == '\0'){
			return black;
		}
		black++;
	}
	return NULL;
}
//ʵ���ڴ濽������,memcpy
//����Ϊvoid*,Ҳ����ζ�ſ��Կ����κ����͵�����
//ע�⣺����Ҫ������ͬ���͵����ݣ���ô��Ҫ��֤�������͵����ݶ��ܿ�����
//������Ҫһ���ֽ�һ���ֽڵĿ��������������ｫ��ǿתΪchar*���͵�
//num��ʾ����Ҫ�������ֽ���
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
//ʵ���ڴ濽������memmove(ʵ�ֿ����Ĺ���)����memcpy�Ĳ�ͬ���ڣ�
//memmove����֧�ֿռ��ص������
void* myMemmove(char* dest, const char* res, size_t num){
	assert(dest != NULL&&res != NULL);
	char* pdest = (char*)dest;
	char* pres = (char*)res;
	//����ռ��ص������򿽱�
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
	//C�����û�ж�һ���ַ������ʼ������ô����
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