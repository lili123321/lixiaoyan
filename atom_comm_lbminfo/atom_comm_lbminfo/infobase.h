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
	       //查找所有lbm_export.h文件
		   LoadInfo(SenginePath);

		   //加载功能号函数等配置信息
		   InitSpdinfo(KcbpPath);

		   //创建排队机配置文件
		   CreateFunctionXml(OutputPath);

		   //获取lbm的入参信息
		   Getlbminfo(OutputPath);
	   
		   //生成网关配置文件
		   CreateKcxpconvFile(OutputPath);
		}
		catch (exception)
		{
			string strErrmsg;
		}

	 }

	 //获取编译需要的配置信息
	 void getinfo(char* SenginePath)
	 {
		 try
		 {
			 //查找所有vcproject文件
			 LoadInfo(SenginePath);

			 InitBuildInfo();

			 //生成编译的配置信息
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
		 struct _finddata_t fileinfo;//文件信息的结构体
		 string p;
		 
		 if ((handle = _findfirst(p.assign(sPath).append("\\*.*").c_str(), &fileinfo)) != NULL)  //第一次查找  
		 {
		     while ( _findnext(handle,&fileinfo)==0)
		     {
			    if (fileinfo.attrib &  _A_SUBDIR)  //如果查找到的是文件夹  
			    {
				    //因为在系统中打开一个文件夹前两个默认是“.”和".."（就像在压缩文件中看到的一样），如果不加这一句会导致无限迭代
				    if(strcmp(fileinfo.name,".")!=0 && strcmp(fileinfo.name,"..")!=0)
				    {
					   LoadInfo(p.assign(sPath).append("\\").append(fileinfo.name));
                    }
			    }
			 
			    else //查找到的不是文件夹
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
		   _findclose(handle); //结束查找  
	     }
	  }

	void  InitBuildInfo()
	{
		for(int i=0;i<buildpath.size();i++)
		{
           objBuildInfo.sProjectName=buildpath[i];
		   objBuildInfo.sPlatform="x64";
		   objBuildInfo.sResource="oracle_debug";
		   objBuildInfo.sBuildStatus="未编译";
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
			while(getline(fin,s)) //getline(fin,s) 按行读取，fin>>s的读取则是遇空格停止
			{   
				if (strstr(s.c_str(),"//")!=NULL)  //功能号录入
				{
                    for (int i=0;i<strlen(s.c_str());i++)
                    {
						if (s[i]>='0'&&s[i]<='9') //判断为纯数字
						{
							objTagConfiginfo.m_strLbmid.append(1,s[i]);//string 的append()后面能是string也能是字符，添加字符如图所示,拼接字符用+;
						}
                    }
				}
				if(strstr(s.c_str(),"EXPORT_LBM_FUNC")!=NULL)//函数名录入
				{ 
                    objTagConfiginfo.m_strFunctionName= s.substr(s.find("(")+1 ,s.find(")")-s.find("(")-1);       			          
				}
		
				if (objTagConfiginfo.m_strFunctionName.length()!=0 && objTagConfiginfo.m_strLbmid.length()!=0)
				{
					size_t pos1 =path[i].rfind("\\");
					size_t pos2 = path[i].rfind("\\", pos1-1);

					char szDllpath[1024];
					//sprintf_s是c语言的函数，string类型后必须加c_str()才能拼接上
                    sprintf_s(szDllpath,".\\function\\%s.dll",(path[i].substr(pos2+1,pos1-1-pos2)).c_str());

                    objTagConfiginfo.m_strDllpath=szDllpath;
					//dll的路径
					objTagConfiginfo.m_strOutDllpath.append(sPath).append("\\").append(path[i].substr(pos2+1,pos1-1-pos2)).append(".dll");

                    vcStConfiginfo.push_back(objTagConfiginfo);
					objTagConfiginfo.Clear();
				}            
			}
		}
	}

	/* 
    TiXmlDocument：文档类，它代表了整个xml文件 
    TiXmlDeclaration：声明类，它表示文件的声明部分 
    TiXmlComment：注释类，它表示文件的注释部分 
    TiXmlElement：元素类，它是文件的主要部分，并且支持嵌套结构，一般使用这种结构来分类的存储信息，它可以包含属性类和文本类 
    TiXmlAttribute/TiXmlAttributeSet：元素属性，它一般嵌套在元素中，用于记录此元素的一些属性 
    TiXmlText：文本对象，它嵌套在某个元素内部 
    */  
	void CreateFunctionXml(string sPath)
	{
		string strFilepath = sPath + "\\function.xml";
		TiXmlDocument *writeDoc = new TiXmlDocument(); //xml文档指针  

		//文档格式声明  
		TiXmlDeclaration *decl = new TiXmlDeclaration("1.0", "UTF-8", "yes");  
		writeDoc->LinkEndChild(decl); //写入文档 

		TiXmlElement *RootElement = new TiXmlElement("jstp");//根元素  
		writeDoc->LinkEndChild(RootElement);  

        for (int i=0;i<vcStConfiginfo.size();i++)
        {
			TiXmlElement *StuElement = new TiXmlElement("program");//program  
			//设置属性  
			StuElement->SetAttribute("func_id",vcStConfiginfo[i].m_strLbmid.c_str()); 
			StuElement->SetAttribute("path",vcStConfiginfo[i].m_strDllpath.c_str());
			StuElement->SetAttribute("module",vcStConfiginfo[i].m_strFunctionName.c_str());
			StuElement->SetAttribute("type","trade");
			StuElement->SetAttribute("timeout","60");
			StuElement->SetAttribute("cache",  "no");

			RootElement->LinkEndChild(StuElement);//父节点写入文档
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
     
			//取的入参
		    fp((char *)m_pvcLbminfo);

		    mapLbminfo.insert(pair<string,vector<CLbminfo>>(vcStConfiginfo[i].m_strLbmid,*m_pvcLbminfo));
			m_pvcLbminfo->clear();
			
		 }		
	 }

	 void CreateKcxpconvFile(string sPath)
	 {
		 string strFilepath = sPath + "\\kcxpconv.xml";
		 TiXmlDocument *writeDoc = new TiXmlDocument(); //xml文档指针  

		 //文档格式声明  
		 TiXmlDeclaration *decl = new TiXmlDeclaration("1.0", "UTF-8", "yes");  
		 writeDoc->LinkEndChild(decl); //写入文档 

		 TiXmlElement *RootElement = new TiXmlElement("root");//根元素  
		 writeDoc->LinkEndChild(RootElement);  

		 for (map<string, vector<CLbminfo>>::iterator  itmap=mapLbminfo.begin();itmap!=mapLbminfo.end();itmap++)
		 {
			 TiXmlElement *StuElement = new TiXmlElement("lbm");//program  
			 //设置属性  
			 StuElement->SetAttribute("name",itmap->first.c_str()); 
			 StuElement->SetAttribute("descripe","");
			 RootElement->LinkEndChild(StuElement);//父节点写入文档

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