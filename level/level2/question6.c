#include <stdio.h>
#include<math.h>
#define S(X) ((X)*(X))
#define MAX(A,B) ((A)>(B)?(A):(B))
#define MIN(A,B) ((A)<(B)?(A):(B))
double d[600];
double x[600],y[600];
int done[600];
int main(void)
{
int T,i,n,r,R;
int id;
scanf("%d",&T);
while(T--)
{
 scanf("%d%d",&r,&R);
 scanf("%d",&n);
 for(i=0;i<n;i++)
 scanf("%lf%lf",&x[i],&y[i]);
 for(i=0;i<n;i++)
 {
 d[i]=sqrt( S(x[i])+S(y[i]) )-r;
 done[i]=0;
 }
 done[n]=0;
 d[n]=R-r;
 while(1)
 {
 id=-1;
 for(i=0;i<=n;i++)
 if(!done[i] && (id==-1 || d[id]>d[i]))
 id=i;
 if(id==n) break;
 done [id]=1;
 for(i=0;i<n;i++)
 if(!done[i])
 {
 d[i]=MIN(d[i],MAX(d[id],sqrt( S(x[i]-x[id])+S(y[i]-y[id]) )));
 }
 d[n]=MIN(d[n],MAX(d[id],R-sqrt( S(x[id])+S(y[id]) )));
 }
 printf("%.3lf\n",d[n]);
}
 return 0;
}
