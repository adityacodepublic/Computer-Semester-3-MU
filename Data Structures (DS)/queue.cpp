#include <iostream>
#define SIZE 5
using namespace std;

struct Queue {
  int items[SIZE], front, rear;

  Queue() {
    front = -1;
    rear = -1;
  }

  bool isFull() {
    if (front == 0 && rear == SIZE - 1) {
      return true;
    }
    return false;
  }

  bool isEmpty() {
    if (front == -1)
      return true;
    else
      return false;
  }

  void enQueue(int element) {
    if (isFull()) {
      cout << "Queue is full";
    } else {
      if (front == -1) front = 0;
      rear++;
      items[rear] = element;
      cout << endl
         << "Inserted " << element << endl;
    }
  }

  int deQueue() {
    int element;
    if (isEmpty()) {
      cout << "Queue is empty" << endl;
      return (-1);
    } else {
      element = items[front];
      if (front >= rear) {
        front = -1;
        rear = -1;
      } /* Q has only one element, so we reset the queue after deleting it. */
      else {
        front++;
      }
      cout << endl
         << "Deleted -> " << element << endl;
      return (element);
    }
  }

  void display() {
    /* Function to display elements of Queue */
    int i;
    if (isEmpty()) {
      cout << endl
         << "Empty Queue" << endl;
    } else {
      cout << endl
         << "Front index-> " << front;
      cout << endl
         << "Items -> ";
      for (i = front; i <= rear; i++)
        cout << items[i] << "  ";
      cout << endl
         << "Rear index-> " << rear << endl;
    }
  }
};

int main() {
    int a=1;
    Queue q;
    printf("\n------------- Welcome to Queue --------------\n1.Enter in Queue\n2.dequeue\n3.exit\n");
    while (a!=4){
        printf("\n Enter command number:");
        scanf("\n%d",&a);
        switch(a){
            case 2:
            cout << q.deQueue() << "removed \n";
            break;
            case 1:
            cout<<"\n Enter Value to add:\n";
            scanf("%d",&a);
            q.enQueue(a);
            a=1;
            break;
            case 3:
            q.display();
            break;
            case 4:
            break;
            default:
            printf("\nInvalid Statement");
        }
    } 
    return 0;
}

