#include <stdio.h>
#include<stdlib.h>
#include <math.h>
int k1,k2,n,j,i;
long long int *G,*S;
long long int MOD = 1000000007;
int cmpfunc(const void *a,const void *b)
{
if(*(long long *)a < *(long long int *)b)
return -1;
if(*(long long*)a > *(long long int*)b)
return 1;
return 0;
}
void arrayprint(long long int *a)
{
for(i=0;i<n;i++)
{
printf("%lld\t",a[i]);
}
printf("\n");
}
void init()
{
scanf("%d%d%d",&k1,&k2,&n);
G=(long long int*)malloc(n*sizeof(long long int));
S=(long long int*)malloc(n*sizeof(long long int));
for(i=0;i<n;i++)
{
scanf("%lld",&G[i]);
}
for(i=0;i<n;i++)
{
scanf("%lld",&S[i]);
}
}
int main(void)
{ int t,Case;
scanf("%d",&t);
for(Case = 0;Case <t; Case++)
{ init();
qsort(G,n,sizeof(long long int),cmpfunc);
qsort(S,n,sizeof(long long int),cmpfunc);
long long int *res=(long long int*)malloc(n*sizeof(long long int));
for(i=0;i<n;i++) res[i] = 0;
long long int target = k1*k2;
for(i=0;i<n;i++)
{for(j=0;j<n;j++)
{if(G[i]*S[j]>target)
{res[i]=n-j;
break;}}}
qsort(res,n,sizeof(long long int),cmpfunc);
long long int prod = 1;
for(i=0;i<n;i++)
{ res[i] -=i;
if(res[i]<0) res[i] = 0;
prod*=res[i];
prod=prod%MOD; }
printf("Case %d: %lld\n",Case+1,prod%MOD);
} return 0;
}
