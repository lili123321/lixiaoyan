#include <iostream>
#include <time.h>
using namespace std;
int main()
{

	//switch�����ж��������Խ���int,byte,char,short, enum���ܽ�����������.
	char a;
	time_t sys; 
	time(&sys);        //��ȡϵͳʱ��
	struct tm *time1;
	time1=localtime(&sys);     //ת��Ϊϵͳʱ��
	//cin>>"������һ���ַ�";
	cin>>a;
	while(true)
  {
   
	switch (a)
	{
	case '?': 
		 cout<<"����1��ʾϵͳʱ��,����2��ʾϵͳ���ڣ�����3�˳�ϵͳ";
		 break;    
	case '1':
		cout<<time1->tm_hour<<":"<<time1->tm_min<<":"<<time1->tm_sec<<endl;
		break;	
	case '2':
        cout<<1900+(time1->tm_year)<<'-'<<time1->tm_mon+1<<'-'<<time1->tm_mday<<endl;
		break;
	
	//return �����˳���ǰ���õĺ���
	//exit ������ֹ��ǰ���õĽ���

	case 'e':
	    return 0;
	
	default:
		break;
  }
	cin>>a;
 }

}