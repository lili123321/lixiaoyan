#include<iostream.h>
#include<fstream.h>
void main()
{
	fstream file1,file2;
	char fn1[10],fn2[10],ch;
	cout<<"������Դ�ļ���:";
	cin>>fn1;
	cout<<"������Ŀ���ļ���:";
	cin>>fn2;
	file1.open(fn1,ios::in);
	file2.open(fn2,ios::out);
	while((ch=file1.get())!=EOF)
	{
		cout<<ch;
		file2.put(ch);
	}
	file1.close();
	file2.close();  
}
/*�ڶ��ְ�����һ���Ƶĳ���Ϊ��
#include<iostream.h>
#include<fstream.h>
void main()
{
	fstream file1,file2;
	char fn1[10],fn2[10],buf[100];
	cout<<"������Դ�ļ���:";
	cin>>fn1;
	cout<<"������Ŀ���ļ���:";
	cin>>fn2;
	file1.open(fn1,ios::in);
	file2.open(fn2,ios::out);
	while(!file1.eof())
	{
		file1.getline(buf,100);
		file2<<buf;
		file2<<"\n";
	}
	file1.close();
	file2.close();
}  */
