#include <iostream>  
#include <queue> 
#include<cstdio>  
using namespace std;   
int main(void){  
    int m,temp; 
    scanf("%d",&m);
    priority_queue<int, vector<int>, greater<int> > q;  
    for(int i=0;i<m;i++){
    	scanf("%d",&temp);
    	q.push(temp);
    }
    if(m==1){
    	printf("0");
    	return 0;
    }
    long long int result=0;
    int a,b,sum,i=m;
    while(q.size()>1) {
    	a=q.top();
    	q.pop();
		b=q.top();
		q.pop();
		sum=a+b;
		q.push(sum);
		result+=sum;
	}
	printf("%lld",result);
	
      
    return 0;  
}  
