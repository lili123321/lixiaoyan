#include <string>
#include <fstream>
#include <iostream>
#include <map>
using namespace std;
int main()
{
	//fstream.open()����Ϊvoid���ͣ�
	//������ filename   �����ļ���   mode   ���ļ��ķ�ʽ  prot   ���ļ�������   
	//	���ļ��ķ�ʽ��iOS��(������ʽI/O�Ļ���)�ж��壬�����¼��ַ�ʽ��
	//	ios::in	Ϊ����(��)�����ļ�
	//	ios::out	Ϊ���(д)�����ļ�
	//	ios::ate	��ʼλ�ã��ļ�β
	//	ios::app	��������������ļ�ĩβ
	//	ios::trunc	����ļ��Ѵ�������ɾ�����ļ�
	//	ios::binary	�����Ʒ�ʽ

	//���ļ�������ͬ����ios����Ҳ�ж��壺0	��ͨ�ļ����򿪲���    1	ֻ��   2	�����ļ�  4	ϵͳ�ļ�
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

		// FILE * fopen(const char * path,const char * mode)���ļ�˳���򿪺�ָ��������ļ�ָ��ͻᱻ���ء�����ļ���ʧ���򷵻�NULL�����Ѵ���������errno �С�����path�ַ����������򿪵��ļ�·�����ļ���������mode�ַ��������������̬mode(r����wд)
		 fp=fopen(s.c_str(),"r");

        //int fseek(FILE *stream, long offset, int fromwhere);fseek ���ڶ����Ʒ�ʽ�򿪵��ļ�,�ƶ��ļ���дָ��λ��. ��һ������streamΪ�ļ�ָ�룬�ڶ�������offsetΪƫ������������ʾ����ƫ�ƣ�������ʾ����ƫ�ƣ�����������origin�趨���ļ������￪ʼƫ��,����ȡֵΪ��SEEK_CUR�� SEEK_END �� SEEK_SET��SEEK_SET�� �ļ���ͷ��SEEK_CUR�� ��ǰλ�ã�SEEK_END�� �ļ���β
		 fseek(fp,0,SEEK_END);
		 
		 //���ڵõ��ļ�λ��ָ�뵱ǰλ��������ļ��׵�ƫ���ֽ�����
		 int nFileSize= ftell(fp);

         char*  m_szFile=new char(nFileSize+1);

		 memset(m_szFile,'/0',nFileSize+1);
		 
		 fseek(fp,0,SEEK_SET);

		 // fread ( void *buffer, size_t size, size_t count, FILE *stream) ;/*buffer  ���ڽ������ݵ��ڴ��ַ size  Ҫ����ÿ����������ֽ�������λ���ֽ� count   Ҫ��count�������ÿ��������size���ֽ�. stream  ������    ����ֵ  ������ʵ��ȡ��������������count����ζ�Ų����˴���*/ 
		 
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
              char szOneLine[4096];  //��ȡһ�н������ַ���
               
			  while(*p!='\n'&& *p!='\r'&& nReadCount < nFileSize)
			  {
                p++;
				nReadCount++;
			  }
			  memset(szOneLine,'\0',sizeof(szOneLine));
              strncpy_s(szOneLine, sizeof(szOneLine), pStart, p - pStart); 

			  //strchr����ԭ�ͣ�extern char *strchr(const char *s,char c);�����ַ���s���״γ����ַ�c��λ�á�
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