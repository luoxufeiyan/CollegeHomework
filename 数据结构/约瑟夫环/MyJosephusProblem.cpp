// My accepted code of Q2
#include <stdlib.h>
#include <iostream>//C++
//#include<stdio.c>
#include <stdarg.h>
using namespace std;


typedef struct _LinkNode //������
{
	int value;//ֵ
	struct _LinkNode* next;
}LinkNode, *LinkNodePtr;//Ptr==Pointer

LinkNodePtr createCycle(int total)//����ѭ��
{
	int index = 1;//��ʼ��Ŀ¼Ϊ1
	LinkNodePtr head = NULL, curr = NULL, prev = NULL;//�����ʼ��
	head = (LinkNodePtr)malloc(sizeof(LinkNode));
	head->value = index;
	prev = head;//ѭ��

	while (--total > 0)// total--
	{
		curr = (LinkNodePtr)malloc(sizeof(LinkNode));
		curr->value = ++index;
		prev->next = curr;
		prev = curr;
	}
	curr->next = head;
	return head;
}

void run(int total, int tag)
{
	LinkNodePtr node = createCycle(total);
	//total;
	//LinkNodePtr prev = NULL;//��ʼ��
	int start = 1;
	int index = start;
	while (node && node->next)
	{
		if (index == tag)//�ҵ���ĳС����
		{
			printf("\n%d", node->value);
			if (tag == start)
			{
				prev = node->next;
				node->next = NULL;
				node = prev;
			}
			else
			{
				prev->next = node->next;
				node->next = NULL;
				node = prev->next;
			}
			index = start;
		}
		else
		{
			prev = node;
			node = node->next;
			index++;
		}
	}
}
int main(int argc, char* argv[])
{
	int peo;
	int i=1;
	while (1)
	{
		cout << "�������ʼ��ţ��˳���1" << endl;
		//cin >> peo;
		scanf("%d",&peo);
		if (peo == 1)
			break;
		else if (peo < 1)
		{
			cout << "���벻�Ϸ�������Ҫ�������һ��������" << endl;
			continue;
		}
		else
		{
			run(peo, 999999);
			printf("\n");
		}
	}
	return 0;
}
