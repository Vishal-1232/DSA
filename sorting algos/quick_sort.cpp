#include <iostream>
using namespace std;

void display_arr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int partition(int arr[], int lb, int ub)
{
    int pivot = arr[ub];
    int i = lb - 1;
    for (int j = lb; j < ub; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr, i, j);
        }
    }
    swap(arr, i + 1, ub);
    return i + 1;
}

void quick_sort(int arr[], int lb, int ub)
{
    if (lb <= ub)
    {
        int pivot_index = partition(arr, lb, ub);
        quick_sort(arr, lb, pivot_index - 1);
        quick_sort(arr, pivot_index + 1, ub);
    }
    // wrost case n^2 otherwise nlogn
}

int main()
{

    int n = 100, a[n];
    int c;
    cout << "how many elements : " << endl;
    cin >> c;
    for (int i = 0; i < c; i++)
    {
        cout << "enter element at index " << i << " :";
        cin >> a[i];
    }
    cout << endl;
    cout << "elements entered are : " << endl;
    display_arr(a, c);
    quick_sort(a, 0, c);
    display_arr(a, c);

    return 0;
}
