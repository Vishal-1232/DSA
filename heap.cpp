#include<iostream>
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
        arr[0]=-1;
    }
    void insert(int val)
    {
        size++;
        int index = size;
        arr[index]=val;
        while(index>1)
        {
            int parent = index/2;
            if(arr[parent]<arr[index])
            {
                swap(arr[parent],arr[index]);
                index=parent;
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
            cout<<arr[i]<<" ";
        }
        
    }
};

int main()
{
    heap h;
    h.insert(50);
    h.insert(96);
    h.insert(40);
    h.print();   
    return 0;
}