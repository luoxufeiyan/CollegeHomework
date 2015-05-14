// My accepted code of Q2
#include <stdlib.h>
#include <iostream>
#include <stdarg.h>
using namespace std;

typedef struct _LinkNode //开链表
{
	int value;
	struct _LinkNode* next;
}LinkNode, *LinkNodePtr;

LinkNodePtr createCycle(int total)
{
	int index = 1;
	LinkNodePtr head = NULL, curr = NULL, prev = NULL;//链表初始化
	head = (LinkNodePtr)malloc(sizeof(LinkNode));
	head->value = index;
	prev = head;

	while (--total > 0)//判断满链表？
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
	LinkNodePtr prev = NULL;
	int start = 1;
	int index = start;
	while (node && node->next)
	{
		if (index == tag)
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
	while (1)
	{
		cout << "请输入初始序号，退出按1么么哒~" << endl;
		cin >> peo;
		if (peo == 1)
			break;
		else if (peo < 1)
		{
			cout << "输入不合法，必须要输入大于一的正整数呀~" << endl;
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
