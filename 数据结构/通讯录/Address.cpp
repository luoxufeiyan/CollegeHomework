#include<iostream>
#include<cstring>
using namespace std;
int menu(void)
{
	cout << "添加请按1" << endl;
	cout << "删除请按2" << endl;
	cout << "查询请按3" << endl;
	cout << "推出请按4" << endl;
	cout << "请选择（1-4）" << endl;
	return 0；
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
//新建
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
	Addr *p, *q;//两指针
	string name, tele;
	p = head;
	q = new Addr;
	if (p->next == NULL)
	{
		cout << "没这个人么么哒~" << endl;
		//只提示无联系人，ＢＵＧ？？
	}
}