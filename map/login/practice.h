using namespace std;
class Aa
{
public:
	void encrypt(string s, int size,string s1, int size1)
   {
	if(size<0||size1<size)
		cout<<"×Ö·û´®ÊäÈëÓÐÎó";

	else
	{
		for(int i=0;i<size;i++)
		{
			char c=s.at(i)+0+10;
			s1+=c;
		
		}
	

	}
	
	}

protected:  
	  string s;
	  int size;
	  string s1;
	  int size1;

};
