#include <iostream>
using namespace std;

void updatePtr(int *p)
{
    p = p + 1;
    cout << "Fun : " << p << endl;
}

int main()
{
    int num = 5;
    cout << num << " Address: " << &num << endl;

    int *p = &num;
    cout << p << endl;
    cout << (*p) << endl;

    // Copy pointer
    int *t = 0;
    t = p;
    cout << "t : " << t << " Val t: " << (*t) << endl;

    // Double pointer
    int **q = 0;
    q = &p;
    cout << "q : " << q << " Val q: " << (*q) << endl;
    int ***s = &q;

    // arr[i] == *(arr+i) == i[arr] == *(i+arr)
    int *ptr = &num;
    cout << "Main : " << ptr << endl;
    updatePtr(ptr);
    cout << "Main : " << ptr << endl;
    return 0;
}