#include<stdio.h>
#include<stdlib.h>
struct node{
        int a;
        struct node*next;
    };

struct node*create_node(int data){
    struct node*cnode=(struct node*)malloc(sizeof(cnode));
    cnode->a=data;
    cnode->next=NULL;
    return cnode;
}

struct node*input(int data,struct node*head){
    struct node*nnode=create_node(data);
    if(head==NULL){
        head=nnode;
        return head;
    }
    struct node*temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=nnode;
    return head;
}

void display(struct node*ptr){
    while(ptr!=NULL){
        printf("%d\n",ptr->a);
        ptr=ptr->next;
    }
}

struct node*insert_at_first(int data1,struct node*head){
    struct node*nnode=(struct node*)malloc(sizeof(struct node*));
    nnode->a=data1;
    nnode->next=head;
    head=nnode;
    return head;
}

struct node*insert_in_between(int data1,struct node*head,int m){
    struct node*nnode=(struct node*)malloc(sizeof(struct node*));
    nnode->a=data1;
    struct node*temp=head;
    for(int i=0;i<m-2;i++){
        temp=temp->next;
    }
    nnode->next=temp->next;
    temp->next=nnode;
    return head;
}

struct node*insert_at_last(int data1,struct node*head){
    struct node*nnode=(struct node*)malloc(sizeof(struct node*));
    nnode->a=data1;
    struct node*temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=nnode;
    nnode->next=NULL;
    return head;
}


int main(){
    int n;
    struct node*nnode,*head;
    head=NULL;
    int data;
    printf("Enter the number of elements you want to enter");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&data);
        head=input(data,head);
    }

    display(head);
    int m,data1;
    printf("Enter the position at which you want to enter the element");
    scanf("%d",&m);
    printf("Enter the element");
    scanf("%d",&data1);
    if(m==1){
        head=insert_at_first(data1,head);
        display(head);
    }
    else if(m>1 && m<=n){
        head=insert_in_between(data1,head,m);
        display(head);
    }
    else if(m>n){
        head=insert_at_last(data1,head);
        display(head);
    }    

    return 0;
}
