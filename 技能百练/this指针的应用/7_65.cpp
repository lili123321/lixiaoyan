#include <string.h>
#include <iostream.h>
class student
{
	public:
		student(char * pName="no name",int ssId=0)
		{
			id=ssId;
			name=new char[strlen(pName)+1];
			strcpy(name,pName);
			cout<<"construct new student "<<pName<<endl;
		}
		//���󣡲�����˱�дcopy����,��Ϊʵ�ֵ���ǰǳ����
	/*	void copy(student & s)
		{
			cout<<"construct copy of"<<s.name<<endl;
			strcpy(name,s.name);
			id=s.id;
		}*/
		void copy(student & s)  //��Դ���ƺ���
		{
		    if(this==&s)
			{
		    	cout<<"����:���ܽ�һ�������Ƶ��Լ���"<<endl;
		    	return;
			}
	    	else
			{
			    name=new char[strlen(s.name)+1];        // �ٷ����µĶ��ڴ�
		        strcpy(name,s.name);					// �����ֵ�ĸ���
		        id=s.id;
		    	cout<<"��Դ���ƺ��������ã�"<<endl;
			}
			
		}
		void disp()
		{
			cout<<"Name:"<<name<<"  Id:"<<id<<endl;
		}
		~student()
		{
			cout<<"Destruct "<<name<<endl;
			delete name;
		}
	private:
		int id;
		char * name;
};

void main()
{
	student a("Kevin",12),b("Tom",23);   // ������ͨ�Ĺ��캯��
    a.disp();
	b.disp();
    a.copy(a);
    b.copy(a);      // ������Դ���ƺ���
	a.disp();
	b.disp();
}
