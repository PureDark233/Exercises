#include<cstdio>
#include<iostream>
#define N 100001
#define INFINATE 2147483647

struct SegmentTree{
	int max;
	int lazy;
}Tree[N << 2];

using namespace std;

int max(int a,int b)return (a>b)?a:b ;

void build(int root, int data[], int start, int end){
	Tree{root}.lazy=0;
	if(start==end)
		Tree[root]=data[start];
	else{
		int mid=(start+end)/2;
		build(root*2+1,data,start,mid);
		build(root*2+2,data,mid+1,end);
		Tree[root].max=max(Tree[root*2+1].max,Tree[root*2+2].max);
	}
}

void pass(int root){
	if(Tree[root].lazy!=0){
		Tree[root*2+1].lazy+=Tree[root].lazy;
		Tree[root*2+2].lazy+=Tree[root].lazy;
		
		Tree[root*2+1].max+=Tree[root].lazy;
		Tree[root*2+2].max+=Tree[root].lazy;
		
		Tree[root].lazy=0;
	}
} 
int query(int root,int sstart, int send, int qstart, int qend){
	if(qstart>send||qend<sstart)
		return INFINATE;
	if(qstart<=sstart&&qend>=send)
		return Tree[root].max;
	pass(root);
	int mid=(sstart+send)/2;
	return max(query(root*2+1,sstart, mid, qstart, qend),
			   query(root*2+2,mid+1, send, qstart, qend));
}

void updateold(int root, int sstart, int send, int change, int add){
	if(sstart==send){
		if(change==sstart)
			Tree[root].max+add;
		return;
	}
	int mid=(sstart+send)/2;
	if(change<=mid)
		updateold(root*2+1,sstart,mid,change,add);
	else
		updateold(root*2+2,mid,send,change,add);
	Tree[root].max=max(Tree[root*2+1].max,Tree[root*2+2].max);
}




