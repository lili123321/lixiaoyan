#include<iostream>
using namespace  std;
int main()
{  
	//比较break,continue,break的用法   和j++,++j的区别
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
          // cout<<"里层循环"<<endl;
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