#include<iostream.h>
#include<string.h>
#define max 100
class Card
{
	int top;  //��ǰ��¼λ�ñ��
	char date[max][11];  //ÿ�ν��׵����ڼ�¼
	int money[max];  //��¼ÿ�ν��׽��
	int rest[max];  //��¼ÿ�ν��׺�����
	static int sum;  //	��̬���ݳ�Ա,��¼�ۼ����
public:
	Card() {top=0;}
	void Cardin(char d[],int m)
	{
		strcpy(date[top],d);
		money[top]=m;
		sum+=m;
		rest[top]=sum;
		top++;
	}
	void Cardout(char d[],int m)
	{
		if(sum>=m)
		{
			strcpy(date[top],d);
		    money[top]=-m;
		    sum-=m;
		    rest[top]=sum;
	    	top++;
		}
		else
			cout<<"���棺"<<d<<"����ʧ�ܣ����Ļ�������Ѳ��㣡�����棡"<<endl;
	}
	void disp()
	{
		int i;
		cout<<"    ����    ����    ȡ��    ���"<<'\n';
		for(i=0;i<top;i++)
		{
			cout.width(10);
			cout<<date[i];
			if (money[i]<0)
			{
				cout.width(13);
				cout<<-money[i];
                cout.width(9);
			    cout<<rest[i]<<endl;
			}
			else
			{
				cout.width(6);
				cout<<money[i];
				cout.width(16);
			    cout<<rest[i]<<endl;
			}
		}
		cout<<"�����ʻ����Ϊ��"<<sum<<endl;
	}
};
int Card::sum=0;
void main()
{
	Card obj;
	obj.Cardin("2001.2.5",1000);
	obj.Cardin("2002.12.15",2000);
	obj.Cardout("2002.11.5",500);
	obj.Cardout("2003.3.5",400);
	obj.Cardout("2003.5.15",3000);
	obj.disp();
}
