// largest sub array sum(sub array is made up of contiguous elements of array)
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <climits>
using namespace std;

int solve(int *arr, int const &n)
{
    int currEnd = 0;
    int bestEnd = 0;
    for (int i = 0; i < n; i++)
    {
        currEnd += arr[i];
        if (bestEnd < currEnd)
        {
            bestEnd = currEnd;
        }
        if (currEnd < 0)
        {
            currEnd = 0;
        }
    }
    return bestEnd;
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n]();
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Ans: " << solve(arr, n) << endl;

    delete[] arr;
    return 0;
}