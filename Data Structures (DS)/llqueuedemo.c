#include<stdio.h> 
#include<stdlib.h>

struct node {
    int data;
    struct node * next;
};

struct node * front=NULL ;
struct node * rear=NULL;

void enqueue(int value){
    struct node * ptr = malloc(sizeof(struct node));
    ptr->data=value;
    ptr->next=NULL;
    if(front==NULL && rear==NULL){
        front=rear=ptr;
    }
    else{
        rear->next=ptr;
        rear=ptr;
    }
    printf("node inserted");
}


void dequeue(){
    if (front==NULL){
        printf("underflow");
    }
    else{
        struct node* temp = front;
        printf("\t\t%d deququed\n",temp->data);
        front=front->next;
        free(temp);
    }
}


void display(){
    struct node *temp= front;
    printf("NULL");
    while(temp!=NULL){
        printf("<-%d",temp->data);
        temp = temp->next;
    }
}


int main() {
    int choice, value;
    printf("\nImplementation of Stack using Linked List\n");
    while (1) {
        printf("\n1. enqueue\n2. dequeue\n3. Display\n4. Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("\nEnter the value to insert: ");
            scanf("%d", &value);
            enqueue(value);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("\nWrong Choice\n");
        }
    }
}