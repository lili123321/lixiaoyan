class CSingleton  
{  
private:  
	CSingleton()   //���캯����˽�е�  
	{  
	}  
	static CSingleton *m_pInstance;  
public:  
	static CSingleton * GetInstance()  
	{  
		if(m_pInstance == NULL)  //�ж��Ƿ��һ�ε���  
			m_pInstance = new CSingleton();  
		return m_pInstance;  
	}  
};  