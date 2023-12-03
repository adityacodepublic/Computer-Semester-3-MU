#include<stdio.h>

int front = -1, queue[10];
int rear = -1;

void enque(int value){
    if (rear == 9)
        printf("Overflow");
    
    else {
        if(front == rear == -1){
            front = rear =0;
        }
        queue[rear++]=value;        
    }
}


int deque(){
    int value;
    if (front>=rear)
        printf("Empty");
    
    else {
        value=queue[front++];
        return value;
    }
}


void display(){
    int i=rear-1;
    if (front == rear == -1){
        printf("The stack is empty");}

    else {
        printf("\n\tThe queue is\n");

        for (i;i>=front;i--){
            printf(" %d ", queue[i]);
        }
    }
}

int main(){
    enque(2);
    enque(3);
    enque(7);
    enque(4);
    enque(5);

    display();

    deque();
    deque();
    deque();

    display();

    enque(9);
    enque(8);

    display();

    deque();
    deque();

    display();



}
