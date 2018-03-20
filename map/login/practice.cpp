#include <iostream>
#include <string>
#include "practice.h"
using namespace  std;
int main()
  {
	  //形参值改变，实参值仍旧不变
     string s="mrsoft";
	 string s1="";
	/* string *s2=&s1;*/
	 int size=s.size();
	 int size1=100;
     Aa g;
	 g.encrypt(s,size,s1,size1);
	 cout<<"mrsoft的密文是"<<s1<<endl;
	 return 0;

  }

 

