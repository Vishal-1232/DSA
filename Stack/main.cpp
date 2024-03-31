#include <iostream>
#include "stackImplementationUsingArrays.cpp"
#include "stackImplementationUsingLinkedList.cpp"
using namespace std;

int main()
{
    Stack s(3);
    s.push(1);
    s.push(1);
    s.push(1);
    s.push(1);
    cout << s.peek() << endl;

    StackLL sll;
    sll.push(1);
    sll.push(2);
    sll.pop();
    cout << sll.peek() << endl;

    return 0;
}