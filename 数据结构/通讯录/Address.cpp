#include<iostream>
#include<cstring>
using namespace std;
int menu(void)
{
	cout << "����밴1" << endl;
	cout << "ɾ���밴2" << endl;
	cout << "��ѯ�밴3" << endl;
	cout << "�Ƴ��밴4" << endl;
	cout << "��ѡ��1-4��" << endl;
	return 0��
}
class Addr
{
public:
	Addr(string Name, string Tele);
	~Addr();

	void PrintAddress(Addr *head);
	void InsertAddress(Addr *head);
	void DeleteAddress(Addr *head);
	Addr *nest;

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
	head->nest = NULL;
	
	return head;
}
void Addr::InsertAddress(Addr *head)
{
	Addr *p, *q;//��ָ��
	string name, tele;
	p = head;
	q = new Addr;
	if (p->next == NULL)
	{
		cout << "û�����ôô��~" << endl;
		//ֻ��ʾ����ϵ�ˣ��£գǣ���
	}
}