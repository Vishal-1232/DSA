#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class QueueL
{
private:
    Node *front;
    Node *rear;

public:
    QueueL()
    {
        front = rear = NULL;
    }
    bool isEmpty()
    {
        return front == NULL;
    }

    void push(int x)
    {
        if (isEmpty())
        {
            front = rear = new Node(x);
            cout << "Element Pushed---> " << x << endl;
        }
        else
        {
            rear->next = new Node(x);
            if(rear->next==NULL){ // if Heap memory is also full
                cout<<"Queue Overflow!!"<<endl;
                return;
            }
            rear = rear->next;
            cout << "Element Pushed---> " << x << endl;
        }
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Queue Underflow !!" << endl;
        }
        else
        {
            cout << "Element Deleted---> " << front->data << endl;
            Node *temp = front;
            front = front->next;
            delete temp;
        }
    }

    int getFrontElement()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty!!!!!" << endl;
            return -1;
        }

        return front->data;
    }

    void printQueue()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty!!" << endl;
            return;
        }
        Node* temp = front;
        while(temp){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout << endl;
    }
};