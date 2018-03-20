#include <iostream>
#include <time.h>
using namespace std;
int main()
{

	//switch语句的判断条件可以接受int,byte,char,short, enum不能接受其他类型.
	char a;
	time_t sys; 
	time(&sys);        //获取系统时间
	struct tm *time1;
	time1=localtime(&sys);     //转换为系统时间
	//cin>>"请输入一个字符";
	cin>>a;
	while(true)
  {
   
	switch (a)
	{
	case '?': 
		 cout<<"输入1显示系统时间,输入2显示系统日期，输入3退出系统";
		 break;    
	case '1':
		cout<<time1->tm_hour<<":"<<time1->tm_min<<":"<<time1->tm_sec<<endl;
		break;	
	case '2':
        cout<<1900+(time1->tm_year)<<'-'<<time1->tm_mon+1<<'-'<<time1->tm_mday<<endl;
		break;
	
	//return 用于退出当前调用的函数
	//exit 用于终止当前调用的进程

	case 'e':
	    return 0;
	
	default:
		break;
  }
	cin>>a;
 }

}