/*
    Node --> i
    Parent(i) = i/2         (1 based indexing)
    Left child(i) = 2*i     (1 based indexing)
    Right child(i) = 2*i+1  (1 based indexing)
*/

#include <iostream>
using namespace std;
void heapfy(int arr[], int n, int i);
void build_heap(int arr[], int n);
void heap_sort(int arr[], int n);
void display(int arr[], int n);
int main()
{
    //vector<int> array;
    /* int element;
    cout << "enter elements of heap to create max heap \n";
    while (cin >> element)
    {
        array.push_back(element);
    }*/
    int array[] = {4, 1, 3, 9, 7};
    int n = sizeof(array) / sizeof(array[0]);
    heap_sort(array, n);
    display(array, n);
    return 0;
}
void build_heap(int arr[], int n)
{
    for (int i = (n / 2) - 1; i >= 0; i--) // i = n/2 bcz leaf nodes are already considered as heapified and they starts from floor(n/2+1).....n   and -1 is due to 0 based indexing
    {
        heapfy(arr, n, i);
    }
}
void heapfy(int arr[], int n, int i) // i is the current index from which we starts building heap
{
    // heapfy is the best algo for building an heap in time complexity n

    int left_child = (i * 2) + 1;  // +1 due to 0 based indexing otherwise +0
    int right_child = (i * 2) + 2; // +2 due to 0 based indexing otherwise +1
    int largest = i;               // as it is a max heap
    if (left_child < n && arr[left_child] > arr[largest])
    {
        largest = left_child;
    }
    if (right_child < n && arr[right_child] > arr[largest])
    {
        largest = right_child;
    }
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapfy(arr, n, largest);
    }
}
void heap_sort(int arr[], int n)
{
    build_heap(arr, n);

    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        heapfy(arr, i - 1, 0);
    }
}
void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}