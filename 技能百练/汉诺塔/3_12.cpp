#include<iostream.h>
void move(char one,char anoth)
{
	cout<<one<<"�ƶ���"<<anoth<<endl;
}

void hanoi(int n,char no1,char no2,char no3)
{
	//
	if (n==1) move(no1,no3);
	else 
	{
		hanoi(n-1,no1,no3,no2);
		move(no1,no3);
        hanoi(n-1,no2,no1,no3);
	}
}

void main()
{
	void hanoi(int n,char no1,char no2,char no3);
	int m;
	cout<<"������A���ϵĽ�����������";
	cin>>m;
	cout<<"����"<<m<<"��������ʱ���ƶ���������Ϊ��"<<endl;
	hanoi(m,'A','B','C');
}
