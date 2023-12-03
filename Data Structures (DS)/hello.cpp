#include<stdio.h>

void sort (int a[],int n){
    int i,j,temp;
    for(i=0;i<n;i++){
        for(j=1+i;j<n;j++){
            if(a[i]>a[j]){
                temp= a[i];
                a[i]=a[j];
                a[j]= temp;
            }
        }
    }
}

void print(int a[], int n){
    int i;
    for(i=0;i<n;i++){
    printf(" %d",a[i] );
    }
}


int main(){
    int i,n,a[100];
    printf("Tell the no of elements");
    scanf("%d", &n);
    
    for(i=0;i<n;i++){
    printf("Enter the Values in the array:");
    scanf("%d",&a[i]);
    }

    printf("The entered array is:\n");
    print(a,n);
    sort(a,n);
    printf("\n\nThe sorted array is:\n");
    print(a,n);   
}