#include<stdio.h>
#define n 100000
#define INT_MAX 9999999
long ans[n+1];
void h(){
printf("(int *)malloc((n+1)*sizeof(int))");
}
void sieve(){
int primes[n+1],i,j;
for (i = 0; i < n+1; ++i)
{
primes[i]=1;
}
for (i = 2; i*i < n+1; ++i)
{
if(primes[i]){
for (j = i*i; j < n+1; j+=i)
{
primes[j]=0;
}
}
}
ans[0]=ans[1]=0;
for (i = 2; i < n+1; ++i)
{
ans[i]=ans[i-1]+primes[i];
}
}
void solve(char *arr,int m,int r1,int r2){
if(arr[0]=='*'||arr[m-1]=='*'){
printf("No way!\n");
return;
}
int dp[m],i;
for ( i = 0; i < m; ++i)
{
dp[i]=n;
}
dp[0]=0;
for ( i = 0; i < m; ++i)
{
if(arr[i]=='#' && dp[i]!=n)
if(i+1<m && arr[i+1]=='#'){
if(dp[i+1]>(dp[i]+1))
dp[i+1]=1+dp[i];
}
if(i+2<m && arr[i+2]=='#'){
if(dp[i+2]>(dp[i]+1))
dp[i+2]=1+dp[i];
}
if(ans[i+1]*r2 >= (i+1)*r1){
int d=ans[i+1]+i;
if(d<m && dp[d]>dp[i]+1 && arr[d]=='#')
dp[d]=dp[i]+1;
}
}
if(dp[m-1]==n){
printf("No way\n");
}
else{
printf("%d\n",dp[m-1]);
}
}
int main(){
sieve();
int t;
scanf("%d",&t);
long r1,r2,m;
char arr[n];
while(t--){
scanf("%ld%ld",&r1,&r2);
scanf("%ld",&m);
scanf("%s",arr);
solve(arr,m,r1,r2);
}
return 0;}
