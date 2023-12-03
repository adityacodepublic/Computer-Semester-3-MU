#include<stdio.h>


#define N 20			//defining the size of queue

int s[N],i,q, top = -1;

int pop ()				//function to remove an element from stack
{
  return s[top--];
}

void push (int x)			//function to insert an element into stack
{
  if (top == N - 1)
    printf ("Stack is Full");
  else
    {
      top++;
      s[top] = x;
    }
}

void enqueue (int x)		
{
  push (x);
}

void display ()			//function to print elements of a queue
{
  int i;
  for (i = 0; i <= top; i++)
    printf (" %d ", s[i]);
}

int dequeue ()		
{
  int data, res;
  if (top == -1)
    printf ("Queue is Empty");
  else if (top == 0)
    return pop ();
  data = pop ();
  res = dequeue ();
  push (data);
  return res;

}

int main ()
{ 
  i=0;
  q=0;
        printf("---------------queue--------------\n");
  while(i!=4){
      printf("\n1. enqueue\n");
      printf("2. dequeue\n");
      printf("3. display\n");
      printf("4. exit\n");
      scanf("%d",&i);
      if (i==1){
        printf("\n enter value for enqueue:\n");
        scanf("%d",&q);  
        enqueue (q);      
      }
      if (i==2){
        //dequeue ();
        printf("%d",dequeue());     
      }
      if(i==3){
      printf("        ------Queue-----\n");
      display();}


    

  }


}