#include <iostream>
using namespace std;

class DequeueArrayImplementation
{
    int front, rear, size;
    int *arr;

public:
    DequeueArrayImplementation(int n)
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
        return ((rear + 1) % size == front);
    }

    void push_front(int x)
    {
        if (isEmpty())
        {
            front = rear = 0;
            arr[front] = x;
        }
        else if (isFull())
        {
            cout << "Dequeue Overflow !!" << endl;
        }
        else
        {
            front = (front - 1 + size) % size;
            arr[front] = x;
        }
    }

    void push_back(int x)
    {
        if (isEmpty())
        {
            front = rear = 0;
            arr[rear] = x;
        }
        else if (isFull())
        {
            cout << "Dequeue Overflow !!" << endl;
        }
        else
        {
            rear = (rear + 1) % size;
            arr[rear] = x;
        }
    }

    void pop_front()
    {
        if (isEmpty())
        {
            cout << "Dequeue Underflow !!" << endl;
        }
        else
        {
            if (front == rear)
            {
                front = rear = -1;
            }
            else
            {
                front = (front + 1) % size;
            }
        }
    }

    void pop_back()
    {
        if (isEmpty())
        {
            cout << "Dequeue Underflow !!" << endl;
        }
        else
        {
            if (front == rear)
            {
                front = rear = -1;
            }
            else
            {
                rear = (rear - 1 + size) % size;
            }
        }
    }

    int start()
    {
        if (isEmpty())
        {
            return -1;
        }

        return arr[front];
    }

    int end()
    {
        if (isEmpty())
        {
            return -1;
        }

        return arr[rear];
    }
};