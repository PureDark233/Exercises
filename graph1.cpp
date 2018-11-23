#include<bits/stdc++.h>
#define MAX 999999999;
using namespace std;

typedef struct edge{
    int nodeid;
    int edge_value;
    edge* next;
};

typedef struct node{
    struct edge* next=NULL;
}head;

int main(void){
    int n,m;
    scanf("%d%d",&n,&m);
    head headlist[201];
    edge* newedge;
    int u,v,w;
    for(int i=0;i<m;i++){
        scanf("%d%d%d",&u,&v,&w);
        newedge=(edge*)malloc(sizeof(edge));
        newedge->nodeid=u;
        newedge->edge_value=w;
        newedge->next=headlist[v].next;
        headlist[v].next=newedge;

        newedge=(edge*)malloc(sizeof(edge));
        newedge->nodeid=v;
        newedge->edge_value=w;
        newedge->next=headlist[u].next;
        headlist[u].next=newedge;
    }
    long long int path[n+1]={MAX};
    path[1]=0;


}
