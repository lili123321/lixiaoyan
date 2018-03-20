#include <iostream>
#include <string>
using namespace std;
int main()
{
	//char a[6]={"mrsoft"}字符数组  string a[6]字符串数组、 char *pcStr = "aaaaa";//这个是字符串,含有6个字符，即5个a加一个结束符'\0'
	//sizeof(a) 是 100;             strlen(a) 是实际长度
	
	/* sizeof(...)是运算符，在头文件中typedef为unsigned int，其值在编译时即计算好了，参数可以是数组、指针、类型、对象、函数等。
	它的功能是：获得保证能容纳实现所建立的最大对象的字节大小。由于在编译时计算，因此sizeof不能用来返回动态分配的内存空间的大小。
	实际上，用sizeof来返回类型以及静态分配的对象、结构或数组所占的空间，返回值跟对象、结构、数组所存储的内容没有关系。*/
	

	/*strlen(...)是函数，要在运行时才能计算。参数必须是字符型指针（char*）。当数组名作为参数传入时，实际上数组就退化成指针了。
	它的功能是：返回字符串的长度。该字符串可能是自己定义的，也可能是内存中随机的，该函数实际完成的功能是从代表该字符串的第一个地址开始遍历，直到遇到结束符NULL。返回的长度大小不包括NULL。*/
	
	
	//char a[7]={"mrsoft"};
	char a[]="mrsoft";
	int n=sizeof(a)-2;
    char b[sizeof(a)];
    for(int i=0;i<sizeof(a)-1;i++)
	 {

          b[n]=a[i];
		  n--;
	 }
	 cout<<b<<endl;
	 return 0;
}