// Codechef, Problem Code: VOTERS
#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;
    vector<int> list;
    int len = n1 + n2 + n3;
    for (int i = 0; i < len; i++)
    {
        int in;
        cin >> in;
        list.push_back(in);
    }
    sort(list.begin(), list.end());
    int curr = list[0], j = 0;
    len = 0;
    vector<int> output;
    for (auto i : list)
    {
        if (i == curr)
        {
            j++;
        }
        else
        {
            if (j > 1)
            {
                len++;
                output.push_back(curr);
            }
            j = 1;
            curr = i;
        }
    }

    cout << output.size() << endl;
    for (auto i : output)
    {
        cout << i << endl;
    }

    return 0;
}
