#include <stdio.h>
#include<string.h>

int MAXSIZE = 8,top=-1,i,len;
char stack[100],data[100],da;




/* Check if the stack is empty */
int isempty(){
   if(top == -1)
      return 1;
   else
      return 0;
}

/* Check if the stack is full*/
int isfull(){
   if(top == MAXSIZE)
      return 1;
   else
      return 0;
}

/* Function to delete from the stack */
void pop(){
   if(!isempty()) {;
      top = top - 1;
   } else {
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



void parenthesis( char * d ){
   for(i=0;data[i]!='\0';i++){

      if(data[i]=='('||data[i]=='['||data[i]=='{'){
         push(data[i]);}

      else if (data[i]==')' && stack[top] =='('|| data[i]==']' && stack[top]=='['|| data[i]=='}' && stack[top]=='{'){
         pop();}
      else if (data[i]==')'||data[i]==']'||data[i]=='}' && top==-1) {
         printf("------------------paranthesis not matching-------------------");
         i=-1;
         break;
      }
   }
   if (i!=-1){
   if (top==-1){
      printf("------------------Paranthes is Matching-------------------"); }
   else printf("paranthesis not matching");}
}

/* Main function */
int main(){
   printf("Enter the expression");
   fgets(data,sizeof(data),stdin);
   parenthesis(data);

   }

