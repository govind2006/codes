#include<stdio.h>
#include<math.h>
int eq[1000];
int n;
double epsilon = 0.0001;
double func(double a)
{
    double sum=0;
    int i;

    for( i=0;i<=n;i++)
    {

        sum+=eq[i] * (pow(a,n-i));
    }
    return sum;
}

double secant(double a, double b)
{
    double c=1,p=1,m=0;
    while(p>epsilon)
    {
        if(b!=0)
            p=fabs(((a-b)/b)*100);
        if(func(c)==0.0)
            break;
        c=b-((b-a)/(func(b)-func(a)))*func(b);
        a=b;
        b=c;
    }
    return c;
}



int main()
{

  printf("enter the highest power\n");
  scanf("%d",&n);
  printf("enter the coeficient of equation\n");
  for(int i=0;i<=n;i++)
  {
      scanf("%d",&eq[i]);
  }
  double a=0,b=0;
  double i=0,j=0;
  if(func(0)<0)
  {
    while(func(i)<=0 && func(j)<=0)
    {
        i++;j--;
    }
    if(func(i)>0)
    {
    a=i-1;
    b=i;
    }
    else
    {
        a=j;b=j+1;
    }

  }
  else
  {
    while(func(i)>=0 && func(j)>=0)
    {
        i++;j--;
    }
    if(func(i)<0)
    {
    a=i-1;b=i;
    }
    else
    {
        a=j;b=j+1;
    }
  }
    printf("root=%lf\n",secant(a,b));

    return 0;
}

