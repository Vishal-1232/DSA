#include <bits/stdc++.h>
#include "queueArrayImplementation.cpp"
#include "circularQueueArrayImplementation.cpp"
#include "queueLinkedListImplementation.cpp"
#include "dequeueLinkedListImplementation.cpp"

using namespace std;

int main()
{
    Queue q = Queue(5);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.pop();
    q.push(5);
    q.push(6);

    CircularQueue cq = CircularQueue(5);
    cq.push(1);
    cq.push(2);
    cq.push(3);
    cq.push(4);
    cq.pop();
    cq.push(5);
    cq.push(6);

    QueueL ql = QueueL();
    ql.push(1);
    ql.push(2);
    ql.push(3);
    ql.push(4);
    ql.pop();
    ql.push(5);
    ql.push(6);

    Dequeue dq;
    dq.push_front(4);
    dq.push_front(3);
    dq.push_back(5);
    dq.print();
    cout << "Front Element: " << dq.start() << endl;
    cout << "Back Element: " << dq.back() << endl;
    dq.pop_back();
    dq.pop_front();
    dq.print();
    return 0;
}