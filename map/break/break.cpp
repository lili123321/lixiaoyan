#include<iostream>
using namespace  std;
int main()
{  
	//�Ƚ�break,continue,break���÷�   ��j++,++j������
	int  j=1;
	while (j!=6)
	{
	     for (int  i=0;i<=10;i++)
	    {
           if (i==6)
		   {
			  cout<<"i="<<"overbreak"<<endl;
			  break;
           }
		   else
		   {
			  cout<<"i="<<i<<endl;
		   }
          // cout<<"���ѭ��"<<endl;
	    }
		cout<<"j="<<++j<<endl;

	}

	advice();

	
}

void advice()
{
	int m=2;
	if (m==2)
	 return ;

	cout<<m<<endl;
}