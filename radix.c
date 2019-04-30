#include <stdio.h>
int a[100], b[100];
int length(int m) {
  int p = 0;
  while (m > 0) {
    m = m / 10;
    p++;
  }
  return p;
}
int max(int g[], int n) {
  int m = 0, i;
  for (i = 1; i <= n; i++)
    if (g[i] > m)
      m = g[i];
  return m;
}
void countsort(int n, int div) {
  int c[10], i;
  for (i = 0; i <= 9; i++)
    c[i] = 0;
  for (i = 1; i <= n; i++)
    c[(a[i] / div) % 10]++;
  for (i = 1; i <= 9; i++)
    c[i] = c[i - 1] + c[i];
  for (i = 0; i < n; i++) {
    b[c[(a[n - i] / div) % 10]] = a[n - i];
    c[(a[n - i] / div) % 10]--;
  }
  for (i = 1; i <= n; i++)
    a[i] = b[i];
}

void radix(int n) {
  int m = max(a, n), div = 1, i;
  int l = length(m);
  for (i = 0; i < l; i++) {
    countsort(n, div);
    div = div * 10;
  }
}

int main() {
  int i, n, x;
  printf("enter size=");
  scanf("%d", &n);
  printf("enter value\n");
  for (i = 1; i <= n; i++)
    scanf("%d", &a[i]);
  radix(n);
  printf("sorted array=");
  for (i = 1; i <= n; i++)
    printf("%d ", a[i]);
}
