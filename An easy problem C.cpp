#include<stdio.h>
typedef struct{
	long long int sum;
	int lt, rt; 
	long long int lazyadd;
	long long int lazymulti=1;
}point;
point linear[400001];
long long int mod;
void buildtree(int x, int l, int r,long long int data[]){
	linear[x].lt=l;
	linear[x].rt=r;
	if(l==r){
		linear[x].sum=data[l];
		return;
	}
	int mid=l+r >> 1;
	buildtree(x*2,l,mid,data);
	buildtree(x*2+1,mid+1,r,data);
	linear[x].sum=linear[x*2].sum+linear[x*2+1].sum;
} 

void add(int d, int l, int r, long long int re){
	int mid;
	if(l<=linear[d].lt && r>=linear[d].rt){
		linear[d].sum=(linear[d].sum+(linear[d].rt-linear[d].lt+1)*re)%mod;
		linear[d].addlazy=(linear.addlazy+re)%mod;
		return ;
	}
	lazyadd(d);
	mid=(linear[d].lt+linear[d].rt)/2;
	if(r<=mid) add(linear[d].lt,l,r,re);
}
int main(void){
	int number;
	
	scanf("%d%lld",number,mod);
	long long int data[number*4+1];
	for(int i=0;i<number;i++){
		scanf("%lld",data+i+1);
	}
	buildtree(1,1,number,data);
	
}
