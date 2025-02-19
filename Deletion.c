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

void Delete_first(struct node*ptr){
    struct node*temp;
    temp=ptr;
    ptr=ptr->next;
    free(ptr);
}

void Delete_last(struct node*ptr){
    struct node*temp,*prev;
    temp=ptr;
    while(temp->next!=0){
        prev=temp;
        temp=temp->next;

    }
    free(temp);
    prev->next=0;
}

void Delete_at_index(struct node*ptr,int loc){
    struct node*temp,*prev;
    temp=ptr;
    int i=1;
    while(i<loc){
        prev=temp;
        temp=temp->next;
        i++;
    }
    prev->next=temp->next;
    temp->next=0;
    free(temp);
}


int main(){
    
    struct node*head,*first,*second,*third;
    head=(struct node*)malloc(sizeof(struct node*));
    first=(struct node*)malloc(sizeof(struct node*));
    second=(struct node*)malloc(sizeof(struct node*));
    third=(struct node*)malloc(sizeof(struct node*));
    head->a=7;
    head->next=first; 
    first->a=8;
    first->next=second;
    second->a=9;
    second->next=third;
    third->a=10;
    third->next=NULL;
    int n;
    display(head);
    Delete_last(head);
    display(head);
    printf("Enter the position of element you want to delete");
    scanf("%d",&n);
    Delete_at_index(head,n);
    display(head);

    return 0;
}
