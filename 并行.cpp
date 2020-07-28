#include<Windows.h>
#include<stdio.h>
#include<iostream>
#include<time.h>

#define TEST_SIZE (1024*1024*200)
#define NUMBER 20


typedef struct _search{
	int *date;//�������ݼ�
	size_t star;//������ʼλ��
	size_t end;//��������λ��
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

	printf("����ʱ��%ds\n",end-star);

	return 0;

}


int main(void){
	DWORD threadID1;//�߳�1�����֤
	HANDLE hThread1;//�߳�1�����

	DWORD threadID2;//�߳�2�����֤
	HANDLE hThread2;//�߳�2�ľ��

	int *date = NULL;
	int count = 0;//��¼���ݵ�����
	
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




	printf("�����߳�......\n");
	//�����߳�1
	//CreateThread(�߳����ԣ��̶߳�ջ��С,�߳�������Ҫִ�еĴ���(���庯��),���ݵĲ���(NULL),�̱߳�־,�̵߳�id)

	hThread1 = CreateThread (NULL,0,ThreaProc,&s1,0,&threadID1);

	//�����߳�2
	hThread2 = CreateThread(NULL,0,ThreaProc,&s2,0,&threadID2);
	
	WaitForSingleObject(hThread1,INFINITE);
	WaitForSingleObject(hThread2,INFINITE);

	printf("����Ԫ��20����:%d\n",s1.count+s2.count);
	printf("�����ϰֻ�ӭ�̹߳���!\n");

	system("pause");
	return 0;
}


int main01(void){//����
	int *date = NULL;
	int count = 0;//��¼���ݵ�����
	
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

	printf("����������ʱ��Ϊ%ds\n",end-star);
	system("pause");
	return 0;
}