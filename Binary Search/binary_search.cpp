#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int key)
{
    int start = 0;
    int end = n - 1;

    while (start <= end)
    {
        //int mid = (start + end) / 2;
        int mid = start + (end - start)/2; // chalaki wali chij avoids int out of range exception

        if (arr[mid] == key)
        {
            return mid;
        }

        if (arr[mid] < key)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    return -1;
}

int firstOccurance(int arr[], int n, int key){
    int start = 0;
    int end = n - 1;
    int ans = -1;
    while(start <= end){
        int mid = start + (end - start)/2;

        if(arr[mid] == key){
            ans = mid;
            end = mid-1;
        }
        else if(arr[mid] < key){
            start = mid+1;
        }else{
            end = mid-1;
        }
    }
    return ans;
}
int lastOccurancce(int arr[], int n, int key){
    int start = 0;
    int end = n - 1;
    int ans = -1;
    while(start <= end){
        int mid = start + (end - start)/2;

        if(arr[mid] == key){
            ans = mid;
            start = mid+1;
        }
        else if(arr[mid] < key){
            start = mid+1;
        }else{
            end = mid-1;
        }
    }
    return ans;
}

int getPivot(int arr[], int n){
    int start = 0;
    int end = n-1;
    while(start<end){
        int mid = start + (end-start)/2;

        if(arr[mid] >= arr[0]){ // apply binary search on 1st line of graph(visual representation of rotated and sorted array)

        start = mid+1;

        }else{ // apply binary search on 2nd line of graph
            end = mid;
        }
    }

    return start;
}

int main()
{
    int even[6] = {2, 4, 6, 8, 12, 18};
    int odd[5] = {3, 8, 11, 14, 16};
    cout << "Even : " << binarySearch(even, 6, 4) << endl;
    cout << "Oddd : " << binarySearch(odd, 5, 16)<<endl;

    // Total no of occurances of key = (lastOccurance - firstOccurance) + 1
    int sortedAndRotatedArr[9] = {5,6,7,8,9,10,1,2,3};
    cout<<"Pivot element : "<<sortedAndRotatedArr[getPivot(sortedAndRotatedArr,9)];
    return 0;
}