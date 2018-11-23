#include<cstdio>
int main(void){

    long long int l1max=1,l1min=1000000000,l2max=1,l2min=1000000000,r1max=1,r1min=1000000000,r2max=1,r2min=1000000000;
    int count1,count2;
    scanf("%d",&count1);
    for(int i=0;i<count1;i++){
        long long int temp1,temp2;
        scanf("%lld %lld",&temp1,&temp2);
        if(temp1>l1max)
        l1max=temp1;
        if(temp1<l1min)
        l1min=temp1;
        if(temp2>r1max)
        r1max=temp2;
        if(temp2<r1min)
        r1min=temp2;
    }
    scanf("%d",&count2);
    for(int i=0;i<count2;i++){
        long long int temp1,temp2;
        scanf("%lld %lld",&temp1,&temp2);
        if(temp1>l2max)
        l2max=temp1;
        if(temp1<l2min)
        l2min=temp1;
        if(temp2>r2max)
        r2max=temp2;
        if(temp2<r2min)
        r2min=temp2;
    }
    
    long long int treat1=0,treat2=0;
    
    if(l1max>r2min){
        treat1=l1max-r2min; 
    }
    if(l2max>r1min){
        treat2=l2max-r1min;
    }
    if(treat1>treat2)
    printf("%lld",treat1);
    else printf("%lld",treat2);

    return 0;




}