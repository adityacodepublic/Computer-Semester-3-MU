#include <bits/stdc++.h>
using namespace std;
 
struct Queue {
    stack<int> s1, s2;
 
    // Enqueue an item to the queue
    void enQueue(int x)
    {
        // Push item into the first stack
        s1.push(x);
    }
 

    int deQueue()
    {
        // if both stacks are empty
        if (s1.empty() && s2.empty()) {
            printf("queue empty");
        }
        // if s2 is empty, move elements from s1
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        // return the top item from s2
        int x = s2.top();
        s2.pop();
        return x;
    }
};
 
// Driver code
int main()
{   int a=1;
    Queue q;
    printf("\n------------- Welcome to Queue --------------\n1.Enter in Queue\n2.dequeue\n3.exit\n");
    while (a!=3){
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
            break;
            default:
            printf("\nInvalid Statement");
        }
    } 
    return 0;
}




