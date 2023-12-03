
#include<stdio.h>
#include<string.h>
char stack[100],data[100],postfix[100];
int i,c, result=0,top=-1, count=0;

void push (int value){
    if (top == sizeof(stack)-1 )
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
       // printf("\n \t %d popped ",stack[top]);
        top--;
    }
}
int precedence(char c ){
    switch(c){
        case '(':
        case '[':
        case '{':
        return -2;
        case '^':
        return 3;
        case '/':
        case '*':
        return 2;
        case '-':
        case '+':
        return 1;
        default:
        return-1;
    }
}
void intop(){
    for (i=0;data[i]!='\0';i++){

        if (data[i]==')'||data[i]==']' || data[i]=='}'){

            while (stack[top]!='(' && stack[top]!='[' && stack[top]!='{' && top!=-1){
                postfix[count++]=stack[top--];
            }
            if ((stack[top]=='('&& data[i]==')'|| stack[top]=='['&& data[i]==']'||stack[top]=='{'&& data[i]=='}')&& top!=-1)
            pop();
            else{
                printf("statement invalid ");
                result=1;
                break;
            }
            continue;
        }

        c= precedence(data[i]);
        if (c==-2)
        push(data[i]);
        else if (c==-1){
        postfix[count++]=data[i];}
        else if (c>precedence(stack[top])){
        push(data[i]);}
        else {
            while(!(c>precedence(stack[top])))
                postfix[count++]=stack[top--];
            
            push(data[i]);
        }
    }
    
    while(top!=-1){
        if (stack[top]=='(' || stack[top]=='[' || stack[top]=='{'){
            printf("invalid statement ");
            result=1;
            break;
        }
        postfix[count++]=stack[top--];
    }

    if (result!=1){
        printf ("\npostfix expression is \n");
        printf("%s",postfix);
    } 
}

int main(){

    printf("Enter the expression\n");
    fgets(data, sizeof(data),stdin);
    data[strcspn(data, "\n")] = 0;
    intop();
}
