#include <stdio.h>
#include<string.h>


int top=-1,i,len=0,count=0,c;
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

    //check ) ] } and removes its opposite from stack
    for(i=0;data[i]!='\0';i++){

        if (data[i]==')'||data[i]==']'||data[i]=='}'){

            while(stack[top]!='('&& stack[top]!='['&& stack[top]!='{'  && top != -1){
                postfx[count++]=stack[top--];}

            if((stack[top]=='(' && data[i]==')'|| stack[top]=='['&& data[i]==']'|| stack[top]=='{'&& data[i]=='}')&& top!=-1)
                pop();
            else{
                printf("Statement invalid");
                len=1;
                break;}
            continue;
        }



        c = precedence(data[i]);
        if (c==-2)                                   //if ( [ { then push
            push(data[i]);
        else if (c==-1){                             //is not symbol then put in postfx
            postfx[count++]=data[i];}
        else if(c>precedence(stack[top])){           
            push(data[i]); }
        else {
            while (!(c>(precedence(stack[top]))))
                postfx[count++]=stack[top--];
            push(data[i]);
        }
    }



    // empty stack at end
    while(!isempty()){
        if (stack[top]=='('||stack[top]=='['||stack[top]=='{'){
            len=1;
            printf("statement invalid");
            break;
        }
        postfx[count++]=stack[top--];   
    }


    if(len!=1){
    printf("The Postfix Expression is \n");
    printf("%s",postfx);}
}




int main() {
    printf("Enter the Infix Expression \n");
    fgets(data,100,stdin);
    data[strcspn(data, "\n")] = 0;     //ask
    postfix(data);


    return 0;
}