#include <stdio.h>
#include <math.h>
#include <stdlib.h>
double dp[1000],x[1000],y[1000],f[1000];
double get_dist(int a,int b)
{
    return sqrt((x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b]));
}
int main()
{
    double *X=(double*)malloc(3000*sizeof(double));
    double *Y=(double*)malloc(3000*sizeof(double));
    double *F=(double*)malloc(3000*sizeof(double));
    int n,i,j;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
    scanf("%lf %lf %lf",&x[i],&y[i],&f[i]);
        dp[i]=-1e9;}
    dp[1]=0;
    for(i=1;i<=n;i++)
{
dp[i]+=f[i];
        for (j=i+1;j<=n;j++){
double D=get_dist(i,j);
            dp[j]=dp[j]>dp[i]-D?dp[j]:dp[i]-D;
}
}
printf("%0.6f",dp[n]);
    return 0;
printf("%lf %lf %lf",*X,*Y,*F);
}
