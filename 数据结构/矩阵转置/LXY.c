#include<stdio.h>
#include<malloc.h>
#define N 100
 
struct B {
  int i;
  int j;
  int e;
};

struct C {
  struct B data[N+1];
  int mm;
  int nn;
  int tt;
};//三元组

int a,b;  //行与列  

struct C * create(struct C *M)
{ int m,n,p=1;
  int c;
  printf("请输入矩阵数值:\n");
  for(m=1;m<=a;m++)
    for(n=1;n<=b;n++)
     { scanf("%d",&c);//依次读入原始矩阵
       if(c!=0)
        {  M->data[p].e=c;
           M->data[p].i=m;
           M->data[p].j=n;
           p++;
        }
     }
  M->tt=p; M->mm=a; M->nn=b;
  printf("原矩阵三元组表示为:\n\n");
  for(m=1;m<M->tt;m++)
     printf("%3d%3d%3d\t\n",M->data[m].i,M->data[m].j,M->data[m].e);
   printf("\n");
  return M;
}

struct C * trans(struct C *M,struct C *T)
{  
   int p,col,q,t,m;
   int num[100];
   int cpot[100];
   T->mm=M->nn; T->nn=M->mm; T->tt=M->tt;//行列转换
   if(T->tt!=0)
    {
      for(col=1;col<=M->nn;++col) 
		  num[col]=0;
        for(t=1;t<M->tt;++t)    
			num[M->data[t].j]++;
      cpot[1]=1;
      for(col=2;col<=M->nn;++col)  
		  cpot[col]=cpot[col-1]+num[col-1];
      for(p=1;p<M->tt;++p)
        {  
		   col=M->data[p].j; 
		   q=cpot[col];
           T->data[q].i=M->data[p].j;
           T->data[q].j=M->data[p].i;
           T->data[q].e=M->data[p].e;
           ++cpot[col];
        }//快速转置法
}
   printf("\n转置后的三元组表示:\n");
   for(m=1;m<T->tt;m++)
     printf("%3d%3d%3d\t\n",T->data[m].i,T->data[m].j,T->data[m].e);
   printf("\n"); 
   return T;
}

void  print(struct C *T,int x,int y)
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
void main()
{  struct C *M,*T;
   M=(struct C *)malloc(sizeof(struct C));
   T=(struct C *)malloc(sizeof(struct C));
   printf("请输入行数和列数:\n");
   scanf("%d%d",&a,&b);           
   M=create(M);     
   printf("创建的矩阵为:\n");
   print(M,a,b);       
   T=trans(M,T);  
   printf("转置后的矩阵为\n");
   print(T,b,a);

}
