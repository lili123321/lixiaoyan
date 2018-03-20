#include<vector>
#include <map>
#include <iostream>
using namespace std;

class Solution {
public:
    /*
     * @param words: A list of words
     * @return: Return how many different rotate words
     */
    int countRotateWords(vector<string> words) 
	{
		vector<map<char,int>>n;
		map<char,int>m;
		map<char,int>::iterator itmap;
		map<map<char,int>,int>t;
		map<map<char,int>,int>::iterator tmap;
		for (int i=0;i<words.size();i++)
		{
			m.clear();
            for (int j=0;j<words[i].size();j++)
            {     
               itmap=m.find(words[i][j]);
			   if (itmap==m.end())
			   {
				   m.insert(pair<char,int>(words[i][j],1));
			   }
			   else
			   {
				   itmap->second ++;
			   }
			
			  
            }   
			 n.push_back(m);
		}
		for(int i=0;i<n.size();i++)
		{
            tmap=t.find(n[i]);
			if (tmap==t.end())
			{
				t.insert(pair<map<char,int>,int>(n[i],1));
			}
			else
			{
                tmap->second ++;
			}
			
		}
		 return  t.size();

    }
};