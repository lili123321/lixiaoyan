#include <iostream>
#include <map>
#include <string>
#include <sstream>
using namespace std;
int main()
{
	string s;
	stringstream  s1;
	s1<<1<<","<<2<<","<<3<<","<<4;
	s="aaaaaaa";
	map<string,string> mapstudent; 
	map<int,string> maptable;
	map<string, string>::iterator  itmap;
	mapstudent.insert(pair<string, string>("3", s));
	mapstudent.insert(pair<string, string>("6", "666"));
	mapstudent.insert(pair<string, string>("1", "9999"));
	maptable.  insert(pair<int, string>(10,"riskfund"));
	//itmap=mapstudent.find(s);
	/*if(itmap!=mapstudent.end())
	{
      cout<<itmap->second<<endl;
	}*/
	for(itmap=mapstudent.begin();itmap!=mapstudent.end();itmap++)
	{
      cout<<itmap->first<<"   "<<itmap->second<<endl;
	
	}
	/*for(itmap=mapstudent.begin();itmap!=mapstudent.end();itmap++)
	{
		cout<<itmap->first<<"   "<<itmap->second<<endl;

	}*/
	cout<<mapstudent.size()<<endl;
	cout<<maptable.size()<<endl;
}
