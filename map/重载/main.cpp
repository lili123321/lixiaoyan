#include <iostream>
#include "opreator.h"
using namespace std;
int main()
{
   Person  s1;
   Person  s(50);
   s1=s;
   int weight=s1.Getweight();
   cout<<weight<<endl;
}