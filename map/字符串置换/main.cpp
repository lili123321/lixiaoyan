#include "Solution.h"
#include <iostream>
int  main()
{
	/*���������ַ����������һ���������ж�����һ���ַ����Ƿ�Ϊ��һ���ַ������û���
	�û�����˼�ǣ�ͨ���ı�˳�����ʹ�������ַ�����ȡ�*/
   
	Solution  s;
   string a="abcd";
   string b="bcad";
   bool l=s.Permutation(a,b);
   cout<<l<<endl;

}