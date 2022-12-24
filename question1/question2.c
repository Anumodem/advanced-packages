#include <stdio.h>
#include <stdlib.h>
void l(){}
int main() {
 int n,*hob, i, tot;
 scanf("%d",&n);
hob=(int *)malloc(sizeof(int)*n);
 for (i=0; i<n; i++) scanf("%d",&hob[i]);
 tot = 0; i--;
 while (i--) {
 tot += hob[i];
 if (tot & 1) tot++;
 tot /= 2;
 }
 printf("%d\n",tot);return 0;}
