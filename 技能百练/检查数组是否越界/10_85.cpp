#include<iostream.h>
#include<string.h>
class words
{
	int len;
	char *str;
public:
	int getlen(){return len;}
	words(char *s)
	{
		str=new char[strlen(s)+1];
		strcpy(str,s);
		len=strlen(s);
	}
	~words(){delete str;}
	char operator [](int n)
	{
		static char ch;  //�������ַ�
		if(n>len-1)
		{
			cout<<"�����±�Խ�磡";
			return ch;
		}
		else 
			return *(str+n);
	}
	void disp(){cout<<str<<endl;}
};
void main()
{
	words word("Time devours all things!");
	word.disp();
	cout<<"������ַ�����Ϊ��"<<word.getlen()<<endl;
	for(int i=0;i<25;i++)
		cout<<word[i]<<" ";
	cout<<endl;
}
