#include<iostream.h>
#include<string.h>
#define Max 20
class Destination
{
protected:
	char from[Max];
	char to[Max];
public:
	Destination()
	{
		strcpy(from,"");strcpy(to,"");
	}
	Destination(char f[],char t[])
	{
		strcpy(from,f);strcpy(to,t);
	}
	void getdata()
	{
		cout<<"���뷢���ص� �ջ��ص�:";
		cin>>from>>to;
	}
	void disp()
	{
		cout<<"�ƷѴ�"<<from<<"��"<<to;
	}
};
class Time
{
protected:
	int hour,minute,second;
	double time;
public:
	Time(){time=0;}
	Time(double t){time=t;}
	void getdata()
	{
		cout<<"����ͨ��ʱ��:ʱ �� ��";
		cin>>hour>>minute>>second;
		time=(double)(hour*3600+minute*60+second);
	}
	void disp()
	{
		cout<<"ͨ��ʱ����"<<time<<"��";
	}
};
class Price:public Destination,public Time
{
	double price;
public:
	Price():Destination(),Time()
	{price=0;}
	Price(char f[],char t[],double tt):Destination(f,t),Time(tt)
	{
		price=(int)((tt+5)/6)*0.06;
	}
	void getdata()
	{
		Destination::getdata();
		Time::getdata();
		price=(int)((time+5)/6)*0.06;
	}
	void disp()
	{
		cout<<"  ";
		Destination::disp();
		Time::disp();
		cout<<",������"<<price<<"Ԫ"<<endl;
	}
};
void main()
{
	Price A;
	A.getdata();
	Price B("AAA","BBB",123);
	cout<<"������:"<<endl;
	A.disp();
	B.disp();
}
