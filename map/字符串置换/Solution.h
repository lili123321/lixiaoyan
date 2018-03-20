#include <string>
#include <map>
using namespace std;

class Solution 
{
public:
    /*
     * @param A: a string
     * @param B: a string
     * @return: a boolean
     */
    bool Permutation(string&A, string &B) 
	{
		map<char,int>a;
		map<char,int>b;
		map<char,int>::iterator itmap;
		if (A.size()==B.size())
		{
			for(int i=0;i<A.size();i++)
			{
			    itmap =a.find(A[i]);
				if(itmap==a.end())
					a.insert(pair<char,int>(A[i],1));
				else
					itmap->second++;

			}

			for (int i=0;i<B.size();i++)
			{
				itmap =b.find(B[i]);
				if(itmap==b.end())
					b.insert(pair<char,int>(B[i],1));
				else
					itmap->second++;
			}

			for (itmap=a.begin();itmap!=a.end();itmap++)
			{
				map<char,int>::iterator tmap;
				tmap=b.find(itmap->first);
				if(tmap==b.end()||(tmap!=b.end()&&tmap->second!=itmap->second))
					return false;

			}
			
		}   
		else
		{
			return  false;
		}
		
       
		return true;
	}
};