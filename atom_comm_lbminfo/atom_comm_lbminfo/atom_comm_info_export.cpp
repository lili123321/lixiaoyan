#include "atom_comm_info_export.h"
#include "infobase.h"

int  Createinfo(char* SenginePath,char* KcbpPath,char* OutputPath)
{   
	CInfoBase  objInfoBase;
	objInfoBase.run(SenginePath,KcbpPath,OutputPath);
    return 0;
}

int  GetbuildInfo(char* SenginePath)
{
    CInfoBase  objInfoBase;
	objInfoBase.getinfo(SenginePath);
	return 0;

}