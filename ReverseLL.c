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

void reverse(struct node*head){
    struct node*prevnode,*currentnode,*nextnode;
    prevnode=0;
    currentnode=nextnode=head;
    while(nextnode!=NULL){
        nextnode=nextnode->abc;
        currentnode->abc=prevnode;
        prevnode=currentnode;
        currentnode=nextnode;
    }
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

    display(head);
    reverse(head);
    display(head);

    return 0;
}
