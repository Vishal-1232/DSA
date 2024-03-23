#include <iostream>
#include <vector>
using namespace std;
void name(string s, int times)
{
    if (times == 0)
    {
        return;
    }
    cout << s << endl;
    name(s, times - 1);
}
// Parameterized Recursion
void sumOfN(int n, int ans)
{
    if (n < 1)
    {
        cout << "Parameterized : " << ans << endl;
        return;
    }
    sumOfN(n - 1, ans + n);
}
// Functional recursion
int sumOfN(int n)
{
    if (n == 1)
    {
        return 1;
    }
    return n + sumOfN(n - 1);
}
int facto(int n)
{
    if (n == 1)
    {
        return 1;
    }
    return n * facto(n - 1);
}
void revArr(int arr[], int l, int r)
{
    if (l >= r)
    {
        return;
    }
    swap(arr[l], arr[r]);
    revArr(arr, l + 1, r - 1);
}
void printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
bool palindrome(string &s, int i)
{
    if (i >= s.size() / 2)
    {
        return true;
    }
    if (s[i] != s[s.size() - 1 - i])
    {
        return false;
    }
    return palindrome(s, i + 1);
}
// Multiple recursion calls
int fibbo(int n)
{
    if (n <= 1)
    {
        return n;
    }
    int last = fibbo(n - 1);
    int secondLast = fibbo(n - 2);
    return last + secondLast;
}
// Recursion on subsequence
void subsequence(int ind, vector<int> &v, int arr[], int n)
{
    if (ind >= n)
    {
        for (auto it : v)
        {
            cout << it << " ";
        }
        if (v.size() == 0)
        {
            cout << "{}";
        }
        cout << endl;
        return;
    }

    // pick
    v.push_back(arr[ind]);
    subsequence(ind + 1, v, arr, n);
    // not pick
    v.pop_back();
    subsequence(ind + 1, v, arr, n);
}
void numSubs(int i, vector<int> &v, int currSum, int sum, int arr[], int n)
{
    if (i == n)
    {
        if (currSum == sum)
        {
            for (auto it : v)
            {
                cout << it << " ";
            } 
            cout << endl;
        }
        return;
    }

    // pick
    v.push_back(arr[i]);
    currSum += arr[i];
    numSubs(i + 1, v, currSum, sum, arr, n);
    // Not pick
    v.pop_back();
    currSum -= arr[i];
    numSubs(i + 1, v, currSum, sum, arr, n);
}
// only any one subsequence
bool numSubs1(int i, vector<int> &v, int currSum, int sum, int arr[], int n)
{
    if (i == n)
    {
        if (currSum == sum)
        {
            for (auto it : v)
            {
                cout << it << " ";
            } 
            cout << endl;
            return true;
        }
        return false;
    }

    // pick
    v.push_back(arr[i]);
    currSum += arr[i];
    if(numSubs1(i + 1, v, currSum, sum, arr, n) == true){
        return true;
    }
    // Not pick
    v.pop_back();
    currSum -= arr[i];
    if(numSubs1(i + 1, v, currSum, sum, arr, n) == true){
        return true;
    }

    return false;
}

int main()
{
    // // Print name 5 times
    // name("Vishal", 5);
    // sumOfN(5, 0);
    // cout << "Functional : " << sumOfN(5) << endl;
    // cout << "Factorial : " << facto(8) << endl;
    // int arr[6] = {1, 2, 3, 4, 5, 6};
    // cout << "Before rev : ";
    // printArr(arr, 6);
    // revArr(arr, 0, 5);
    // cout << "After rev : ";
    // printArr(arr, 6);
    // string palin = "madam";
    // if (palindrome(palin, 0))
    // {
    //     cout << "Entered string is palindrome\n";
    // }
    // else
    // {
    //     cout << "Entered string is not a palindrome\n";
    // }
    // cout << "fibbo : " << fibbo(4) << endl;
    // vector<int> v;
    // subsequence(0, v, arr, 6);
    // print subsequence whose sum is equal to num
    int arr1[3] = {1,2,1};
    vector<int> sub;
    numSubs1(0, sub, 0, 2, arr1, 3);
    return 0;
}