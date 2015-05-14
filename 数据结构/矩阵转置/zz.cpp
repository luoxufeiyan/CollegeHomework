#include<stdio.h>
#include<string.h>
int N1, N2;
int main()
{
	int a[100][100], b[100][100], i, j;
	scanf("%d%d", &N1, &N2);
	for (i = 0; i<N1; i++)
	for (j = 0; j<N2; j++)
		scanf("%d", &a[i][j]);
	printf("\n");
	for (i = 0; i<N2; i++)
	{
		for (j = 0; j<N1; j++)
		{
			b[i][j] = a[j][i];
			printf("%d\t", b[i][j]);
		}
		printf("\n");
	}
	getchar();
	return 0;
}