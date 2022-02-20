// codechef: KCON
#include <iostream>
#include <climits>
#include <vector>
using namespace std;

typedef long long ll;

ll kadane(vector<int> arr, int const &n)
{
    ll curr = 0;
    ll best = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        curr += arr[i];
        if (best < curr)
        {
            best = curr;
        }
        if (curr < 0)
        {
            curr = 0;
        }
    }

    return best;
}

ll maxSumSub(vector<int> &a, int n, int k)
{
    ll sum = kadane(a, n);
    if (k == 1)
    {
        return sum;
    }
    // best prefix sum, best suffix sum
    ll currPre = 0, currSuff = 0, bestPre = INT_MIN, bestSuff = INT_MIN;
    // best prefix calc.
    for (int i = 0; i < n; i++)
    {
        currPre += a[i];
        bestPre = max(bestPre, currPre);
    }
    ll totalSum = currPre;
    for (int i = n - 1; i >= 0; i--)
    {
        currSuff += a[i];
        bestSuff = max(bestSuff, currSuff);
    }
    if (totalSum < 0)
    {
        return max(bestSuff + bestPre, sum);
    }
    else
    {
        ll res = max((k - 2) * totalSum + bestPre + bestSuff, sum);
        return res;
    }
}

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        cout << maxSumSub(a, n, k) << endl;
    }
    return 0;
}
