#include<occi.h>
#include<iostream> 

using namespace std;
using namespace oracle::occi; 

const string username = "kpms"; 
const string password = "kpms"; 
const string connstr = "//127.0.0.1:1521/orcl"; 

//ע������ļ������ļ��������������

int main()
{
	try
	{
		//�����δ����ǵ���OCCI�Ļ���������OCCI�����Ļ��� ���������ӣ����Ҵ���һ��Statement�������ݿ���в�����
		Environment *env = Environment::createEnvironment(Environment::DEFAULT); 
		Connection *conn = env->createConnection(username,password,connstr); 
		//Environment::terminateConnection()�Ͽ�����  Statement������ִ��SQL/PLSQL���,����ȡ���ؽ���� ResultSet �����ڴ���SELECT ��ѯ�Ľ����
	   
		/*Statement::setSQL(string &sql);
          Statement::execute(string &sql);       - can be used for any SQL, returnsstatusһ��SQL��䣬create\insert
          Statement::executeUpdate(string &sql); - returns Insert/Update/Delete count
          Statement::executeQuery(string &sql);  - returns ResultSet���������*/

		//�޲������÷�
		//Statement *stmt=conn->createStatement();//��Statement����
		//string  sql = "select *  from projectasset";
		//stmt->execute(sql);

		//�в������÷�
		string  sq="select * from fundacct where brokerid=:3";
		Statement  * st=conn->createStatement(sq);
		st->setInt(1,1000);
		ResultSet *rs=st->executeQuery();   //���createstatement����sql,��˴����ٰ�sq,����ᱨ��
		while (rs->next())
		{
			string isno= rs->getString(7); ////ȡ����һ�е�ֵ����ӦΪstring�ͣ�
		    //string date = mResultSet->getDate(1).toText("YYYYMMDD")//ת����stringʱ�����ṩʱ���ַ�����ʽ��
			cout<<isno<<endl;
		}

	} 
	catch(SQLException &ex) 
	{
		cout << ex.what() << endl;
	}
	return 0;
}