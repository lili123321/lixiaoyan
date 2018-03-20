#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <io.h>
#include <fstream>
#include <Windows.h>
#include "tinyxml.h"
#include "../../lbm/public/lbminfodata.h"
#include "kdexception.h"
#include "buildinfo.h"
#include "../../kamc/comm/struct_exception.h"
using namespace std;

typedef int(*Dllfun)(char*);

struct TagConfiginfo
{
public:
	TagConfiginfo()
	{
		Clear();
	}
	void Clear()
	{
		m_strFunctionName = "";
		m_strOutDllpath="";
		m_strDllpath = "";
		m_strLbmid = ""`;		
	}

	string	m_strFunctionName;
	string  m_strDllpath;
	string  m_strLbmid;
	string  m_strOutDllpath;
};

class CInfoBase
{
 public:
	 CInfoBase()
	 {
        m_pvcLbminfo= new vector<CLbminfo>;
	 }
	 ~CInfoBase()
	 {
        delete  m_pvcLbminfo;
	 }

public:

	 void run(char* SenginePath,char* KcbpPath,char* OutputPath)
	 {
		try
		{
	       //��������lbm_export.h�ļ�
		   LoadInfo(SenginePath);

		   //���ع��ܺź�����������Ϣ
		   InitSpdinfo(KcbpPath);

		   //�����Ŷӻ������ļ�
		   CreateFunctionXml(OutputPath);

		   //��ȡlbm�������Ϣ
		   Getlbminfo(OutputPath);
	   
		   //�������������ļ�
		   CreateKcxpconvFile(OutputPath);
		}
		catch (exception)
		{
			string strErrmsg;
		}

	 }

	 //��ȡ������Ҫ��������Ϣ
	 void getinfo(char* SenginePath)
	 {
		 try
		 {
			 //��������vcproject�ļ�
			 LoadInfo(SenginePath);

			 InitBuildInfo();

			 //���ɱ����������Ϣ
			 CreateBuildinfo();
			
		 }
		 catch (exception)
		 {
			 string strErrmsg;
		 }

	 }

	 void LoadInfo(string sPath)
	 {
		 long   handle;	 
		 struct _finddata_t fileinfo;//�ļ���Ϣ�Ľṹ��
		 string p;
		 
		 if ((handle = _findfirst(p.assign(sPath).append("\\*.*").c_str(), &fileinfo)) != NULL)  //��һ�β���  
		 {
		     while ( _findnext(handle,&fileinfo)==0)
		     {
			    if (fileinfo.attrib &  _A_SUBDIR)  //������ҵ������ļ���  
			    {
				    //��Ϊ��ϵͳ�д�һ���ļ���ǰ����Ĭ���ǡ�.����".."��������ѹ���ļ��п�����һ���������������һ��ᵼ�����޵���
				    if(strcmp(fileinfo.name,".")!=0 && strcmp(fileinfo.name,"..")!=0)
				    {
					   LoadInfo(p.assign(sPath).append("\\").append(fileinfo.name));
                    }
			    }
			 
			    else //���ҵ��Ĳ����ļ���
			    {
				   string a(fileinfo.name);
                   if(strcmp(fileinfo.name,"lbm_export.h")==0)
				   {
					  path.push_back(p.assign(sPath).append("\\").append(fileinfo.name));
				   }
				   if (strstr(a.c_str(),".vcproj")!=NULL&& a.find("vcproj")==a.find_last_of('.')+1)
				   {
					   
					   buildpath.push_back(fileinfo.name);
				   }

			    }
		     }
		   _findclose(handle); //��������  
	     }
	  }

	void  InitBuildInfo()
	{
		for(int i=0;i<buildpath.size();i++)
		{
           objBuildInfo.sProjectName=buildpath[i];
		   objBuildInfo.sPlatform="x64";
		   objBuildInfo.sResource="oracle_debug";
		   objBuildInfo.sBuildStatus="δ����";
		   m_vBuildinfo.push_back(objBuildInfo);
		}
	}

	void CreateBuildinfo()
	{

	}

    void  InitSpdinfo(string sPath)
	{
		for(int i=0;i<path.size();i++)
		{
			ifstream  fin(path[i].c_str());  
			string s;  
			while(getline(fin,s)) //getline(fin,s) ���ж�ȡ��fin>>s�Ķ�ȡ�������ո�ֹͣ
			{   
				if (strstr(s.c_str(),"//")!=NULL)  //���ܺ�¼��
				{
                    for (int i=0;i<strlen(s.c_str());i++)
                    {
						if (s[i]>='0'&&s[i]<='9') //�ж�Ϊ������
						{
							objTagConfiginfo.m_strLbmid.append(1,s[i]);//string ��append()��������stringҲ�����ַ�������ַ���ͼ��ʾ,ƴ���ַ���+;
						}
                    }
				}
				if(strstr(s.c_str(),"EXPORT_LBM_FUNC")!=NULL)//������¼��
				{ 
                    objTagConfiginfo.m_strFunctionName= s.substr(s.find("(")+1 ,s.find(")")-s.find("(")-1);       			          
				}
		
				if (objTagConfiginfo.m_strFunctionName.length()!=0 && objTagConfiginfo.m_strLbmid.length()!=0)
				{
					size_t pos1 =path[i].rfind("\\");
					size_t pos2 = path[i].rfind("\\", pos1-1);

					char szDllpath[1024];
					//sprintf_s��c���Եĺ�����string���ͺ�����c_str()����ƴ����
                    sprintf_s(szDllpath,".\\function\\%s.dll",(path[i].substr(pos2+1,pos1-1-pos2)).c_str());

                    objTagConfiginfo.m_strDllpath=szDllpath;
					//dll��·��
					objTagConfiginfo.m_strOutDllpath.append(sPath).append("\\").append(path[i].substr(pos2+1,pos1-1-pos2)).append(".dll");

                    vcStConfiginfo.push_back(objTagConfiginfo);
					objTagConfiginfo.Clear();
				}            
			}
		}
	}

	/* 
    TiXmlDocument���ĵ��࣬������������xml�ļ� 
    TiXmlDeclaration�������࣬����ʾ�ļ����������� 
    TiXmlComment��ע���࣬����ʾ�ļ���ע�Ͳ��� 
    TiXmlElement��Ԫ���࣬�����ļ�����Ҫ���֣�����֧��Ƕ�׽ṹ��һ��ʹ�����ֽṹ������Ĵ洢��Ϣ�������԰�����������ı��� 
    TiXmlAttribute/TiXmlAttributeSet��Ԫ�����ԣ���һ��Ƕ����Ԫ���У����ڼ�¼��Ԫ�ص�һЩ���� 
    TiXmlText���ı�������Ƕ����ĳ��Ԫ���ڲ� 
    */  
	void CreateFunctionXml(string sPath)
	{
		string strFilepath = sPath + "\\function.xml";
		TiXmlDocument *writeDoc = new TiXmlDocument(); //xml�ĵ�ָ��  

		//�ĵ���ʽ����  
		TiXmlDeclaration *decl = new TiXmlDeclaration("1.0", "UTF-8", "yes");  
		writeDoc->LinkEndChild(decl); //д���ĵ� 

		TiXmlElement *RootElement = new TiXmlElement("jstp");//��Ԫ��  
		writeDoc->LinkEndChild(RootElement);  

        for (int i=0;i<vcStConfiginfo.size();i++)
        {
			TiXmlElement *StuElement = new TiXmlElement("program");//program  
			//��������  
			StuElement->SetAttribute("func_id",vcStConfiginfo[i].m_strLbmid.c_str()); 
			StuElement->SetAttribute("path",vcStConfiginfo[i].m_strDllpath.c_str());
			StuElement->SetAttribute("module",vcStConfiginfo[i].m_strFunctionName.c_str());
			StuElement->SetAttribute("type","trade");
			StuElement->SetAttribute("timeout","60");
			StuElement->SetAttribute("cache",  "no");

			RootElement->LinkEndChild(StuElement);//���ڵ�д���ĵ�
        }
		writeDoc->SaveFile(strFilepath.c_str());  
		delete writeDoc;  
	}

	void Getlbminfo(string sPath)
	{
		for (int i=0;i<vcStConfiginfo.size();i++)
		{
			HINSTANCE hdll;
			hdll=LoadLibrary(vcStConfiginfo[i].m_strOutDllpath.c_str());
			if(hdll==NULL)
			{
				FreeLibrary(hdll);
			}
			
			Dllfun fp = (Dllfun)GetProcAddress(hdll,vcStConfiginfo[i].m_strFunctionName.c_str());

			if(i==57)
			 return;
			
			if (fp==NULL)
			{
				FreeLibrary(hdll);
			}
     
			//ȡ�����
		    fp((char *)m_pvcLbminfo);

		    mapLbminfo.insert(pair<string,vector<CLbminfo>>(vcStConfiginfo[i].m_strLbmid,*m_pvcLbminfo));
			m_pvcLbminfo->clear();
			
		 }		
	 }

	 void CreateKcxpconvFile(string sPath)
	 {
		 string strFilepath = sPath + "\\kcxpconv.xml";
		 TiXmlDocument *writeDoc = new TiXmlDocument(); //xml�ĵ�ָ��  

		 //�ĵ���ʽ����  
		 TiXmlDeclaration *decl = new TiXmlDeclaration("1.0", "UTF-8", "yes");  
		 writeDoc->LinkEndChild(decl); //д���ĵ� 

		 TiXmlElement *RootElement = new TiXmlElement("root");//��Ԫ��  
		 writeDoc->LinkEndChild(RootElement);  

		 for (map<string, vector<CLbminfo>>::iterator  itmap=mapLbminfo.begin();itmap!=mapLbminfo.end();itmap++)
		 {
			 TiXmlElement *StuElement = new TiXmlElement("lbm");//program  
			 //��������  
			 StuElement->SetAttribute("name",itmap->first.c_str()); 
			 StuElement->SetAttribute("descripe","");
			 RootElement->LinkEndChild(StuElement);//���ڵ�д���ĵ�

			 TiXmlElement *Lbminfo=new TiXmlElement("params");
			 StuElement->LinkEndChild(Lbminfo);

             m_vLbminfo=itmap->second;
			 for (int i=0;i<m_vLbminfo.size();i++)
			 {
				 TiXmlElement *outparams=new TiXmlElement("param"); 
				 outparams->SetAttribute("name",m_vLbminfo[i].m_strFieldname.c_str());
				 outparams->SetAttribute("datatype",m_vLbminfo[i].m_strFieldtype.c_str());
				 outparams->SetAttribute("capition","11");
				 Lbminfo->LinkEndChild(outparams);
			 }		 
		 }      
		 writeDoc->SaveFile(strFilepath.c_str());  
		 delete writeDoc;  
	 }



  public: 
	vector<CLbminfo> *m_pvcLbminfo;
	vector<CLbminfo>  m_vLbminfo;
	vector<CBuildInfo>m_vBuildinfo;
	map<string,vector<CLbminfo>> mapLbminfo;
	vector<string>    path;
	vector<string>    buildpath;
	TagConfiginfo     objTagConfiginfo;
	CBuildInfo        objBuildInfo;
	vector<TagConfiginfo>  vcStConfiginfo;

};