#include<stdio.h>

int main(void){
    long long int num[26]={0};
    int etry;
    scanf("%d",&etry);
    char letter[etry][100001];
    getchar();
    for(int i=0;i<etry;i++){
        fgets(letter[i],100001,stdin);
    }
    
    int cost[etry];
    for(int i=0;i<etry;i++)
    scanf("%d",cost+i);
    
    for(int i=0;i<etry;i++){
        for(int count=0;;count++){
        	if(letter[i][count]!='\0')
            num[letter[i][count]-'a']+=cost[i];
            else {
			count++;
            break;
			}
        }
    }
    
    long long int result=0;
    for(int i=0;i<26;i++){
        if(num[i]>result)
        result=num[i];
    }
    
    printf("%lld",result);
    
    return 0;
}




