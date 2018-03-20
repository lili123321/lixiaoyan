class CSingleton  
{  
private:  
	CSingleton()   //构造函数是私有的  
	{  
	}  
	static CSingleton *m_pInstance;  
public:  
	static CSingleton * GetInstance()  
	{  
		if(m_pInstance == NULL)  //判断是否第一次调用  
			m_pInstance = new CSingleton();  
		return m_pInstance;  
	}  
};  