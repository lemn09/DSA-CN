// codechef, Problem Code: COOK82C
#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

typedef long long ll;

int query = 0;
int endPtr = -1;
queue<ll> q;
ll solution(vector<ll> &input, int reqQuery)
{
    ll curr = -1;
    while (query != reqQuery)
    {
        if (endPtr >= 0 && q.empty())
        {
            curr = input[endPtr--];
        }
        else
        {
            if (endPtr < 0 || input[endPtr] < q.front())
            {
                curr = q.front();
                q.pop();
            }
            else
            {
                curr = input[endPtr--];
            }
        }
        ll temp = curr / 2;
        if (temp > 0)
        {
            q.push(temp);
        }
        query++;
    }
    return curr;
}

int main()
{
    // your code goes here
    int n, m;
    cin >> n >> m;
    vector<ll> input(n, 0);
    for (auto &i : input)
    {
        cin >> i;
    }
    endPtr = n - 1;
    sort(input.begin(), input.end());
    while (m--)
    {
        int qr;
        cin >> qr;
        cout << solution(input, qr) << endl;
    }
    return 0;
}
