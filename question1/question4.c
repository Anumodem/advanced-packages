#include<stdio.h>
#include <stdlib.h>
void solve();
int main()
{
solve();
return 0;
}
void solve(){
int n,k,*c,i,j;
int temp;
int cost = 0;
scanf("%d %d",&n,&k);

c=(int *)malloc(n*sizeof(int));
for(i=0;i<n;i++)
scanf("%d",&c[i]);

for(i=0;i<n;i++)
for(j=0;j<n-i-1;j++)
{

if(c[j] < c[j+1])
{
temp = c[j];
c[j] = c[j+1];
c[j+1] = temp;
}
}
for(i=0;i<n;i++)
{
cost+=((int)(i/k)+1) * c[i];
//printf("%d\r\n", a[i]);
}
printf("%d\r\n",cost);
//scanf("%d",&n);
}
