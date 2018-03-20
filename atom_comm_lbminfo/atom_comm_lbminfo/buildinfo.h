class CBuildInfo
{
 public:
    CBuildInfo()
	{
		sProjectName[0]='0';
		sResource[0]='0';
		sPlatform[0]='0';
		sBuildStatus[0]='0';

	}
  string sProjectName;
  string sPlatform;
  string sResource;
  string sBuildStatus;

};