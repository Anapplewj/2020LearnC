int g_val = 10;//static修饰全局变量，改变了变量的作用域，其他源文件不能访问
void myPrint(){
	int a = 0;
	printf("%d", a+20);
}