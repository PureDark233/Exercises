struct Node{
    ElemType data;
    struct Node *next;
};
typedef struct Node LNode;
typedef struct Node *LinkedList;

void LinkedListInit(Linkedlist L){
    L=(LNode *)malloc(sizeof(LNode));
    if(L==NULL){
        printf("Failure\n");
        exit(0);
    }
    L->next=NULL;
}

int LinkedListLength(LinkedList L){
    LNode *p;
    p=L->next;
    j=0;
    while(p!=NULL){
        j++;
        p=p->next;
    }
    return j;
}

LinkedList LinkedListGet(LinkedList L, int i){
    LNode *p;
    p=L->next;
    j=1;
    while((p!=NULL)&&(j<i)){
        p=p->next;
        j++;
    }
    return p;
}

void LinkedListCreate(LinkedList L, ElemType a[n]){
    for(i=0;i<n;i++){
        p=(LNode *)malloc(sizeof(LNode));
        if(L==NULL){
            printf("Failure\n");
            exit(0);
        }
        p->data=a[i];
        p->next=L->next;
        L->next=p;
    }
}

void LinkedListInsert(LinkedList L,LinkedList p,Elemtype e){
    q=
}

int main(void){
    int m[5]={1,3,5,7,9},n[5]={2,4,6,8,10};
    LinkedList a,b,c;
    LinkedListInit(a);
    LinkedListInit(b);
    LinkedListInit(c);
    LinkedListCreate(a,m[5]);
    LinkedListCreate(b,n[5]);
    for




}