#include<Windows.h>
#include<stdio.h>
#include<iostream>
#include<time.h>

#define TEST_SIZE (1024*1024*200)
#define NUMBER 20


typedef struct _search{
	int *date;//搜索数据集
	size_t star;//搜索开始位置
	size_t end;//搜索结束位置
	size_t count;


}search;
DWORD WINAPI ThreaProc(void *ipParam){

	search *s = (search *)ipParam;
	time_t star,end;

	time(&star);

	for(int i=0;i<10;i++){
		for(int i=s->star;i<s->end;i++){
	
		if(s->date[i]==NUMBER) s->count++;


		}
	}

	time(&end);

	printf("查找时间%ds\n",end-star);

	return 0;

}


int main(void){
	DWORD threadID1;//线程1的身份证
	HANDLE hThread1;//线程1发句柄

	DWORD threadID2;//线程2的身份证
	HANDLE hThread2;//线程2的句柄

	int *date = NULL;
	int count = 0;//记录数据的数量
	
	date = new int [TEST_SIZE];

	for(int i=0;i<TEST_SIZE;i++){
		date[i] = i;
	}
	



	search s1,s2;

	s1.date = date;
	s1.star = 0;
	s1.end = TEST_SIZE/3;
	s1.count = 0;

	s2.date = date;
	s2.star = 1+TEST_SIZE/3;
	s2.end = TEST_SIZE-1;
	s2.count = 0;




	printf("创建线程......\n");
	//创建线程1
	//CreateThread(线程属性，线程堆栈大小,线程启动后要执行的代码(定义函数),传递的参数(NULL),线程标志,线程的id)

	hThread1 = CreateThread (NULL,0,ThreaProc,&s1,0,&threadID1);

	//创建线程2
	hThread2 = CreateThread(NULL,0,ThreaProc,&s2,0,&threadID2);
	
	WaitForSingleObject(hThread1,INFINITE);
	WaitForSingleObject(hThread2,INFINITE);

	printf("查找元素20个数:%d\n",s1.count+s2.count);
	printf("进程老爸欢迎线程归来!\n");

	system("pause");
	return 0;
}


int main01(void){//串行
	int *date = NULL;
	int count = 0;//记录数据的数量
	
	date = new int [TEST_SIZE];

	for(int i=0;i<TEST_SIZE;i++){
		date[i] = i;
	}
	
	time_t star = 0;
	time_t end = 0;

	time(&star);

	for(int i=0;i<10;i++){
	for(int i=0;i<TEST_SIZE;i++){
		if(date[i]==NUMBER) count++;


		}
	}

	time(&end);

	printf("查找所花的时间为%ds\n",end-star);
	system("pause");
	return 0;
}