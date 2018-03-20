#include <iostream>
#include <sstream>
#include<fstream>
using namespace std;
int main()
{
   /*stringstream  s;
   s<<1<<" "<<55<<" "<<6;
   cout<<s.str()<<endl;

   stringstream  s1;
   int a;
   string        ss="1 2 3 4 5";
   s1.str(ss);
   s1>>a;
   cout<<a<<endl;

   stringstream s3;
   string m;
   string name;
   while(getline(cin,m))
   {
        s3.str(m);
		s3>>name;
		cout<<name;
   }*/


   string path="E:\\JSTB\\trunk\\src\\sengine\\bin64\\jstp_exp.ini";
   string a;
   string  b;
   stringstream  s;
   fstream fs(path.c_str());
   if (fs.is_open())
   {
     while(getline(fs,a))
	 {
		 s.clear();
         s.str(a);
		 s>>b;
		 cout<<b<<endl;
		 cout<<a<<endl;

	 }


   }
  




}