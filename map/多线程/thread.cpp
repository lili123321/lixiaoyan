#include<pthread.h>
#include <iostream>
#define NUM_THREADS 5  
using namespace std;

//int num=0;   //�����ȫ�ֱ������������߳̽��з��ʣ������ͻ����ͬʱд��������Ʊػ���Ҫ�����ƣ� 
//pthread_mutex_t  num_mutex;

int task=10;
pthread_mutex_t task_mutex;
pthread_cond_t  task_cond;

//�����ݿ�����һ����ע������ļ������ļ��������������,64λ�ĳ���ֻ����x64λ����
//����̵߳��õĺ�������һ��������ô�죿���ǽ��ú���д�ɾ�̬��Ա������

//void * say_hello(void* args)//�̵߳����к���������void*��û˵�ı�ʾ����ͨ��ָ�롢����ͨ��ָ��  
//{  
//    int i = *((int*)args);//�Դ���Ĳ�������ǿ������ת������������ָ���Ϊ������ָ�룬Ȼ���ٶ�ȡ��
//	cout << "hello  in "<<i<<endl;
//
//	pthread_mutex_lock(&num_mutex);   //�޸�sum���ȼ���������ռ�þ�������ֱ���õ������޸�sum��
//	cout<<"before sum  is"<<num<<endl;
//
//	num+=i;
//
//	cout<<"after sum  is"<<num<<endl;
//
//	pthread_mutex_unlock(&num_mutex);  //���º�������ͷŸ������߳�ʹ��;  
//
//	pthread_exit(0);  //�˳�����Ӹ�״̬��  
//
//
//
//	//int status=10+i;
//	//pthread_exit((void*)status);//�����̴߳���ʱ���ṩ��joinable����������������˳�ʱ����˳�����Ϣ��status����������ȡ���̵߳Ľ�����Ϣ��  
// //   return NULL;
//}  

void  * say_hello1(void * arg)  //<=5������
{

	pthread_t  pd= pthread_self();
	cout << " hello in thread1 " << *((int*)arg) << endl;
	while(1)
	{
		pthread_mutex_lock(&task_mutex);
		if (task>5)
		{
			cout << " pthread_cond_wait in thread1 " << *((int*)arg) << endl;  
			pthread_cond_wait(&task_cond, &task_mutex);//�ȴ��ź�����Ч����hello2�����źţ����������wait��ִ�к�����
		}

		else
		{
			cout << " take task1:  "<< task << " in thread "<< *((int*)arg) << endl;  
			--task;//<=5��--  
		}
        pthread_mutex_unlock(&task_mutex);

		if (task==0)
		 break;
	}

	return NULL;
}


void  * say_hello2(void * arg) >5������
{
   pthread_t  pd=pthread_self();
   cout << " hello2 in thread " << *((int*)arg) << endl; 

   bool is_signaled = false;//���һ����־λ  
   while(1)//����ѭ��  
   {  
	   pthread_mutex_lock(&task_mutex);//Ҫ�޸��ˣ�����  
	   if (task > 5)//>5���޸�  
	   {  
		   cout << " take task2:  "<< task << " in thread "<< *((int*)arg) << endl;  
		   --task;//����1  
	   }  
	   else if (!is_signaled)  
	   {  
		   cout << " pthread2_cond_signal in thread " << *((int*)arg) << endl;  
		   pthread_cond_signal(&task_cond);//�����Ѿ�����>5�˸���hello1����ȥ���������źţ�  
		   is_signaled = true;//��ʾ�ź��Ѿ�������  
	   }  
	   pthread_mutex_unlock(&task_mutex);//���������  

	   if (task == 0) 
		  break;//����ȴ�tasksȫ����Ϊ�㼴hello1��ɲ�����������ѭ�������������  
}
   return NULL;
}

int main()  
{  
	pthread_t tids[NUM_THREADS];//�����̵߳�id���������������������Ϊ����ʹ�� 
	int indexes[NUM_THREADS];
	
	pthread_attr_t  attr;         //Ҫ�봴��ʱ���������������  
	pthread_attr_init(&attr);     //�ٳ�ʼ�� 
    pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_JOINABLE);//��������ʼ���������������������Ҫָ���߳����Բ��������������������߳��ǿ���join���ӵģ�join���ܱ�ʾ��������Ե��߳̽�������ȥ��ĳ�£�ʵ������������߳�ͬ�����ܣ�������������ͨ��ͼʾ���ܽ��ͣ������������ϰ�  

	pthread_mutex_init(&task_mutex,NULL); // ����Ƕ������г�ʼ��������ģ� 
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
	//	//�����ʱ�����ǿ��ת��Ϊvoid* ���ͣ���������ָ�� 
	//	int ret = pthread_create(&tids[i], &attr, say_hello, (void*)&indexes[i]); //���������ǣ��������߳�id���̲߳��������ú�����������ĺ�������  
	//	//cout<< "Current pthread id ="<<i<<endl;//����ѧ��ʹ��tids�����ӡ�����Ľ���id��Ϣ��
	//	if (ret != 0)  
	//	{  
	//		cout << "pthread_create error: error_code=" << ret << endl;  
	//	}  

	//}  

	//pthread_attr_destroy(&attr);//����ʹ�����˾Ϳ��������ˣ���������Ŷ����ֹ�ڴ�й¶��

	//void  *status;

	//for (int i=0;i<NUM_THREADS;i++)
	//{
	//	int ret=pthread_join(tids[i],&status);;//ǰ�洴�����̣߳�������������Ҫjoinÿ���̺߳�ȡ��ÿ���̵߳��˳���Ϣstatus��

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
	//pthread_mutex_destroy(&num_mutex); ////ע���������Կ���ʹ��pthread���ñ�������Ķ���Ӧ�����ٺ������������ڴ�й¶��صİɣ�  
 // 
	//pthread_exit(NULL);//�ȸ����߳��˳��󣬽��̲Ž������������ǿ�ƽ����ˣ��߳̿��ܻ�û��Ӧ������  
}  