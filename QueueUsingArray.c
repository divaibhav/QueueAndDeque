#include<stdio.h>
#define SIZE 6
int queue[SIZE];
int front = 0;
int rear = 0;
int isEmpty(){
    if(rear == front){
        return 1;
    }
    else{
        return 0;
    }
}
int enqueue(int element){
    if(rear < SIZE){
        queue[rear] = element;
        rear ++;
        return 1;
    }
    else{
        printf("Cannot insert data as queue is full\n");
        return 0;
        
    }
}
int dequeue(){
    if(isEmpty()){
         printf("Cannot Delete data as queue is Empty\n");
        return 0;
        
    }
    else{
        int data = queue[front];
        front++;
        return data;
    }
}
int size(){
    return rear-front;
}
int peek(){
    if(isEmpty()){
        return 0;
    }
    else{
        return queue[front];
    }
}
void traverse(){
    for(int i = front; i < rear; i++){
        printf("%d, " , queue[i]);
    }
    printf("\n");
}
void main(){
   printf("deleted element is = %d\n",dequeue());
        printf("size of queue = %d\n",size());
        printf("element at the front = %d\n",peek());
        traverse();
        enqueue(100);
        enqueue(200);
        enqueue(300);
        enqueue(500);
        enqueue(700);
        traverse();
        printf("deleted element is = %d\n",dequeue());
        printf("size of queue = %d\n",size());
        printf("element at the front = %d\n",peek());
        traverse();
        printf("deleted element is = %d\n",dequeue());
        printf("deleted element is = %d\n",dequeue());
        printf("deleted element is = %d\n",dequeue());
        printf("deleted element is = %d\n",dequeue());
        enqueue(900);
         printf("size of queue = %d\n",size());
        printf("deleted element is = %d\n",dequeue());
         enqueue(1900);
        printf("deleted element is = %d\n",dequeue());
         printf("size of queue = %d\n",size());
}