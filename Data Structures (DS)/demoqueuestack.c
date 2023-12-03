#include<stdio.h>

int top=-1, stack[20],i,j;

void push(int value){
    stack[++top]=value;
}

int pop(){
    return stack[top--];
};

void enqueue(int val){
    push(val);
}

int deque(){
    int data,res;
    if (top==-1)
        printf("underflow");
    else if (top==0){
        return pop();
    }
    data=pop();
    res = deque();
    push(data);
    return res;
};


void display(){
    int i=top;
    for(i;i>=0;i--){
        printf("%d ",stack[i]);
    }
}


int main(){

    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    enqueue(60);
    printf("\n");

    display();
        printf("\n");

    printf("%d ",deque());
    printf("%d ",deque());
    printf("%d ",deque());
    printf("%d ",deque());
    printf("%d ",deque());
    printf("%d ",deque());
    printf("%d ",deque());

    printf("\n");

    display();


    printf("\n");



}