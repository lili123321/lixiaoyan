#include <iostream.h>
void main()
{
	int n,r,c,m,j=0;
	cout<<"������������С��14����";
	cin>>m;
	while (m>=14)
	{
		if (j>=2)
		{
			cout<<"��Ĵ��������Ѵ�3�Σ�����Ȩ�����룡"<<endl;
		    return;
		}
		cout<<"�����������������Χ�����������룡"<<endl;
        cout<<"������������С��14����";
	    cin>>m;
		
		j++;
	}

		for (n=0;n<=m-1;n++)
		{
			for(r=1;r<15-n;r++)
				cout<<"  ";  //2
			c=1;
			cout<<c<<"   ";  //3
			for(r=1;r<=n;r++)
			{
				c=c*(n-r+1)/r;
				if (c<100)
					if(c<10) 
						cout<<c<<"   ";  //3
					else
						cout<<c<<"  ";  //2
				else
					cout<<c<<" ";  //1
			}
			cout<<endl;
		}
}
