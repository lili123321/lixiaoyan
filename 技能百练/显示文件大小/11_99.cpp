#include<iostream.h>
#include<fstream.h>
void main()
{
	char fname[20];
	cout<<"�����ļ���:";
	cin>>fname;
	ifstream file(fname,ios::nocreate|ios::in);
	try
	{
		if(file.fail())
		//���ļ�������ʱ��file.fail()������
			throw "error!";
	}
	catch(char *s)
	{
		cout<<s<<fname<<"�ļ�������!"<<endl;
		return;
	}
	file.seekg(0,ios::end);
	//�˾���Ϊ���ļ��Ķ�ָ�������ļ�ĩβ
	cout<<fname<<"�ļ���С:"<<file.tellg()<<"Bytes"<<endl;
	//tellg()�������ص�ǰ�ļ�ָ���λ��
}
