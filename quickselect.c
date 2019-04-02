#include <stdio.h>
void swap(int a[], int i, int j) {
  int t = a[i];
  a[i] = a[j];
  a[j] = t;
}
int index(int a[],int v,int p)
{
for(int i=0;i<p;i++)
if(a[i]==v)
return i;
}
int quicksort(int a[], int m, int p)
{
  int i = m, j = p,v=a[m];
   while (j > i) {
    do {
      i++;
    } while (i < p && a[i] <=v);
    do {
      j--;
    } while (j > m && a[j] >v);
    if (j > i)
      swap(a, i, j);
  }
  swap(a, m, j);
  return j;
}
int main() {
  int i, n, x;
  printf("enter the size of array-");
  scanf("%d", &n);
  int a[n];
  printf("enter the elemnts of array-");
  for (i = 0; i < n; i++)
    scanf("%d", &a[i]);
    printf("enter the value of select-");
  scanf("%d", &x);
   int c=index(a,x,n);
   swap(a,0,c);
  quicksort(a, 0, n);
  for (i = 0; i < n; i++)
    printf("%d ", a[i]);
}

