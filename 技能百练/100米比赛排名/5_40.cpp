#include <iostream.h>
#include <iomanip.h>
struct sport		//�ṹ�����������ṹʱ�������ڴ�ռ䣩
{
	char num[4];	//���ݳ�Ա1���ṹ�а��������ݱ�����Ϊ���ݳ�Ա��
	double grade;	//���ݳ�Ա2
};					//����ȱ�ٷֺ�

void main()
{
sport a[12]={{"001",13.6},{"002",14.8},{"010",12.0},
			{"011",12.7},{"023",15.6},{"025",13.4},
			{"031",14.9},{"036",12.6},{"037",13.4},
			{"102",12.5},{"325",15.3},{"438",12.7}}; //�ṹ����Ķ���ͳ�ʼ��
	sport temp;
	int i,j;
	int row=12,col=3;
	
	for(i=1;i<row;i++)  //"ð��"����
		for(j=0;j<row-i;j++)
		{
			if (a[j].grade>a[j+1].grade)
			{
				temp=a[j];			//�ṹ����������Ի��ำֵ
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	
	cout<<setw(6)<<"����"<<setw(6)<<"���"<<setw(6)<<"�ɼ�"<<endl;
	for(i=0;i<row;i++)
	cout<<setw(6)<<(i+1)<<setw(6)<<a[i].num<<setw(6)<<a[i].grade<<endl;
	
}
