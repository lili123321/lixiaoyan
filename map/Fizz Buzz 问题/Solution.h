#include <string>
#include <vector>
#include<sstream>
using namespace std;

class Solution 
{
public:
    /*
     * @param n: An integer
     * @return: A list of strings.
     */
    vector<string> fizzBuzz(int n) 
    {
       vector<string> s(n);
	   char str[10];
       for(int i=1;i<=n;i++)
       {
           if(i%3==0 && i%5!=0)
            s[i-1]="fizz";
           
           else if(i%5==0 && i%3!=0)
            s[i-1]="buzz";
            
           else if(i%3==0 && i%5==0)
            s[i-1]="fizz buzz";
            
           else
		   {  
			   //整形转换成字符串
			   //itoa(i,str,10);
               //s[i-1]=string(str);

			   stringstream ss;
			   ss << i; 
			   string st = ss.str();
			   s[i-1]=st;
		   }
           
       }
       
       return s;
    }
};