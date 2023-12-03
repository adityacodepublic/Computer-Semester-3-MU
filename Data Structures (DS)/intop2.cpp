#include <stdio.h>
#include<conio.h>
#include<string.h>


int top=-1,i,suces=0,pre, count=0,c;
char postfx[100],stack[100],data[100];



/* Check if the stack is empty */
int isempty(){
   if(top == -1)
      return 1;
   else
      return 0;
}

/* Check if the stack is full*/
int isfull(){
   if(top == 100)
      return 1;
   else
      return 0;
}

/* Function to delete from the stack */
void pop(){
   if(!isempty()) {;
      top = top - 1;
   } else {
      top=-1;
      printf("Could not retrieve data, Stack is empty.\n");
   }
}

/* Function to insert into the stack */
void push(int data){
   if(!isfull()) {
      top = top + 1;
      stack[top] = data;
   } else {
      printf("Could not insert data, Stack is full.\n");
   }
}


int precedence(char d){
    switch(d){
    case '(':
    case '[':
    case '{':
    return -2;
    case '^':
    return 3;
    break;
    case '*':
    case '/':
    return 2;
    break;
    case '+':
    case '-':
    return 1;
    break;
    default:
    return -1;}
}


    

void postfix(char*data){
    for(i=0;data[i]!=0;i++){
        if (data[i]==')'||data[i]==']'||data[i]=='}'){
            while(!isempty() && (stack[top]!='('&&stack[top]!='['&&stack[top]!='{')){
                postfx[count++]=stack[top--];
            }
            if(isempty()){
                printf("Statement invalid");
                suces=1;
                break;
            }
            if((stack[top]=='(' && data[i]==')') || (stack[top]=='[' && data[i]==']') || (stack[top]=='{' && data[i]=='}')){
                pop();
            }
            else{
                printf("Statement invalid");
                suces=1;
                break;
            }
        }
        if (suces==1){
            printf("statement invalid");
            break;}

       
        c = precedence(data[i]);
        if (c==-2)
            push(data[i]);
        else if (c==-1)
            { postfx[count++]=data[i];}
        else if(isempty() || c>precedence(stack[top])){
              push(data[i]); }
        else {
              while (!isempty() && !(c>(precedence(stack[top])))){
              postfx[count++]=stack[top--];}
              push(data[i]);
        }
    }

    while(!isempty()){
        postfx[count++]=stack[top--];   
    }
}

int main() {
    printf("Enter the Infix Expression \n");
    fgets(data, 100, stdin);
    postfix(data);
    printf("The Postfix Expression is \n");
    for(i=0;postfx[i]!=0;i++){
    printf("%c",postfx[i]);}

    return 0;
}
