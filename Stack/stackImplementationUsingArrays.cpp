#include <iostream>
using namespace std;

class Stack
{
private:
    int size;
    int top;
    int *arr;

public:
    Stack(int n)
    {
        size = n;
        arr = new int[n];
        top = -1;
    }

    bool isEmpty()
    {
        return top == -1;
    }

    bool isFull()
    {
        return top == size - 1;
    }

    int isSize()
    {
        return top + 1;
    }

    void push(int x)
    {
        if (isFull())
        {
            cout << "Stack Overflow!!!" << endl;
        }
        else
        {
            top++;
            arr[top] = x;
            cout << "Element Pushed into Stack: " << x << endl;
        }
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow!!" << endl;
            return;
        }
        cout << "Popped: " << arr[top] << " from stack." << endl;
        top--;
    }

    int peek()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow!!" << endl;
            return -1;
        }

        return arr[top];
    }
};
