// question f(x)=1/(1+x*x)
#include <stdio.h>
double y[1000];

double func(int i) {
  double sum, x = i;
  sum = 1 / (1 + x * x);
  return sum;
}

int main() {
  int a, b, i;
  double sum = 0, h;
  printf("enter the limits=");
  scanf("%d%d", &a, &b);
  printf("enter the value of differences=");
  scanf("%lf", &h);
  for (i = a; i <= b; i = i + h)
    y[i] = func(i);
  for (i = a + 1; i < b; i = i + h)
    sum = sum + 2 * y[i];
  sum = sum + y[a] + y[b];
  sum = h / 2 * (sum);
  printf("soln=%lf", sum);
}
