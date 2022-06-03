#include<stdio.h>
#include<stdlib.h>
    struct node {
        int data;
        struct node *next;
    };
    struct node *front = NULL;
    struct node *rear = NULL;
    int sizeOfQueue = 0;
    int isEmpty(){
        if(sizeOfQueue == 0){
            return 1;
        }
        else{
            return 0;
        }
    }
    //implementing enqueue method
    //insert at last using rear

    void enqueue(int element){
        //creating a node
        struct node *link = (struct node*)malloc(sizeof(struct node));
        //setting data of node
        link -> data = element;
        //setting next to null
        link -> next = NULL;
        if(isEmpty()){
            front = link;
            rear = link;
        }
        else{
            rear -> next = link;
            rear = link;
        }
        //size will increase
        sizeOfQueue++;
    }

    
    int dequeue(){
        if(isEmpty()){
             return 0;
        }
        else {           
            //getting the data of deleted node
            int dataOfDeletedNode = front -> data;
            front = front -> next;
            if(front == NULL){
                rear = NULL;
            }
            sizeOfQueue--;
            return dataOfDeletedNode;
        }

    }
    int peek(){
        if(isEmpty()){
            return 0;
        }
        else{
            return front -> data;
        }
    }
    //this method will give us the size of queue i.e. no of elements in queue
    int size(){
        return sizeOfQueue;
    }
    // need not to be part of queue
    // but checking our queue
    void traverse(){
        struct node *temp = front;
        while(temp != NULL){
            printf("%d --> ",temp -> data);
            temp = temp -> next;
        }
    printf("NULL \n");
    }
    void main(){
        printf("deleted element is = %d\n",dequeue());
        printf("size of queue = %d\n",size());
        printf("element at the front = %d\n",peek());

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

    }