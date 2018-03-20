#include <crtdbg.h>
#include<iostream>
using namespace std;
int main()
{
  int * p=new int;
  _CrtDumpMemoryLeaks();
};