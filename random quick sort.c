#include <stdio.h>
int a[10000];
void swap(int i,int j)
{
int t;
t=a[i];
a[i]=a[j];
a[j]=t;
}
int partition(int m,int p)
{
int i=m,j=p,v=a[m];
printf("random value=%d\n",v);
while(j>i)
{
do{
i++;
}while(i<p && a[i]<=v);
do
{
j--;
}while(j>m && a[j]>=v);
if(j>i)
swap(i,j);
}
swap(m,j);
return j;
}

void quicksort(int p,int q)
{
if(q>p)
{
int s=p+rand()%(q-p)+1;
swap(p,s);
int j=partition(p,q+1);
quicksort(p,j-1);
quicksort(j+1,q);
}
}
int main()
{
  int i,n;
printf("enter the size of array=");
scanf("%d",&n);
printf("enter the elements of array=");
for(i=0;i<n;i++)
scanf("%d",&a[i]);
quicksort(0,n-1);
printf("sorted array=");
for(i=0;i<n;i++)
printf(" %d",a[i]);
}

