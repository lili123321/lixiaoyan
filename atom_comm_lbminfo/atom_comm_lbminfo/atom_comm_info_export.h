#include <iostream>
using namespace  std;
#ifdef __cplusplus
extern "C" {
#endif
	__declspec(dllexport) int  Createinfo(char* SenginePath,char* KcbpPath,char* OutputPath);//type = 0ֻ����kcxpconv.xml,1����sys_lbmin.sql, 2ȫ������
	__declspec(dllexport) int  GetbuildInfo(char* SenginePath);

#ifdef __cplusplus
}
#endif