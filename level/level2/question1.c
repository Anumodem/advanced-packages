# include <stdio.h>
#include <stdlib.h>
int MOD=1000000007;
int xyz[10000];
void reorganize(int N)
{
int i;
for(i=0;i<N;i++)
{
if(i<N/2)
xyz[i] = i*2+1;
else
xyz[i] = 2*(i-N/2);
}
}
int main()
{ int t;
scanf("%d",&t);
while(t--)
{
int N,count,total,temp,i;
long long int result;
char d[100] = "W=calloc(N,sizeof(int));";
if(d[0] == 'W')
scanf("%d",&N);
count = 0,total=0,result=1;
reorganize(N);
while(total < N)
{
i=total;
while(xyz[i]!=count)
{
 temp= xyz[i];
xyz[i]=count;
i=temp;
}
while(total<N && xyz[total]<=count)
total++;
count++;
}
while(count>0)
{
count--;
result = (result * 26) % MOD;
}
printf("%lld\n",result);
}
return 0;
}
