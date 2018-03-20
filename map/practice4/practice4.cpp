#include <iostream>
int main()
{
	int a[10]={4,6,3,9,7,1,10,8,4,5};
	//√∞≈›≈≈–Ú∑®
	for (int i=0;i<8;i++)
	 for(int j=0;j<8-i;j++)
	{
       if (a[j]>a[j+1])
       {
         int n=a[j];
		 a[j]=a[j+1];
		 a[j+1]=n;


       }
	}
}