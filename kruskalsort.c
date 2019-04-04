#include<stdio.h>
int ar[1000][1000],arr[1000],p[100];
int sort(int n)
{
int i,j;
for(i=1;i<n;i++)
{
for(j=0;j<i;j++)
if(arr[j]>arr[i])
{
int t=arr[i];
arr[i]=arr[j];
arr[j]=t;
}
}
}

int union1(int i,int j)
{
p[i]=j;
}
int find(int i)
{
while(p[i]>=0)
i=p[i];
return i;
}
int delete(int e)
{
int k;
for(k=1;k<e;k++)
arr[k-1]=arr[k];
}
int kruskal(int n,int e)
{
int mc=0,t[n][n],l,i,j,k,u,v;
sort(e);
for(i=0;i<e;i++)
p[i]=-1;
i=0;
while(i<e-1 && arr[0]>0)
{
l=arr[i];
for(u=0;u<n;u++)
{
for(v=0;v<n;v++)
{
if(ar[u][v]==l)
break;
}
}
ar[u][v]=99999;
ar[v][u]=99999;
delete(e-i);
j=find(u);
k=find(v);
if(j!=k)
{
i=i+1;
t[i][1]=u;
t[i][2]=v;
mc=mc+l;
union1(j,k);
}
}
}
int main()
{
    int i,n,e,j,v,u,c;
    printf("enter the no of nodes and edges-");
    scanf("%d%d",&n,&e);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            ar[i][j]=99999;
    }
    for(i=0;i<e;i++)
    {
        printf("enter the nodes no and cost-");
        scanf("%d%d%d",&u,&v,&c);
        ar[u][v]=c;
        ar[v][u]=c;
        arr[i]=c;
    }
    kruskal(n,e);
    for(i=0;i<n;i++)
    printf("%d\n",p[i]);
}
