#include<stdio.h>
#define size 20
int top = -1,i;
char stack[size],data[size];

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
        //printf("\n \t %d popped ",stack[top]);
        top--;
    }
}





void parenthesis(){
    for (i=0;data[i]!='\0'; i++){

        if(data[i]=='('||data[i]=='['||data[i]=='{')
            push(data[i]);
        else if(data[i]==')' && stack[top]=='(' || data[i]==']' && stack[top]=='[' || data[i]=='}' && stack[top]=='{')
            pop();
        else if (data[i]==')'||data[i]==']'||data[i]=='}' && top==-1){
            printf("-------------------Parenthesis Not Matching----------------------");
            i =-1;
            break;
        }
    }

    if (i!=-1){
        if (top==-1)
        printf("------------------------Parenthesis matching----------------------------");
        else 
        printf("-------------------Parenthesis Not Matching----------------------");
    }
}


int main (){
    printf("Enter The Expression");
    fgets(data, sizeof(data), stdin);
    parenthesis();
}