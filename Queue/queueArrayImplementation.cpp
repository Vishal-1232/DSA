#include <iostream>
using namespace std;
// Queue Implementation using array
class Queue
{
private:
    int *arr;
    int front, rear, size;

public:
    Queue(int n)
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
        return rear == size - 1;
    }

    void push(int x){
        if(isEmpty()){
            front = rear = 0;
            arr[rear] = x;
            cout<<"Element Pushed---> "<<x<<endl;
        }else if(isFull()){
            cout<<"Queue Overflow!!!"<<endl;
        }else{
            rear++;
            arr[rear] = x;
            cout<<"Element Pushed---> "<<x<<endl;
        }
    }

    void pop(){
        if(isEmpty()){
            cout<<"Queue Underflow !!"<<endl;
        }else{
            cout<<"Element Deleted---> "<<arr[rear];
            if(front==rear){ // Only Single Element is Present
                front = rear = -1;
            }else{
                front++;
            }
        }
    }

    int front(){
        if(isEmpty()){
         cout<<"Queue is Empty!!!!!";
         return -1;   
        }

        return arr[front];
    }

    void printQueue(){
        if(isEmpty()){
            cout<<"Queue is Empty!!"<<endl;
            return;
        }
        for(int i = 0; i <= rear; i++){
            cout<<arr[i]<<" | ";
        }
        cout<<endl;
    }
};