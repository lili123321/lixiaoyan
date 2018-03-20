#include "Solution.h"
#include <iostream>
int  main()
{
	/*给定两个字符串，请设计一个方法来判定其中一个字符串是否为另一个字符串的置换。
	置换的意思是，通过改变顺序可以使得两个字符串相等。*/
   
	Solution  s;
   string a="abcd";
   string b="bcad";
   bool l=s.Permutation(a,b);
   cout<<l<<endl;

}