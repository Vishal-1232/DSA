#include <iostream>
#include <queue>
using namespace std;

class heap
{
private:
    int arr[100];
    int size;

public:
    heap()
    {
        size = 0;
        arr[0] = -1;
    }
    void insert(int val) //O(log N)
    {
        size++;
        int index = size;
        arr[index] = val;
        while (index > 1)
        {
            int parent = index / 2;
            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }
    void deleteFromHeap() //O(log N)
    {
        if (size == 0)
        {
            cout << "Heap is already Empty  !! " << endl;
            return;
        }
        // step 1: put last element into first index
        arr[1] = arr[size];
        // step 2: remove last element
        size--;
        // step 3: take root node to its correct position
        int parentIndex = 1;
        while (parentIndex < size)
        {
            int leftChildIndex = 2 * parentIndex;
            int rightChildIndex = 2 * parentIndex + 1;

            if (leftChildIndex < size && arr[parentIndex] < arr[leftChildIndex])
            {
                swap(arr[parentIndex], arr[leftChildIndex]);
                parentIndex = leftChildIndex;
            }
            else if (rightChildIndex < size && arr[parentIndex] < arr[rightChildIndex])
            {
                swap(arr[parentIndex], arr[rightChildIndex]);
                parentIndex = rightChildIndex;
            }
            else
            {
                return;
            }
        }
    }
    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left <= n && arr[largest] < arr[left])
    {
        largest = left;
    }
    if (right <= n && arr[largest] < arr[right])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    int size = n;
    while (size > 1)
    {
        // step1 : swap
        swap(arr[size], arr[1]);
        size--;
        // step2 : heapify
        heapify(arr, size, 1);
    }
}

int main()
{
    heap h;
    //----------Insertion
    h.insert(50);
    h.insert(96);
    h.insert(40);
    h.insert(100);
    h.print();
    //--------- Deletion
    h.deleteFromHeap();
    h.print();
    //-------heapify Algo
    int arr[] = {-1, 54, 53, 55, 52, 50};
    int n = 5;
    // heap creation
    for (int i = n / 2; i > 0; i--) // (n/2)+1 to n already heap h because they are leaf nodes
    {
        heapify(arr, n, i);
    }
    cout << "Printing Heap " << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    //---------------------------heapSort
    heapSort(arr, n);
    cout << "Printing sorted Heap " << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    //-----------Priority Queue(STL for heap)
    priority_queue<int> pq; //max heap
    pq.push(4);
    pq.push(2);
    pq.push(5);
    pq.push(3);
    cout << "\nElement at top : " << pq.top() << endl;
    pq.pop();
    cout << "Element at top after popping : " << pq.top() << endl;
    cout << "Size of proirity queue : " << pq.size() << endl;
    if (pq.empty())
    {
        cout << "priority queue is empty\n";
    }
    else
    {
        cout << "Priority queue not empty\n";
    }
    // Min heap
    priority_queue<int, vector<int>, greater<int>> minHeap;
    minHeap.push(4);
    minHeap.push(2);
    minHeap.push(5);
    minHeap.push(3);
    cout << "\nElement at top : " << minHeap.top() << endl;
    minHeap.pop();
    cout << "Element at top after popping : " << minHeap.top() << endl;
    cout << "Size of min heap : " << minHeap.size() << endl;
    if (minHeap.empty())
    {
        cout << "min heap is empty\n";
    }
    else
    {
        cout << "min heap not empty\n";
    }
    return 0;
}