#include<stdio.h>
#include<stdlib.h>
struct node{
        int a;
        struct node*next;
    };
void display(struct node*ptr){
    while(ptr!=NULL){
        printf("Element: %d\n",ptr->a);
        ptr=ptr->next;
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
    head->next=first; 
    first->a=8;
    first->next=second;
    second->a=9;
    second->next=NULL;

    display(head);

    return 0;
}
