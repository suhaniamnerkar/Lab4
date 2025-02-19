#include<stdio.h>
#include<stdlib.h>
struct node{
        int a;
        struct node*abc;
    };
void display(struct node*ptr){
    while(ptr!=NULL){
        printf("Element: %d\n",ptr->a);
        ptr=ptr->abc;
    }
}

struct node*insertatfirst(struct node*head,int data){
    struct node*ptr=(struct node*)malloc(sizeof(struct node));
    ptr->abc=head;
    ptr->a=data;
    head=ptr; 
    return ptr;
}

struct node*insertinbetween(struct node*head,int data,int n){
    struct node*ptr=(struct node*)malloc(sizeof(struct node));
    struct node*p=head;
    ptr->a=data;
    int i=1;
    while(i<n){
        p=p->abc;
        i++;
    }
    ptr->abc=p->abc;
    p->abc=ptr;
}

struct node*insertatlast(struct node*head,int data){
    struct node*ptr=(struct node*)malloc(sizeof(struct node));
    struct node*p=head;
    int i=1;
    while(p->abc!=0){
        p=p->abc;
    }
    p->abc=ptr;
    p->a=data;
}

int main(){
    
    struct node*head;
    struct node*first;
    struct node*second;
    head=(struct node*)malloc(sizeof(struct node*));
    first=(struct node*)malloc(sizeof(struct node*));
    second=(struct node*)malloc(sizeof(struct node*));

    head->a=7;
    head->abc=first; 
    first->a=8;
    first->abc=second;
    second->a=9;
    second->abc=NULL;
    int n;
    display(head);
    head=insertatfirst(head,6);
    display(head);
    printf("Enter the index of inserting new element");
    scanf("%d",&n);
    insertinbetween(head,5,n);
    display(head);
    insertatlast(head,10);
    display(head);

    return 0;
}
