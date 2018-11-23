#include<stdio.h>

int main(void){
    int i,count;
    scanf("%d",&i);
    
    for(count=0;count<i;count++){
        int number=0;
        char temp=1,c;
        do c=getchar();
        while(!((c>='A'&&c<='Z')||(c>='a'&&c<='z')));
        while(c!='\n'){
            if(c!=' '&&temp==' '){
                number++;
            }
            temp=c;
            c=getchar();
        }
        printf("%d\n",number+1);
        number=0;
    }
    return 0;
}