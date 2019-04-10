#include <stdio.h>
int cost[100][100];
int prims(int n, int e) {
  int i, j, k, mincost,u,l,near[n],t[n][n];
  for(i=1;i<=n;i++)
  near[i]=-1;
  mincost = 99999;
  for (j = 1; j <= n; j++) {
    for (u = 1; u <= n; u++)
      if (cost[j][u] < mincost)
    {
        k=j;
        l=u;
         mincost = cost[j][u];
  }
  }
  t[1][1]=k;
  t[1][2]=l;
  for (u = 2; u < n; u++) {
    int c = 99999;
  for (i = 1; i <= n; i++) {
    if(near[i]!=0)
    {
    if(cost[i][k]<cost[i][l])
    near[i]=k;
    else
    near[i]=l;
    }
}
near[k]=near[l]=0;
for(j=1;j<=n;j++)
{
    if(near[j]>0)
    {
        if(c>cost[j][near[j]])
    {
        c=cost[j][near[j]];
        k=j;
        l=near[j];
    }
    }
}
t[u][1] = k;
t[u][2] = l;
mincost=mincost+c;
}
  return mincost;
}

int main() {
  int n, e, i, v, j, u, c;
  printf("enter the no of nodes and edges-");
  scanf("%d%d", &n, &e);
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++)
      cost[i][j] = 99999;
  }
  for (i = 1; i <= e; i++) {
    printf("enter node no and cost-");
    scanf("%d%d%d", &u, &v, &c);
    cost[u][v] = c;
    cost[v][u] = c;
  }
  printf("mincost=%d",prims(n, e));
}
