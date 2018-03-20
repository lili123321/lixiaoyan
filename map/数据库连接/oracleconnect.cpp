#include<occi.h>
#include<iostream> 

using namespace std;
using namespace oracle::occi; 

const string username = "kpms"; 
const string password = "kpms"; 
const string connstr = "//127.0.0.1:1521/orcl"; 

//注意包含文件、库文件、依赖项的配置

int main()
{
	try
	{
		//这三段代码是调用OCCI的基础，创建OCCI上下文环境 ，建立连接，并且创造一个Statement来对数据库进行操作。
		Environment *env = Environment::createEnvironment(Environment::DEFAULT); 
		Connection *conn = env->createConnection(username,password,connstr); 
		//Environment::terminateConnection()断开连接  Statement类用于执行SQL/PLSQL语句,并获取返回结果。 ResultSet 类用于处理SELECT 查询的结果。
	   
		/*Statement::setSQL(string &sql);
          Statement::execute(string &sql);       - can be used for any SQL, returnsstatus一般SQL语句，create\insert
          Statement::executeUpdate(string &sql); - returns Insert/Update/Delete count
          Statement::executeQuery(string &sql);  - returns ResultSet（结果集）*/

		//无参数绑定用法
		//Statement *stmt=conn->createStatement();//创Statement对象
		//string  sql = "select *  from projectasset";
		//stmt->execute(sql);

		//有参数绑定用法
		string  sq="select * from fundacct where brokerid=:3";
		Statement  * st=conn->createStatement(sq);
		st->setInt(1,1000);
		ResultSet *rs=st->executeQuery();   //如果createstatement绑定了sql,则此处不再绑定sq,否则会报错
		while (rs->next())
		{
			string isno= rs->getString(7); ////取出第一列的值（对应为string型）
		    //string date = mResultSet->getDate(1).toText("YYYYMMDD")//转化成string时可以提供时间字符串格式。
			cout<<isno<<endl;
		}

	} 
	catch(SQLException &ex) 
	{
		cout << ex.what() << endl;
	}
	return 0;
}