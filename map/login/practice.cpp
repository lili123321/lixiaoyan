#include <iostream>
#include <string>
#include "practice.h"
using namespace  std;
int main()
  {
	  //�β�ֵ�ı䣬ʵ��ֵ�Ծɲ���
     string s="mrsoft";
	 string s1="";
	/* string *s2=&s1;*/
	 int size=s.size();
	 int size1=100;
     Aa g;
	 g.encrypt(s,size,s1,size1);
	 cout<<"mrsoft��������"<<s1<<endl;
	 return 0;

  }

 

