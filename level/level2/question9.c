#include <stdio.h>
#define MAX 100000
#define max(a,b) (a>b)?a:b
double a[MAX];
const double EPS = 1e-8;
int n;
int solve(int n,double t,double d)
{
int i;
double x=max(0.0,a[0]-d);
for(i=1;i<n;i++){
if(a[i]+d<x+t) return 0;
x=max(a[i]-d,x+t);
}
return 1;
}
int main()
{
int test,i;
double t,l,h;
scanf("%d",&test);
while(test--)
{
scanf("%d%lf",&n,&t);
for(i=0;i<n;i++)
scanf("%lf",&a[i]);
l=0;
h=1;
while(!solve(n,t,h))
h=h*2;
while(l+EPS<h){
double mid=(l+h)/2;
if(solve(n,t,mid))h=mid;
else l=mid;
}
printf("%.4lf\n",l);
}
return 0;
}
