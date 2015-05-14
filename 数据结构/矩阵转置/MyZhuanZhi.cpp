#include<stdio.h>
#include<malloc.h>
#define MAXSIZE 100
typedef struct {
  int i,j;
  int e;
}Triple; //开三元组
typedef struct{
  Triple data[MAXSIZE+1];
  int mu,nu,tu;
} SanYuanZu;//三元组信息

int a,b;

SanYuanZu * creatarray(SanYuanZu *M)
{ int m,n,p=1;
  int c;
  printf("please input the array A:\n");
  for(m=1;m<=a;m++)
    for(n=1;n<=b;n++)
     { scanf("%d",&c);
       if(c!=0)
        {  M->data[p].e=c;
           M->data[p].i=m;
           M->data[p].j=n;
           p++;
        }
     }
  M->tu=p; M->mu=a; M->nu=b;

SanYuanZu * fasttrans(SanYuanZu *M,SanYuanZu *T)
{  
   int p,col,q,t,m;
   int num[100];
   int cpot[100];
   T->mu=M->nu; T->nu=M->mu; T->tu=M->tu;
   if(T->tu!=0)
    {
      for(col=1;col<=M->nu;++col) 
		  num[col]=0;
        for(t=1;t<M->tu;++t)    
			num[M->data[t].j]++;
      cpot[1]=1;
      for(col=2;col<=M->nu;++col)  
		  cpot[col]=cpot[col-1]+num[col-1];
      for(p=1;p<M->tu;++p)
        {  
		   col=M->data[p].j; 
		   q=cpot[col];
           T->data[q].i=M->data[p].j;
           T->data[q].j=M->data[p].i;
           T->data[q].e=M->data[p].e;
           ++cpot[col];
        }
}
   printf("\nZhuanzhi:\n");
   for(m=1;m<T->tu;m++)
     printf("%d%d%d\t\n",T->data[m].i,T->data[m].j,T->data[m].e);
   printf("\n"); 
   return T;
}

void  print(SanYuanZu *T,int x,int y)
{  int m,n,p=1;
   int d;
   for(m=1;m<=x;m++)
    { printf("\n");
      for(n=1;n<=y;n++)
       { if(T->data[p].i==m&&T->data[p].j==n)
          {  d=T->data[p].e;
             p++;
          }
         else d=0;
         printf("%6d",d);
       }
   }
   printf("\n");
}
int main()
{  SanYuanZu *M,*T;
   M=(SanYuanZu *)malloc(sizeof(SanYuanZu));
   T=(SanYuanZu *)malloc(sizeof(SanYuanZu));
   printf("请输入行数和列数:\n");
   scanf("%d%d",&a,&b);           
   M=creatarray(M);     
   printf("创建的矩阵为:\n");
   print(M,a,b);       
   T=fasttrans(M,T);  
   printf("转置后的矩阵为\n");
   print(T,b,a);

}