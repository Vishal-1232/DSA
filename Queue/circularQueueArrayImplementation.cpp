#include <iostream>
using namespace std;

// Circular Queue Implementation using array
class CircularQueue
{
private:
    int *arr;
    int front, rear, size;

public:
    CircularQueue(int n)
    {
        arr = new int[n];
        size = n;
        front = rear = -1;
    }

    bool isEmpty()
    {
        return front == -1;
    }

    bool isFull()
    {
        return (rear+1)%size == front;
    }

    void push(int x){
        if(isEmpty()){
            front = rear = 0;
            arr[rear] = x;
            cout<<"Element Pushed---> "<<x<<endl;
        }else if(isFull()){
            cout<<"Circular Queue Overflow!!!"<<endl;
        }else{
            rear = (rear+1)%size;
            arr[rear] = x;
            cout<<"Element Pushed---> "<<x<<endl;
        }
    }

    void pop(){
        if(isEmpty()){
            cout<<"Circular Queue Underflow !!"<<endl;
        }else{
            cout<<"Element Deleted---> "<<arr[rear]<<endl;
            if(front==rear){ // Only Single Element is Present
                front = rear = -1;
            }else{
                front = (front+1)%size;
            }
        }
    }

    int getFrontElement(){
        if(isEmpty()){
         cout<<"Circular Queue is Empty!!!!!"<<endl;
         return -1;   
        }

        return arr[front];
    }

    void printQueue(){
        if(isEmpty()){
            cout<<"Circular Queue is Empty!!"<<endl;
            return;
        }
        for(int i = 0; i <= rear; i++){
            cout<<arr[i]<<" | ";
        }
        cout<<endl;
    }
};