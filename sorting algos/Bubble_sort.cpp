// iterative and recursive approach
#include <iostream>
using namespace std;
void bubble_sort_itr(int arr[], int n);
void bubble_sort_recr(int arr[], int n);
void display(int arr[], int n);
int main()
{
    int arr1[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int arr2[] = {20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    bubble_sort_itr(arr1, n1);
    display(arr1, n1);
    bubble_sort_recr(arr2, n2);
    display(arr2, n2);
    return 0;
}
void bubble_sort_itr(int arr[], int n)
{
    bool swapped;
    for (int i = 0; i < n-1; i++)
    {
        swapped = false;
        for (int j = 0; j < n-1-i; j++)
        {
            if (arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
                swapped = true;
            }
            
        }
        if (swapped==false)
        {
            break;
        }
        
    }
    
}
void bubble_sort_recr(int arr[], int n)
{
    if (n==1)
    {
        return;     
    }
    else
    {
        for (int i = 0; i < n-1; i++)
        {
            if (arr[i]>arr[i+1])
            {
                swap(arr[i],arr[i+1]);
            }
            
        }
        bubble_sort_recr(arr,n-1);
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