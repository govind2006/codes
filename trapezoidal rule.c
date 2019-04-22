// question f(x)=1/(1+x*x)
#include <stdio.h>
double func(double x) {
  double sum;
  sum = 1 / (1 + x*x);
  return sum;
}

int main() {
  int a, b;
  double sum = 0, h,i;
  printf("enter the limits=");
  scanf("%d%d", &a, &b);
  printf("enter the value of differences=");
  scanf("%lf", &h);
  i=a+h;
  while(i<b)
  {
  sum = sum + 2 * func(i);
  i=i+h;
  }
   sum = sum + func(a) + func(b);
  sum = h / 2 * (sum);
  printf("soln=%lf", sum);
}
