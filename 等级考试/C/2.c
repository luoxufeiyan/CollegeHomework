#include<stdio.h>
#include<string.h> 
void main() 
{ 
    struct student { char name[9]; int a[3]; float v; } temp,*s; 
    int i,j,k; 
    scanf("%d",&n); 
    s=(student*)malloc(n*sizeof(student)); 
    for(i=1;i<=n;i++) 
    { 
        scanf("%s",s[i].name);
        s[i].v=0; 
        for(j=0;j<3;j++)
        {
            scanf("%d",&s[i].a[j]);
            s[i].v+=s[i].a[j]/3 ;
        } 
    }
    for(i=0;is[k].v) k=j; 
        temp=s[i]; s[i]=s[k]; s[k]=temp; 
    for(i=0;i<n;i++)
        printf("%s, %d, %d, %d, %f\n",s[i].name,s[i].a[0],s[i].a[1],s[i].a[2],s[i].v); 
}

