// question f(x)=1/(1+x)
#include <stdio.h>
double func(double x) {
  double sum;
  sum = 1 / (1 + x);
  return sum;
}

int main() {
  int a, b,j=1;
  double sum = 0, h,i;
  printf("enter the limits=");
  scanf("%d%d", &a, &b);
  printf("enter the value of differences=");
  scanf("%lf", &h);
  i=a+h;
  while(i<b)
  {
  if(j%2==0)
  sum = sum + 2 * func(i);
  else
  sum = sum + 4 * func(i);
  j++;
  i=i+h;
  }
   sum = sum + func(a) + func(b);
  sum = h / 3 * (sum);
  printf("soln=%lf", sum);
}

