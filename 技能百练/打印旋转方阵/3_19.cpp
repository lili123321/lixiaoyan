#include <iostream.h>
#include<iomanip.h>
#define N 6
void main()
{
	int a[N+1][N+1];
	int row,column,i,j,k,t,p;
	row=0;column=1;k=N;t=1;p=1;

	do
	{
		for(i=1;i<=k;i++)  //��һ������ֵ
		{
			row+=t;
			a[row][column]=p;
			p++;
		}
		k--;   //������һ
		for(i=1;i<=k;i++)  //��һ������ֵ
		{
			column+=t;
			a[row][column]=p;
			p++;
		}
		t=-t;   //�ı丳ֵ����
	}while(p<=N*N);  //��ֵ����N*N����ʱ��ֹ

	for(i=1;i<=N;i++)   //�������
	{
		for(j=1;j<=N;j++)
			cout<<setw(5)<<a[i][j];
		cout<<endl;
	}
}
