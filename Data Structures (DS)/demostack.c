#include<stdio.h>
#define size 20
int top = -1, stack[size];

void push (int value){
    if (top == 19 )
      printf ("\nOverflow");

    else {
        stack[++top]=value;
    }
}

void pop(){
    if (top == -1){
        printf("underflow");
    }

    else{
        printf("\n \t %d popped ",stack[top]);
        top--;
    }
}

void display(){
    int temp = top;

    for (temp;temp!=-1; temp-1){
        printf("\n %d",stack[temp--] );
    }

    if(temp!=-1){
    printf("\n Stack empty");
    }   
}






int main (){

    push (20);
    push (22);
    push (23);
    push (24);

    display();

    pop();
    pop();

    display();

    
    
}
