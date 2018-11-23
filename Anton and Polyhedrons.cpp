#include<stdio.h>
#include<string.h>
char cube20[]="Icosahedron";
char cube6[]="Cube";
char cube4[]="Tetrahedron";
char cube12[]="Dodecahedron";
char cube8[]="Octahedron";



int main(void){
	int count,result=0;
	scanf("%d",&count);
	char word[13];
	memset(word,'\0',sizef(word));
	for(int i=0;i<count;i++){
	scanf("%s",word);
	if(!strcmp(word,cube20))
	result+=20;
	if(!strcmp(word,cube6))
	result+=6;
	if(!strcmp(word,cube4))
	result+=4;
	if(!strcmp(word,cube12))
	result+=12;
	if(!strcmp(word,cube8))
	result+=8;
	}
	printf("%d",result);
}