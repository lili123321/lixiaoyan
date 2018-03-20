#include<iostream.h>
#include<iomanip.h>
#include<time.h>
const unsigned long maxshort=65536L;
const unsigned long multiplier=1194211693L;
const unsigned long adder=12345;

class RandomNumber
{
private:
	unsigned long randSeed;
public:
	RandomNumber(unsigned long s=0);
	unsigned short Random(unsigned long n);
	double fRandom(void);
};

RandomNumber::RandomNumber(unsigned long s)
{
	if (s==0)
		randSeed=time(0);
	else
		randSeed=s;
}
unsigned short RandomNumber::Random(unsigned long n)
{
	randSeed=multiplier*randSeed+adder;
	return (unsigned short)((randSeed>>16)%n);
}
double RandomNumber::fRandom(void)
{
	return Random(maxshort)/double(maxshort);
}

int TossCoins(int numberCoins)  //ģ����Ӳ�ҵõ��������¼�Ƶ��
{
	static RandomNumber coinToss;
	int i,tosses=0;
	for(i=0;i<numberCoins;i++)
		tosses+=coinToss.Random(2);
	return tosses;
}

void main(void)
{
	const int NCOINS=10;
	const long NTOSSES=100000L;
	long i,heads[NCOINS+1];  //heads[i]���ÿһ�¼��õ�����Ĵ���
	int j,position;
	for(j=0;j<NCOINS+1;j++)
		heads[j]=0;  //��ʼ��
	for(i=0;i<NTOSSES;i++)  //�ظ��¼�NTOSSES��
		heads[TossCoins(NCOINS)]++;
	for(i=0;i<=NCOINS;i++)  //���Ƶ��ͼ
	{
		position=int(float(heads[i])/NTOSSES*100);
		cout<<setw(6)<<i<<" ";
		for(j=0;j<position-1;j++)
			cout<<" ";
		cout<<"*"<<endl;
	}
}
