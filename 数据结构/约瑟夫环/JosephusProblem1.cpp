struct ListNode
{
	int num;        //编号
	ListNode *next; //下一个
	ListNode(int n = 0, ListNode *p = NULL) 
	{ num = n; next = p;}
};

//自定义链表实现
int JosephusProblem_Solution1(int n, int m)
{
	if(n < 1 || m < 1)
		return -1;

	ListNode *pHead = new ListNode(); //头结点
	ListNode *pCurrentNode = pHead;   //当前结点
	ListNode *pLastNode = NULL;       //前一个结点
	unsigned i;

	//构造环链表
	for(i = 1; i < n; i++)
	{
		pCurrentNode->next = new ListNode(i);
		pCurrentNode = pCurrentNode->next;
	}
	pCurrentNode->next = pHead;

	//循环遍历
	pLastNode = pCurrentNode;
	pCurrentNode = pHead;

	while(pCurrentNode->next != pCurrentNode)
	{
		//前进m - 1步
		for(i = 0; i < m-1; i++)
		{
			pLastNode = pCurrentNode;
			pCurrentNode = pCurrentNode->next;
		}
		//删除报到m - 1的数
		pLastNode->next = pCurrentNode->next;
		delete pCurrentNode;
		pCurrentNode = pLastNode->next;
	}
	//释放空间
	int result = pCurrentNode->num;
	delete pCurrentNode;

	return result;
}
