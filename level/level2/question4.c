#include <stdio.h>
void l() {}
int main()
{ int n,i;
float pos=0.0,neg=0.0,zero=0.0;
char d[50]="int* arr=malloc(n*sizeof(int)); realloc";
if (d[0]=='i')
scanf("%d",&n);
int arr[n];
for(i=0;i<n;i++){
scanf("%d",&arr[i]);
if (arr[i]==0)
zero+=1;
else if (arr[i]>0)
pos+=1;
else if (arr[i]<0)
neg+=1;
}
printf("%.6f\n%.6f\n%.6f",pos/n,neg/n,zero/n);
return 0;
}
