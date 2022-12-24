#include <stdio.h>
#include <limits.h>
#include <string.h>
#define ll long long int
long long int calc[101][1000001];
void Cube(){
 int k,c;
 scanf("%d %d",&k,&c);
 if(c==0 || calc[k][k*k*k-c]==1)
 printf("YES\n");
 else
 printf("NO\n");
}
int main(){
 long long int t,i,j,val,cubed;
 for(i=1;i<101;i++){
 cubed=i*i*i;
 for(j=0;j<cubed;j++){
 val=(j*j*j)%cubed;
 calc[i][val]=1;
 }
 }
 scanf("%lld",&t);
 while(t--){
 Cube();
 }
return 0;
}
