//����������ʱ������������������������
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<windows.h>
//
//int main()
//{
//	int num1 = 0;
//	int num2 = 0;
//	printf("�������������֣�");
//	scanf("%d %d", &num1, &num2);
//	num1 = num1 + num2;
//	num2 = num1 - num2;
//	num1 = num1 - num2;
//	printf("������������Ϊ��%d %d\n",num1,num2);
//	system("pause");
//	return 0;
//}

//ͳ�ƶ�������1�ĸ���
//дһ���������ز����������� 1 �ĸ�����
//���磺 15    0000 1111    4 �� 1
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<windows.h>
//int binary(int num)
//{
//	int count = 0;
//	for (int i = 0; i < 32; i++){
//		if (num &(1 << i)){
//			count++;
//		}
//	}
//	return count;
//}
//int main()
//{
//	int num = 0;
//	printf("������һ�����֣�");
//	scanf("%d", &num);
//	printf("ת��Ϊ��������1�ĸ���Ϊ��%d\n", binary(num));
//	system("pause");
//	return 0;
//}

//��ӡ���������Ƶ�����λ��ż��λ

//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<windows.h>
////��ӡż��λ
//void oddnum(int num)
//{
//	for (int i = 30; i >=0; i-=2){
//			if ((num &(1 << i))){
//				printf("1 ");
//			}else{
//				printf("0 ");
//			}
//	}
//	
//}
////��ӡ����λ
//void evennum(int num)
//{
//	for (int i = 31; i >=0; i -= 2){
//		if ((num &(1 << i))){
//			printf("1 ");
//		}
//		else{
//			printf("0 ");
//		}
//	}
//
//}
//
//int main()
//{
//	int num = 0;
//	printf("������һ�����֣�");
//	scanf("%x", &num);
//	printf("�������ż��λΪ��");
//	oddnum(num);
//	printf("\n�����������λΪ��");
//	evennum(num);
//	printf("\n");
//	system("pause");
//	return 0;
//}


//���ʵ�֣�����int��32λ������m��n�Ķ����Ʊ���У��ж��ٸ�λ(bit)��ͬ��
//�������� :
//1999 2299
//������� : 7
//����˼�� ���������^����ͬΪ0����ͬΪ1.
//���֮���ж��ٸ�1���ж���λ��ͬ
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<windows.h>
//
//int bitEqual(int m, int n)
//{
//	int num = m^n;
//	int count = 0;
//	for (int i = 0; i < 32; i++){
//		if (num & (1 << i)){
//			count++;
//		}
//	}
//	return count;
//}
//int main()
//{
//	int m = 0;
//	int n = 0;
//	printf("�������������֣�");
//	scanf("%d %d", &m, &n);
//	printf("��������ת��Ϊ�����ƺ��� %d λ��ͬ\n", bitEqual(m, n));
//	system("pause");
//	return 0;
//}

//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<windows.h>
//
//int main()
//{
//	system("pause");
//	return 0;
//}

