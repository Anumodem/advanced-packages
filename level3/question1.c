#include <stdio.h>
#include"stdlib.h"
#include"string.h"
#define WHITE 2
#define PINK 1
#define BLUE 0
#define BOY 0
#define GIRL 1
typedef struct node{
int vertex;
struct node* next;
}node_t;
node_t** adjList;
int* colour;
int* gender;
int findInversions( int n ){
int* queue = (int*)calloc(n,sizeof(int));
int queueStart = n-1;
int queueEnd = n-1;
queue[n-1] = 0;
colour[0] = BLUE;
while( queueStart<=queueEnd ){
int vertex = queue[queueEnd--];
node_t* t=adjList[vertex];
while(t!=NULL){
int v2 = t->vertex;
if( colour[v2] == WHITE ){
colour[v2] = 1- colour[vertex];
queue[--queueStart] = v2;
}
else
if( colour[v2] == colour[vertex] )
return -1;
t=t->next;
}
}
// coming here means that coloring is possible
// now count the inversions in this coloring
int count =0,i;
for( i=0;i<n;i++)
if(colour[i] != gender[i]) count ++;
if( count > n/2 ) count = n-count;
return count;
}
int main()
{
int n,m,v1,v2,i;
char* temp;
scanf("%d%d", &n, &m);
temp = (char*) calloc(4, sizeof(char));
adjList = (node_t**)calloc(n,sizeof(node_t*));
colour=(int*)calloc(n,sizeof(int));
gender=(int*)calloc(n,sizeof(int));
for( i=0;i<n;i++){
scanf("%s", temp);
if(temp[0] == 'B')
gender[i] = BOY;
else
gender[i] = GIRL;
colour[i] = WHITE;
adjList[i]= NULL;
}
for( i=0;i<m;i++){
scanf("%d%d", &v1, &v2);
v1--;v2--; // 0 based indexing
node_t* t = (node_t*)malloc(sizeof(node_t));
t->vertex = v2;
t->next = adjList[v1];
adjList[v1] = t;
t = (node_t*)malloc(sizeof(node_t));
t->vertex = v1;
t->next = adjList[v2];
adjList[v2] = t;
}
int Result = findInversions( n );
if(Result == -1) printf("Not Possible\n");
else printf("%d\n", Result);
//printf("1\n");
return 0;
}
