// My accepted code of Q2
#include <stdlib.h>
#include <iostream>//C++
//#include<stdio.c>
#include <stdarg.h>
using namespace std;


typedef struct _LinkNode //开链表
{
	int value;//值
	struct _LinkNode* next;
}LinkNode, *LinkNodePtr;//Ptr==Pointer

LinkNodePtr createCycle(int total)//创建循环
{
	int index = 1;//初始化目录为1
	LinkNodePtr head = NULL, curr = NULL, prev = NULL;//链表初始化
	head = (LinkNodePtr)malloc(sizeof(LinkNode));
	head->value = index;
	prev = head;//循环

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
	//LinkNodePtr prev = NULL;//初始化
	int start = 1;
	int index = start;
	while (node && node->next)
	{
		if (index == tag)//找到了某小朋友
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
		cout << "请输入初始序号，退出按1" << endl;
		//cin >> peo;
		scanf("%d",&peo);
		if (peo == 1)
			break;
		else if (peo < 1)
		{
			cout << "输入不合法，必须要输入大于一的正整数" << endl;
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
