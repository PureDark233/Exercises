#include<cstdio>
#include<iostream>
#define N 50001
using namespace std;

struct Node{
    int left, right;
    long long int max, min;
}liner[N << 2];

long long int data[N]={0};

void build(int x,int L, int R){
    liner[x].left = L;
    liner[x].right = R;
    if(L==R){
        liner[x].max=data[L];
        liner[x].min=data[L];
        return;
    }
    int mid=L+R >> 1;
    build(x*2,L,mid);
    build(x*2+1,mid+1,R);
    liner[x].max=(liner[x*2].max>liner[x*2+1].max)?liner[x*2].max:liner[x*2+1].max;
    liner[x].min=(liner[x*2].min<liner[x*2+1].min)?liner[x*2].min:liner[x*2+1].min;
}

long long int qurymax(int x,int L,int R){
    if(L ==liner[x].left&& R ==liner[x].right)
        return liner[x].max;

    int mid= liner[x].left+ liner[x].right >> 1;
    if(R<=mid)
        return qurymax(x*2, L, R);
    else if(L>mid)
        return qurymax(x*2+1, L, R);
    else return (( qurymax(x*2, L, mid) > qurymax(x*2+1, mid+1, R) )? qurymax(x*2, L, mid) : qurymax(x*2+1, mid+1, R) );
}

long long int qurymin(int x,int L,int R){
    if(L ==liner[x].left&& R ==liner[x].right)
        return liner[x].min;

    int mid= liner[x].left+ liner[x].right >> 1;
    if(R<=mid)
        return qurymin(x*2, L, R);
    else if(L>mid)
        return qurymin(x*2+1, L, R);
    else return (( qurymin(x*2, L, mid) < qurymin(x*2+1, mid+1, R) )? qurymin(x*2, L, mid) : qurymin(x*2+1, mid+1, R) );
}

int main(void){
    int m,n;
    if(scanf("%d%d",&m,&n)==2){
        
        for(int i=1;i<=m;i++){
            scanf("%lld",data+i);
        }
        build(1,1,m);
        int a,b;
        long long int max,min,result;
        for(int i=0;i<n;i++){
            scanf("%d%d",&a,&b);
            max=qurymax(1,a,b);
            min=qurymin(1,a,b);
            result=max-min;
            printf("%lld\n",result);
        }
    }
    return 0;

}
