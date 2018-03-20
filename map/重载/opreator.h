class Person
{
public: 
	Person(){};
	
	Person(int wt)
	{
     weight=wt;
	}
	void operator =(const Person & p1)
	{
        weight=p1.weight+100; 
	}
	int  Getweight()
	{
		return this->weight;
	}


private:
	int weight;
	int height;
	bool gendar;
};
