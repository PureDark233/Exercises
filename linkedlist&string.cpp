#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef char ElemType;
struct Node{
	ElemType data;
	struct Node* next;
};

typedef struct Node LNode;
typedef struct Node* LinkedList;


void LinkedListCreate(LinkedList &L,ElemType a[],int n){
	LinkedList pre=L;
	L=(LNode*)malloc(sizeof(LNode));
	if(L==NULL){
		printf("Failure!");
		exit(0);
	}
	L->next=NULL;
	LinkedList tail=L;
	for(int i=0;i<n;i++){
		LinkedList p=(LNode*)malloc(sizeof(LNode));
		if(p==NULL){
		    printf("Failure!");
		    exit(0);
		}
		p->data=a[i];
		p->next=NULL;
		tail->next=p;
		tail=p;
	
	}
}

char LinkedListSearch(LinkedList &X,LinkedList &Y){
	LinkedList p=X,q=Y;
	p=p->next;
	q=q->next;
	
	while(p!=NULL){
		int status=0;
		while(q!=NULL){
			if(q->data==p->data)
			status=1;
			
			q=q->next;
		}
		if(!status)
		return p->data;
		q=Y->next;
		p=p->next;
	}
	printf("They are same.");
	return 0;
}
	
int main(void){
	char a[30],b[30];
	LinkedList X,Y;
    scanf("%s%s",a,b);
	LinkedListCreate(X,a,strlen(a));
	LinkedListCreate(Y,b,strlen(b));
	printf("%c",LinkedListSearch(X,Y));
	return 0;
}

