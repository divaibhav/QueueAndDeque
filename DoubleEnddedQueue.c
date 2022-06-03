#include<stdio.h>
#include<stdlib.h>
    struct node{
        int data;
        struct node *next;
        struct node *previous;
    };
    
    struct node *front = NULL;
    struct node *rear = NULL;
    int sizeOfQueue = 0;

    int isEmpty(){
        if(sizeOfQueue == 0){
            return 1;
        }
   
            return 0;
        
    }
    void enqueue(int element){
        struct node *link = (struct node*)malloc(sizeof(struct node));
        link -> data = element;
        link -> next = NULL;
        link -> previous = NULL;
        if(isEmpty()){
            front = link;
            rear = link;
        }
        else{
            rear -> next = link;
            link -> previous = rear;
            rear = link;
        }
        sizeOfQueue++;
    }

    void enqueueAtFront(int element){
        struct node *link = (struct node*)malloc(sizeof(struct node));
        link -> data = element;
        link -> next = NULL;
        link -> previous = NULL;
        if(isEmpty()){
            front = link;
            rear = link;
        }
        else{
            front -> previous = link;
            link -> next = front;
            front = link;
        }
        sizeOfQueue++;

    }

    int dequeue(){
        int dataOfDeletedNode;
        if(isEmpty()){
            return 0;
        }
        else{
             dataOfDeletedNode = front -> data;
            front = front -> next;
            if(front == NULL){
                rear = NULL;
            }
            else{
                front -> previous = NULL;
            }
        }
        sizeOfQueue--;
        return dataOfDeletedNode;
    }

    int dequeueFromRear(){
        int dataOfDeletedNode;
        if(isEmpty()){
            return 0;
        }
        else{
            dataOfDeletedNode = rear -> data;
            rear = rear -> previous;
            if(rear ==  NULL){
                front = NULL;
            }
            else{
                rear -> next = NULL;
            }
        }
        sizeOfQueue--;
        return dataOfDeletedNode;
    }

    int peekFirst(){
        if(isEmpty()){
            return 0;
        }
        return front -> data;
    }

    int peekLast(){
        if(isEmpty()){
            return 0;
        }
        return rear -> data;
    }

    int size(){
        return sizeOfQueue;
    }
    void traverse(){
        struct node *temp = front;
        while(temp != NULL){
            printf("%d <--> ", temp -> data);
            temp = temp -> next;
        }
        printf("\n");
    }

    void main(){
        printf("size of queue = %d\n" + size());
        enqueue(100);
        enqueue(200);
        enqueue(300);
        enqueueAtFront(50);
        enqueueAtFront(25);
        enqueue(400);
        traverse();
        printf("deleted node = %d\n",dequeue());
        printf("deleted node = %d\n",dequeueFromRear());
        traverse();
        printf("FIRST node = %d\n",peekFirst());
        printf("Last node = %d\n",peekLast());
    }

