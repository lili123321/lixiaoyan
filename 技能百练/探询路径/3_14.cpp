#include<iostream.h>
#include<string.h>
int n,k;  //k��ʾ�ڼ���·����nΪ����·�����յ�
void path(int n,char s[20])  //s��ʾ�����
{
	char s1[20];
	s1[0]='-';
	s1[1]=n+48; //�����������ֵת��Ϊ��Ӧ�ַ���ASCII��ֵ
	s1[2]='\0';
	strcat(s1,s);  //�ַ������ӣ�����S1��
	if(n>1) path(n-2,s1);
	if(n>0) path(n-1,s1);
	if(n==0)
	{
		k++;
		cout<<k<<" : 0"<<s<<endl;
	}
}

void main()
{
	do
	{
		cout<<"n=";
		cin>>n;
	}while(!(n>=0&& n<=9));
	k=0;
	path(n,"");
}
