#include <stdio.h>
#include<stdlib.h>
int i,j;
float Findval(float* piArray, int iStart, int iEnd, float iarr[1000][1000])
{
float iVal1, iVal2, iRet, iFind1, iFind2;
if (iarr[iStart][iEnd] != -1)
return iarr[iStart][iEnd];
if (iStart == iEnd)
{
iRet = piArray[iStart];
iarr[iStart][iEnd] = iRet;
return iRet;
}
if (iStart + 1 == iEnd)
{
float i = piArray[iStart];
float j = piArray[iEnd];
iRet = (i+j)/2;
iarr[iStart][iEnd] = iRet;
return iRet;
}
iFind1 = Findval(piArray, iStart+2, iEnd,iarr);
iFind2 = Findval(piArray, iStart+1, iEnd-1,iarr);
iVal1 = (piArray[iStart] + iFind1 + piArray[iStart] + iFind2)/2;
iFind1 = Findval(piArray, iStart, iEnd-2,iarr);
iFind2 = Findval(piArray, iStart+1, iEnd-1,iarr);
iVal2 = (piArray[iEnd] + iFind1 + piArray[iEnd] + iFind2)/2;
iRet = (iVal1+iVal2)/2;
iarr[iStart][iEnd] = iRet;
return iRet;
}
int main()
{
int iTestNumber,a;
float *piarr, iResult,iarrVisited[1000][1000];
scanf("%d", &iTestNumber);
for(i=0;i<1000;i++)
for(j=0;j<1000;j++)
iarrVisited[i][j]=-1;
while(iTestNumber--)
{
scanf("%d", &a);
piarr =(float*)malloc(sizeof(float)*a);
for(j=0;j<a;j++)
scanf("%f", &piarr[j]);
iResult = Findval(piarr, 0, a-1, iarrVisited);
printf("%.15f", iResult);
printf("\n");
}
return 0;
}
