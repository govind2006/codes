#include <stdio.h>
double ar[100][100], x[100], a[100], b[100];
int check(int n) {
  int k = 0, i;
  for (i = 0; i < n; i++)
    if (x[i] == b[i])
      k++;
  if (k == n)
    return 0;
  else
    return 1;
}
int main() {
  int i, j, n;
  printf("enter the size of matrix=");
  scanf("%d", &n);
  printf("enter the matrix row wise-\n");
  for (i = 0; i < n; i++) {
    for (j = 0; j < n + 1; j++) {
      printf("%d %d=", i, j);
      scanf("%lf", &ar[i][j]);
    }
  }
  double sum = 0;
  for (i = 0; i < n; i++) {
    a[i] = 0;
    x[i] = 0;
    b[i] = 1;
  }
  while (check(n) == 1) {
    for (i = 0; i < n; i++)
      x[i] = b[i];
    for (i = 0; i < n; i++) {
      sum = 0;
      a[i] = 0;
      for (j = 0; j < n; j++)
        sum = sum + a[j] * ar[i][j];
      b[i] = (ar[i][n] - sum) / ar[i][i];
      a[i] = b[i];
    }
    for (i = 0; i < n; i++)
      printf("%lf ", b[i]);
    printf("\n");
  }
  printf("exact root=");
  for (i = 0; i < n; i++)
    printf("%lf ", b[i]);
}

