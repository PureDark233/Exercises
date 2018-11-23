#include<stdio.h>
#include<string.h>
int main(void){
	int a,b,result=0;
	scanf("%d %d",&a,&b);
	int tree[a+1];
	memset(tree,0,sizeof(tree));
	for(int count=0;count<b;count++){
		int i,o;
		scanf("%d%d",&i,&o);
		for(int m=i;m<=o;m++){
			tree[m]=1;
		}
	}
	for(int h=1;h<=a;h++){
		if(tree[h]==0)
		result++;
	}
	printf("%d",result+1);
}