#include <iostream>
using namespace std;
void func(int a);
int main()
{
	const int a=2;
	char b[a]="e";
    func(a);
}

void func(int a)
{
	cout<<a<<endl;
}