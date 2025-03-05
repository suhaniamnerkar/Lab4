#include<stdio.h>
#include<stdlib.h>
struct node{
        int a;
        struct node*next;
    };


struct node*create_node(int data){
    struct node*cnode=(struct node*)malloc(sizeof(struct node*));
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

struct node*delete_at_first(struct node*head){
    head=head->next;
    return head;
}

/*void Delete_last(struct node*ptr){
    struct node*temp,*prev;
    temp=ptr;
    while(temp->next!=0){
        prev=temp;
        temp=temp->next;

    }
    free(temp);
    prev->next=0;
}*/

struct node*delete_at_index(struct node*head,int m){
    struct node*temp=head;
    for(int i=1;i<m-1;i++){
        temp=temp->next;
    }
    temp->next=temp->next->next;
    return head;
}

struct node*delete_at_last(struct node*head,int n){
    struct node*temp=head;
    for(int i=1;i<n-1;i++){
        temp=temp->next;
    }
    temp->next=NULL;
    return head;
}

int main(){
    int n,m;
    struct node*nnode,*head;
    head=NULL;
    int data;
    printf("Enter the number of elements you want to enter");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&data);
        head=input(data,head);
    }
    printf("Enter the position of element you want to delete:");
    scanf("%d",&m);

    if(m==1){
        head=delete_at_first(head);
        display(head);
    }
    else if(m>1 && m<n){
        head=delete_at_index(head,m);
        display(head);
    }
    else if(m==n){
        head=delete_at_last(head,n);
        display(head);
    }
}
