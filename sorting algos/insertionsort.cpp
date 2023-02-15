#include<iostream>
using namespace std;
void display(int arr[], int n);
void insertion_sort(int arr[] , int n)
{
    // loop starts from i = 1 because there is two subarrys sorted (grows with iterations) and unsorted (reduces with iterations)
    for (int i = 1; i < n; i++) // (direction) ---------> 
    {
        int temp = arr[i];
        int j = i-1;
        while (j>=0 && arr[j]>temp) // <----------   (direction)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp; // here j+1 bcz of j--
    }
    
}
int main()
{
    int arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    insertion_sort(arr,n);
    display(arr,n);
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