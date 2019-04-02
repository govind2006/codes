#include<bits/stdc++.h>
using namespace std;
vector<int>v;
int binarySearch(int i,int j,int p)
{
if (j!=i) {
int mid =i+ (j- i) / 2;
if (v[mid] == p)
return 1;
if (v[mid] > p)
return binarySearch(i, mid - 1, p);
else
return binarySearch(mid + 1, j, p);
}
else{
if(v[i]==p)
return 1;
else
return -1;
}
}
int main()
{
int n,i,p,l;
cout<<"enter the size of array=";
cin>>n;
cout<<"enter the array=";
for(i=0;i<n;i++)
{
int l;
cin>>l;
v.push_back(l);
}
cout<<"enter the searching element=";
cin>>p;
l=binarySearch(0,n-1,p);
if(l==-1)
cout<<"no";
else
cout<<"yes";
}

