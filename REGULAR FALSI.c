#include<stdio.h>
#include<math.h>
int arr[1000];
int n;
double epsilon=0.00001;

double func(double a)
{
    double sum=0;
    for(int i=0;i<=n;i++)
    {
       sum+=arr[i] * pow(a , n-i);
    }
    return sum;
}

double reg(double a, double b)
{
    double c=0,p=1,m=0;
    while(p>=epsilon)
    {
        if(c!=0)
        p=fabs((c-m)/c)*100;
        m=c;
        double tm =  (a*func(b) - b*func(a));
        c= tm/ (func(b) - func(a));
        if(func(c)==0.0)
        {return c;
        break;
        }
        if(func(a) * func(c) < 0)
            b = c;
        else
            a = c;
    }

     return c;
}

int main()
{

  printf("enter the highest power\n");
  scanf("%d",&n);
  printf("enter the coeficient of equation\n");
  for(int g=0;g<=n;g++)
      scanf("%d",&arr[g]);
  double a=0,b=0,i=0,j=0;
  if(func(0)<0)
  {
    while(func(i)<=0 && func(j)<=0)
    {
        i++;
        j--;
    }
    if(func(i)>0)
    {
    a=i-1;
    b=i;
    }
    else
    {
        a=j;
        b=j+1;
    }
  }
  else
  {
    while(func(i)>=0 && func(j)>=0)
    {
        i++;j--;
    }
    if(func(i)<0)
{a=i-1;
b=i;
}
    else
    {
        a=j;b=j+1;
    }
  }
    printf("root=%lf\n",reg(a,b));
    return 0;
}


