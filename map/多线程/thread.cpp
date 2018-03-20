#include<pthread.h>
#include <iostream>
#define NUM_THREADS 5  
using namespace std;

//int num=0;   //定义个全局变量，让所有线程进行访问，这样就会出现同时写的情况，势必会需要锁机制； 
//pthread_mutex_t  num_mutex;

int task=10;
pthread_mutex_t task_mutex;
pthread_cond_t  task_cond;

//和数据库连接一样，注意包含文件、库文件、依赖项的配置,64位的程序只能用x64位编译
//如果线程调用的函数是在一个类中怎么办？答案是将该函数写成静态成员函数，

//void * say_hello(void* args)//线程的运行函数，必须void*，没说的表示返回通用指针、输入通用指针  
//{  
//    int i = *((int*)args);//对传入的参数进行强制类型转换，由无类型指针变为整形数指针，然后再读取；
//	cout << "hello  in "<<i<<endl;
//
//	pthread_mutex_lock(&num_mutex);   //修改sum就先加锁，锁被占用就阻塞，直到拿到锁再修改sum；
//	cout<<"before sum  is"<<num<<endl;
//
//	num+=i;
//
//	cout<<"after sum  is"<<num<<endl;
//
//	pthread_mutex_unlock(&num_mutex);  //完事后解锁，释放给其他线程使用;  
//
//	pthread_exit(0);  //退出随便扔个状态码  
//
//
//
//	//int status=10+i;
//	//pthread_exit((void*)status);//由于线程创建时候提供了joinable参数，这里可以在退出时添加退出的信息：status供主程序提取该线程的结束信息；  
// //   return NULL;
//}  

void  * say_hello1(void * arg)  //<=5处理函数
{

	pthread_t  pd= pthread_self();
	cout << " hello in thread1 " << *((int*)arg) << endl;
	while(1)
	{
		pthread_mutex_lock(&task_mutex);
		if (task>5)
		{
			cout << " pthread_cond_wait in thread1 " << *((int*)arg) << endl;  
			pthread_cond_wait(&task_cond, &task_mutex);//等待信号量生效，当hello2发出信号，这里就跳出wait，执行后续；
		}

		else
		{
			cout << " take task1:  "<< task << " in thread "<< *((int*)arg) << endl;  
			--task;//<=5就--  
		}
        pthread_mutex_unlock(&task_mutex);

		if (task==0)
		 break;
	}

	return NULL;
}


void  * say_hello2(void * arg) >5处理函数
{
   pthread_t  pd=pthread_self();
   cout << " hello2 in thread " << *((int*)arg) << endl; 

   bool is_signaled = false;//随便一个标志位  
   while(1)//无限循环  
   {  
	   pthread_mutex_lock(&task_mutex);//要修改了，加锁  
	   if (task > 5)//>5才修改  
	   {  
		   cout << " take task2:  "<< task << " in thread "<< *((int*)arg) << endl;  
		   --task;//减少1  
	   }  
	   else if (!is_signaled)  
	   {  
		   cout << " pthread2_cond_signal in thread " << *((int*)arg) << endl;  
		   pthread_cond_signal(&task_cond);//表明已经不是>5了告诉hello1进程去处理：发送信号；  
		   is_signaled = true;//表示信号已经发送了  
	   }  
	   pthread_mutex_unlock(&task_mutex);//操作完解锁  

	   if (task == 0) 
		  break;//必须等待tasks全部减为零即hello1完成操作，才跳出循环结束这个进程  
}
   return NULL;
}

int main()  
{  
	pthread_t tids[NUM_THREADS];//定义线程的id变量，多个变量可以声明为数组使用 
	int indexes[NUM_THREADS];
	
	pthread_attr_t  attr;         //要想创建时加入参数，先声明  
	pthread_attr_init(&attr);     //再初始化 
    pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_JOINABLE);//声明、初始化后第三步就是设置你想要指定线程属性参数，这个参数表明这个线程是可以join连接的，join功能表示主程序可以等线程结束后再去做某事，实现了主程序和线程同步功能，这个深层理解必须通过图示才能解释；参阅其他资料吧  

	pthread_mutex_init(&task_mutex,NULL); // 这句是对锁进行初始化，必须的； 
	pthread_cond_init(&task_cond,NULL);

	pthread_t i1,i2;

	int index1=1;

	int ret=pthread_create(&i1,&attr,say_hello1,(void *)&index1);

	if (ret != 0)  
	{  
	  cout << "pthread_create error: error_code=" << ret << endl;  
	}  

	int index2=2;

	ret=pthread_create(&i2,&attr,say_hello2,(void *)&index2);

	if (ret != 0)  
	{  
		cout << "pthread_create error: error_code=" << ret << endl;  
	}  

	pthread_join(i1,NULL);
	pthread_join(i2,NULL);

	pthread_mutex_destroy(&task_mutex);
	pthread_cond_destroy(&task_cond);



	//for(int i = 0; i < NUM_THREADS; ++i)  
	//{  
	//	indexes[i]=i;
	//	//传入的时候必须强制转换为void* 类型，即无类型指针 
	//	int ret = pthread_create(&tids[i], &attr, say_hello, (void*)&indexes[i]); //参数依次是：创建的线程id，线程参数，调用函数名，传入的函数参数  
	//	//cout<< "Current pthread id ="<<i<<endl;//这里学会使用tids数组打印创建的进程id信息；
	//	if (ret != 0)  
	//	{  
	//		cout << "pthread_create error: error_code=" << ret << endl;  
	//	}  

	//}  

	//pthread_attr_destroy(&attr);//参数使用完了就可以销毁了，必须销毁哦，防止内存泄露；

	//void  *status;

	//for (int i=0;i<NUM_THREADS;i++)
	//{
	//	int ret=pthread_join(tids[i],&status);;//前面创建了线程，这里主程序想要join每个线程后取得每个线程的退出信息status；

	//	if (ret != 0)  
	//	{  
	//		cout << "pthread_join error: error_code=" << ret << endl;  
	//	}  
	//	/*else  
	//	{  
	//		cout << "pthread_join get status: " << (long)status << endl;  
	//	}  */
	//}

	//cout<<"finally  sum  is"<<num<<endl;
	//
	//pthread_mutex_destroy(&num_mutex); ////注销锁，可以看出使用pthread内置变量神马的都对应了销毁函数，估计是内存泄露相关的吧；  
 // 
	//pthread_exit(NULL);//等各个线程退出后，进程才结束，否则进程强制结束了，线程可能还没反应过来；  
}  