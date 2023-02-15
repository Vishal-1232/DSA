// logic
// SELECTION --->  SWAPPING ---> COUNTER SHIFT

#include <iostream>
using namespace std;

void display(int arr[], int n);
void selection_sort(int arr[], int n);

int main()
{
    int arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    selection_sort(arr, n);
    display(arr, n);
    return 0;
}

void display(int arr[], int n)
{

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void selection_sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }
        swap(arr[i], arr[min_index]);
    }
    /*
    Time Complexity: O(n2) as there are two nested loops.
    Auxiliary Space: O(1) 

    The good thing about selection sort is it never makes more than O(n) swaps and can be useful when memory write is a costly operation. 
    
    */
}