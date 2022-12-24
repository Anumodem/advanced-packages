#include <stdio.h>
#include <stdlib.h>
int main()
{
int t;
scanf("%d",&t);
while(t--){
int m,n,i,j;
scanf("%d %d",&m,&n);
if(n>m){
printf("0");
}
else if(m==n)
printf("1");
else{
int *ar = (int *)calloc(m+1,sizeof(int));
int *tmp = (int *)calloc(m+1,sizeof(int));
ar[0] = 1;
ar[m] = 1;
for(i=m-1;i>=n;i--){
tmp[0] = 1;
for(j=1;j<i;j++)tmp[j] = 0;

tmp[i] = 1;
for(j=i+1;j<=m;j++)tmp[j] = (tmp[j-i] + ar[j])%1000000009;
int *swap = ar;
ar = tmp;
tmp = swap;
}
printf("%d",ar[m]);
}
printf("\n");
}
return 0;}
