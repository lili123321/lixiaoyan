#include<iostream.h>
#include<string.h>
class father
{
protected:
	char* fname;
	char* sname;
	int age;
public:
	father()
	{cout<<"fatherĬ�Ϲ��캯������!"<<endl;fname=NULL;sname=NULL;}
	father(char *fn,char *sn,int a)
	{
		cout<<"father���캯������!"<<endl;
		fname=new char[strlen(fn)+1];
		strcpy(fname,fn);
		sname=new char[strlen(sn)+1];
		strcpy(sname,sn);
		age=a;
	}
	~father()
	{
		cout<<"father������������!"<<endl;
		delete fname;
		delete sname;
	}
	char *getfname(){return fname;}
	void show(){cout<<fname<<sname<<"  ����:"<<age;}
};
class mother
{
protected:
	char* fname;
	char* sname;
	int age;
public:
	mother()
	{cout<<"motherĬ�Ϲ��캯������!"<<endl;fname=NULL;sname=NULL;}
	mother(char *fn,char *sn,int a)
	{
		cout<<"mother���캯������!"<<endl;
		fname=new char[strlen(fn)+1];
		strcpy(fname,fn);
        sname=new char[strlen(sn)+1];
		strcpy(sname,sn);
		age=a;
	}
	~mother()
	{
		cout<<"mother������������!"<<endl;
		delete fname;
		delete sname;
	}
	char *getfname(){return fname;}  //�˾��ʡ��
	void show(){cout<<fname<<sname<<"  ����:"<<age;}
};
class child:public mother,public father
{
private:
	father* myfather;
	mother* mymother;
public:
	child(){cout<<"child���캯������!"<<endl;}
	child(father& fa,mother &mo,char *na,int a)
		:myfather(&fa),mymother(&mo)
	{
		cout<<"child���캯������!"<<endl;
      //����ʡ��mother::������ֶ�����
		mother::fname=new char[strlen(fa.getfname())+1];  
	//������ĸ�գ����Ϊstrcpy(mother::fname,mo.getfname());
		strcpy(mother::fname,fa.getfname());
        mother::sname=new char[strlen(na)+1];
		strcpy(mother::sname,na);
		mother::age=a;  //����д��age=a; 
	}
	~child(){cout<<"child������������!"<<endl;}
	void show()
	{
		cout<<"  ����:"; mother::show();
		cout<<endl;
		cout<<"����:"; myfather->show();
		cout<<endl;
		cout<<"ĸ��:"; mymother->show();
		cout<<endl;
	}
};
void main()
{
	father fa1("ŷ��","����",50),fa2("��","ΰ��",40);
	mother mo1("��","����",47),mo2("��","Ӣ",35);
	child ch1(fa1,mo1,"�ǳ�",23),ch2(fa2,mo2,"��",10);
	cout<<"������:"<<endl;
	ch1.show();
	ch2.show();
}
