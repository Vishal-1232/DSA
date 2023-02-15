#include <iostream>
using namespace std;
void display(int arr[], int n);
void merge_sort(int arr[] , int lb , int ub);
void merge(int arr[],int mid,int lb, int ub);
int main()
{
    int arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    merge_sort(arr,0, n-1);
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
void merge_sort(int arr[] , int lb , int ub)
{
    if(lb<ub)
    {
        int mid = (lb+ub)/2;
        merge_sort(arr,lb,mid);
        merge_sort(arr,mid+1,ub);
        merge(arr,mid,lb,ub);
    }
    // time complexity O(n log n)
    // space complexity O(n)
}
void merge(int arr[],int mid,int lb, int ub)
{
    int i = lb , j = mid+1;
    int b[100] , k = lb;
    while (i<=mid && j<=ub)
    {
        if (arr[i]<arr[j])
        {
            b[k++] = arr[i++];
        }
        else
        {
            b[k++] = arr[j++]; 
        }
        
    }
    while (i<=mid)
    {
        b[k++] = arr[i++];
    }
    while (j<=ub)
    {
        b[k++] = arr[j++];
    }
    for (int i = lb; i <= ub; i++)
    {
        arr[i] = b[i];
    }
    
    
}