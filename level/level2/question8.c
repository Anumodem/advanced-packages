#include <stdio.h>
#include <string.h>
#define MAX_BUF 50000
int getint(){
int c,num;
while(c<'0' || c>'9')
c=getchar_unlocked();
num=0;
while(c>='0' && c<='9'){
num=(10*num)+(c-'0');
c=getchar_unlocked();
}
return num;
}
int main()
{
int c,T,N,i,ans_len,curr_truth,lo,hi;
int a[MAX_BUF],b[MAX_BUF],delta[MAX_BUF],ans[MAX_BUF];
T=getint();
while(T--){
N=getint();
memset(delta,0,(N+1)*sizeof(int));
for(i=0;i<N;i++){
c=getint();
a[i]=c;
delta[c]++;
c=getint();
b[i]=c;
delta[c+1]--;
}
curr_truth=0;
ans_len=0;
for(i=0;i<=N;i++){
curr_truth+=delta[i];
if(curr_truth==i)
ans[ans_len++]=i;
}
printf("%d\n",ans_len);
for(i=0;i<N;i++){
if(a[i]<=ans[0]&&b[i]>=ans[ans_len-1]){
printf("1");
}else{
printf("0");
for(lo=0;lo<ans_len&& ans[lo]<a[i];)
lo++;
for(hi=lo;hi<ans_len && ans[hi]<=b[i];)
hi++;
if(lo<hi){
for(;hi<ans_len;lo++,hi++)
ans[lo]=ans[hi];
}
}
}
printf("\n");
}
return 0;
}
