//My accepted code of Q1
#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;
int menu(void)
{
	cout << "����ͨѶ¼��by��������" << endl;
	cout << "#####################" << endl;
	cout << "����밴0" << endl;
	cout << "ɾ���밴1" << endl;
	cout << "��ѯ�밴2" << endl;
	cout << "�˳��밴3" << endl;
	cout << "��ѡ��0-3��" << endl;
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
	Addr *next;//��һָ��

private:
	string m_Name;
	string m_Tele;
};
Addr::Addr(string Name = "", string Tele = "") :
m_Name(Name), m_Tele(Tele){};
Addr::~Addr(){};
//�½�
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
		cout << "û��ôô��~����ӵ�һ����ϵ��." << endl;
		//��ʾ����ϵ��,�����
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
		cout << "������";
		cin >> p->m_Name;
		cout << " �绰�� ";
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
	printf("Ҫɾ������ţ���\n");
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