//My accepted code of Q1
#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;
int menu(void)
{
	cout << "链表通讯录　by落絮飞雁" << endl;
	cout << "#####################" << endl;
	cout << "添加请按0" << endl;
	cout << "删除请按1" << endl;
	cout << "查询请按2" << endl;
	cout << "退出请按3" << endl;
	cout << "请选择（0-3）" << endl;
	return 0;
}
class Addr
{
public:
	Addr(string Name, string Tele);
	~Addr();

	void PrintAddress(Addr *head);
	void InsertAddress(Addr *head);
	void DeleteAddress(Addr *head);
	Addr *next;//下一指针

private:
	string m_Name;
	string m_Tele;
};
Addr::Addr(string Name = "", string Tele = "") :
m_Name(Name), m_Tele(Tele){};
Addr::~Addr(){};
//新建
Addr* createlist(void)
{
	Addr*head;

	head = new Addr;
	if (!head)
	{
		exit(0);
	}
	head->next = NULL;

	return head;
}
void Addr::InsertAddress(Addr *head)
{
	Addr *p, *q;
	string name, tele;
	p = head;
	q = new Addr;
	if (p->next == NULL)
	{
		cout << "没人么么哒~请添加第一个联系人." << endl;
		//提示无联系人,并添加
		cout << "Name??";
		cin >> p->m_Name;
		cout << "tele??";
		cin >> p->m_Tele;
		p->next = q;
		q->next = NULL;
		p = p->next;
	}
	else
	{
		while (p->next)
		{
			p = p->next;
		}
		PrintAddress(head);
		cout << "姓名：";
		cin >> p->m_Name;
		cout << " 电话： ";
		cin >> p->m_Tele;
		p->next = q;
		q->next = NULL;
		p = p->next;
	}
}
void Addr::DeleteAddress(Addr*head)
{
	int i, n;
	Addr*p, *q;

	p = q = head;
	printf("要删除的序号？？\n");
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		p = q;
		q = q->next;
	}
	if (q)
	{
		p->next = q->next;
	}

}
void Addr::PrintAddress(Addr *head)
{
	Addr*p = head;
	int i = 1;
	printf("\n");
	while (p->next)
	{
		p = p->next;
		cout << i << ":" << p->m_Name << " " << p->m_Tele << endl;
		i++;
	}
}
int main(void)
{
	Addr *head;
	Addr num;
	int select;
	head = createlist();
	menu();
	while (~scanf("%d", &select))
	{
		switch (select)
		{
		case 0:
			num.InsertAddress(head);
			num.PrintAddress(head);
			break;
		case 1:
			num.DeleteAddress(head);
			num.PrintAddress(head);
			break;
		case 2:
			num.PrintAddress(head);
			break;
		}
	} while (0);
	{
		getchar();
	}
	return 0;
}