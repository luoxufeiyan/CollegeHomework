#include<stdio.h>

//typedef int int;       

typedef struct
{
	int i, j;               
	int e;
}Triple;                    

typedef struct
{
	Triple data[10001]; 
	int n, m, t;        
}Matrix;                


void Inst(Matrix &a)
{
	int i, j;
	int tmp;
	printf("请输入当前矩阵的行列数，以空格分开哦。\n");
	scanf("%d%d", &a.n, &a.m);
	a.t = 0;
	for (i = 1; i <= a.n; i++)
	{
		for (j = 1; j <= a.m; j++)
		{
			printf("请输入矩阵 %d 行 %d 列 元素的值，回车键结束哦。\n", i, j);
			scanf("%d", &tmp);
			if (tmp)
			{
				a.t++;
				a.data[a.t].i = i;
				a.data[a.t].j = j;
				a.data[a.t].e = tmp;
			}
		}
	}
}


void Trans(Matrix a, Matrix &b)
{
int num[10001] = { 0 }, pos[10001] = { 0 };
	int i, j, p;

	b.n = a.m; b.m = a.n; b.t = a.t;//行列转换

	for (i = 1; i <= a.t; i++) num[a.data[i].j]++;
	for (i = 1; i <= a.m; i++) pos[i] = pos[i - 1] + num[i];
	for (i = a.t; i >= 1; i--)
	{
		p = pos[a.data[i].j]--;
		b.data[p].i = a.data[i].j;
		b.data[p].j = a.data[i].i;
		b.data[p].e = a.data[i].e;
	}
}

void Out(Matrix a)
{
	int i, j;
	int u = 1;
	printf("矩阵转置的结果为\n");
	for (i = 1; i <= a.n; i++)
	{
		for (j = 1; j <= a.m; j++)
		if (i == a.data[u].i && j == a.data[u].j) printf("%d ", a.data[u++].e);
		else printf("0 ");
		printf("\n");
	}
	printf("\n");
	printf("输出完毕，棒棒哒~\n\n");
}

int main()
{
	Matrix a, b;
	printf("=====矩阵转置 By：落絮飞雁=====\n");
	while (1)
	{
		Inst(a);
		Trans(a, b);
		Out(b);
	}
	return 0;
}
