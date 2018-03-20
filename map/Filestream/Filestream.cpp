#include <string>
#include <fstream>
#include <iostream>
#include <map>
using namespace std;
int main()
{
	//fstream.open()函数为void类型，
	//参数： filename   操作文件名   mode   打开文件的方式  prot   打开文件的属性   
	//	打开文件的方式在iOS类(所以流式I/O的基类)中定义，有如下几种方式：
	//	ios::in	为输入(读)而打开文件
	//	ios::out	为输出(写)而打开文件
	//	ios::ate	初始位置：文件尾
	//	ios::app	所有输出附加在文件末尾
	//	ios::trunc	如果文件已存在则先删除该文件
	//	ios::binary	二进制方式

	//打开文件的属性同样在ios类中也有定义：0	普通文件，打开操作    1	只读   2	隐含文件  4	系统文件
	string s="E:\\JSTB\\trunk\\src\\sengine\\bin64\\jstp_exp.ini";
    string b;
    fstream  a;
	a.open(s.c_str(),ios::out|ios::in);
	if (a.is_open())
	{
        /*while (!a.eof())
		{
			a>>b;
			cout<<b<<endl;
		}*/
         
		 FILE   *fp =NULL;

		// FILE * fopen(const char * path,const char * mode)：文件顺利打开后，指向该流的文件指针就会被返回。如果文件打开失败则返回NULL，并把错误代码存在errno 中。参数path字符串包含欲打开的文件路径及文件名，参数mode字符串则代表着流形态mode(r读，w写)
		 fp=fopen(s.c_str(),"r");

        //int fseek(FILE *stream, long offset, int fromwhere);fseek 用于二进制方式打开的文件,移动文件读写指针位置. 第一个参数stream为文件指针，第二个参数offset为偏移量，整数表示正向偏移，负数表示负向偏移，第三个参数origin设定从文件的哪里开始偏移,可能取值为：SEEK_CUR、 SEEK_END 或 SEEK_SET，SEEK_SET： 文件开头，SEEK_CUR： 当前位置，SEEK_END： 文件结尾
		 fseek(fp,0,SEEK_END);
		 
		 //用于得到文件位置指针当前位置相对于文件首的偏移字节数。
		 int nFileSize= ftell(fp);

         char*  m_szFile=new char(nFileSize+1);

		 memset(m_szFile,'/0',nFileSize+1);
		 
		 fseek(fp,0,SEEK_SET);

		 // fread ( void *buffer, size_t size, size_t count, FILE *stream) ;/*buffer  用于接收数据的内存地址 size  要读的每个数据项的字节数，单位是字节 count   要读count个数据项，每个数据项size个字节. stream  输入流    返回值  返回真实读取的项数，若大于count则意味着产生了错误*/ 
		 
		 int a=fread(m_szFile,sizeof(char),nFileSize,fp);

		 const char *p=m_szFile;
		 const char *pStart;

         int nReadCount = 0; 

		 map<string,string>  map1;
		 char  key[1024];
		 char  value[1024];

		 while(nReadCount < nFileSize)
		 {
			  pStart = p;
              char szOneLine[4096];  //读取一行结束的字符串
               
			  while(*p!='\n'&& *p!='\r'&& nReadCount < nFileSize)
			  {
                p++;
				nReadCount++;
			  }
			  memset(szOneLine,'\0',sizeof(szOneLine));
              strncpy_s(szOneLine, sizeof(szOneLine), pStart, p - pStart); 

			  //strchr函数原型：extern char *strchr(const char *s,char c);查找字符串s中首次出现字符c的位置。
			  char * pEqualSign=strchr(szOneLine, '=');
			  if (pEqualSign)
			  {
				   strncpy_s(key,sizeof(key),szOneLine,pEqualSign - szOneLine);
				   pEqualSign++;
				   strncpy_s(value,sizeof(value),pEqualSign,szOneLine - pEqualSign);
				   map1.insert(pair<string,string>(key,value));
			  }

			  if (*p == '\n' && nReadCount < nFileSize)
			  {
				  p++;
				  nReadCount++;
			  }           

		 }

		 for (map<string,string>::iterator  itmap=map1.begin();itmap!=map1.end();itmap++)
         {

		   cout<<itmap->first<<"  "<<itmap->second<<endl;
         }	
   
	}
	
}