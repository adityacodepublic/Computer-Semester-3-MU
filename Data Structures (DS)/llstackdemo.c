#include<stdio.h>
#include<stdlib.h>


struct node{
    int data;
    struct node * next;
};

struct node * top;

void push( int value ){
    struct node * new = malloc(sizeof(struct node));

    new->data = value;
    new->next = top;
    top = new;
}

void pop(){
    struct node * temp;
    if (top == NULL )
        printf("Stack is empty");
    else{
        printf("Element popped is %d ", top->data);
        temp = top;
        top=top->next;
        free (temp);
    }
}

void display(){
    struct node*temp=top;
    while(temp!=NULL){
        printf("%d->",temp->data);
        temp=temp->next;}
    printf("NULL");
}

int main() {
    int choice, value;
    printf("\nImplementation of Stack using Linked List\n");
    while (1) {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("\nEnter the value to insert: ");
            scanf("%d", &value);
            push(value);
            break;
        case 2:
            pop();
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

