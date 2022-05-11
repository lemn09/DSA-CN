#include <bits/stdc++.h>
using namespace std;

#define m 1000000007
#define SWAP(a, b, c) ((c) = (a), (a) = (b), (b) = (c))

// Recursion
int fib1(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    return fib1(n - 1) + fib1(n - 2);
}

// Memoization
int fib2(int n, int *arr)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    if (!arr[n])
    {
        arr[n] = fib2(n - 1, arr) + fib2(n - 2, arr);
    }
    return arr[n];
}

int fib3(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    int *arr = new int[n + 1]();
    arr[0] = 1;
    arr[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        arr[i] = arr[i - 1] + arr[i - 2];
    }
    int ans = arr[n];
    delete[] arr;
    return ans;
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n + 1]();
    cout << fib1(n) << endl;
    cout << fib2(n, arr) << endl;
    delete[] arr;
    cout << fib3(n) << endl;
    return 0;
}