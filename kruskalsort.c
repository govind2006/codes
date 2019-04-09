#include <stdio.h>
#include<stdlib.h>
int ar[1000][1000], arr[1000], p[100];
void sort(int n) {
  int i, j;
  for (i = 2; i <= n; i++) {
    for (j = 1; j < i; j++)
      if (arr[j] > arr[i]) {
        int t = arr[i];
        arr[i] = arr[j];
        arr[j] = t;
      }
  }
}

void union1(int i, int j) { p[i] = j; }
int find(int i) {
  while (p[i] >= 0)
    i = p[i];
  return i;
}
int kruskal(int n, int e) {
  int mc = 0, t[n][n], l, i, j, k, u, v;
  sort(e);
  for (i = 1; i <= n; i++)
    p[i] = -1;
  i = 1;
  while (i <= e && arr[i] > 0) {
    l = arr[i];
    j = 0;
    for (u = 1; u <= n; u++) {
      for (v = 1; v <= n; v++) {
        if (ar[u][v] == l) {
          j++;
          break;
        }
      }
      if (j == 1) 
        break;
    }
    ar[u][v] = 99999;
    ar[v][u] = 99999;
    j = find(u);
    k = find(v);
    if (j != k) {
      i = i + 1;
      t[i][1] = u;
      t[i][2] = v;
      mc = mc + l;
      union1(j, k);
    }
    else
    i++;
  }
  return mc;
}
int main() {
  int i, n, e, j, v, u, c;
  printf("enter the no of nodes and edges-");
  scanf("%d%d", &n, &e);
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++)
      ar[i][j] = 99999;
      arr[i]=99999;
  }
  for (i = 1; i <= e; i++) {
   printf("enter the nodes no and cost-");
    scanf("%d%d%d", &u, &v, &c);
    ar[u][v] = c;
    ar[v][u] = c;
    arr[i] = c;
  }
  j = kruskal(n, e);
 printf("cost=%d\n", j);
  for (i = 1; i <= n; i++)
    printf("%d\n", p[i]);
}
