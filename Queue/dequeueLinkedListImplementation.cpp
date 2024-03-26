#include <iostream>
using namespace std;

class DoublyNode
{
public:
    int data;
    DoublyNode *next;
    DoublyNode *prev;

    DoublyNode(int x)
    {
        data = x;
        next = prev = NULL;
    }
};

class Dequeue
{
private:
    DoublyNode *rear;
    DoublyNode *front;

public:
    Dequeue()
    {
        rear = front = NULL;
    }

    void push_front(int x)
    {
        DoublyNode *newNode = new DoublyNode(x);
        if (front == NULL)
        {
            front = rear = newNode;
        }
        else
        {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }
    }

    void push_back(int x)
    {
        DoublyNode *newNode = new DoublyNode(x);
        if (front == NULL)
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            newNode->prev = rear;
            rear = newNode;
        }
    }

    void pop_front()
    {
        if (front == NULL)
        {
            cout << "Dequeue Underflow!!!" << endl;
        }
        else
        {
            DoublyNode *temp = front;
            front = front->next;
            delete temp;

            if (front)
            {
                front->prev = NULL;
            }
            else
            {
                rear = NULL;
            }
        }
    }

    void pop_back()
    {
        if (front == NULL)
        {
            cout << "Dequeue Underflow!!!" << endl;
        }
        else
        {
            DoublyNode *temp = rear;
            rear = rear->prev;
            delete temp;

            if (rear)
            {
                rear->next = NULL;
            }
            else
            {
                front = NULL;
            }
        }
    }

    int start()
    {
        if (front == NULL)
        {
            cout << "Dequeue is already Empty!!" << endl;
            return -1;
        }

        return front->data;
    }

    int back()
    {
        if (front == NULL)
        {
            cout << "Dequeue is already Empty!!" << endl;
            return -1;
        }

        return rear->data;
    }

    void print()
    {
        DoublyNode *temp = front;
        while (temp)
        {
            cout << temp->data << "-->";
            temp = temp->next;
        }
        cout << endl;
    }
};
