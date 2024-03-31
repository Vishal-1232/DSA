#include <iostream>
#include "node.cpp"

class StackLL
{
private:
    Node *top;
    int size;

public:
    StackLL()
    {
        top = NULL;
        size = 0;
    }

    bool isEmpty()
    {
        return top == NULL;
    }

    void push(int x)
    { // Insert in the Begining of list
        Node *temp = new Node(x);
        if (temp == NULL)
        {
            cout << "Stack Overflow!!" << endl;
            return;
        }
        temp->next = top;
        top = temp;
        size++;
        cout << "Element Pushed: " << x << endl;
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack UnderFlow!!!" << endl;
            return;
        }
        Node *temp = top;
        top = top->next;
        cout << "Element Popped: " << temp->data << endl;
        delete temp;
        size--;
    }

    int peek()
    {
        if (isEmpty())
        {
            cout << "Stack UnderFlow!!!" << endl;
            return -1;
        }

        return top->data;
    }

    int isSize()
    {
        return size;
    }
};
