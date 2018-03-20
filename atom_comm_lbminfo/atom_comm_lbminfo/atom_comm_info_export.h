#include <iostream>
using namespace  std;
#ifdef __cplusplus
extern "C" {
#endif
	__declspec(dllexport) int  Createinfo(char* SenginePath,char* KcbpPath,char* OutputPath);//type = 0只生成kcxpconv.xml,1生成sys_lbmin.sql, 2全部生成
	__declspec(dllexport) int  GetbuildInfo(char* SenginePath);

#ifdef __cplusplus
}
#endif