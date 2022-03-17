#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;

// Two pointer method, return size of new array
// T(n): O(nlogn) for unsored array, S(n): O(1)
int removeDuplicate1(vector<int> &input, int n)
{
    sort(input.begin(), input.end());
    int idx = 0;
    for (int i = 1; i < n; i++)
    {
        if (input[idx] != input[i])
        {
            input[++idx] = input[i];
        }
    }
    return idx + 1;
}

// method 2: returning a new list(vector)
// T(n): O(nlogn), S(n): O(1)
vector<int> removeDuplicate2(vector<int> &input, int n)
{
    sort(input.begin(), input.end());
    vector<int> output;
    int idx = 0;
    output.push_back(input[0]);
    for (int i = 1; i < n; i++)
    {
        if (input[i] != output[idx])
        {
            output.push_back(input[i]);
            idx++;
        }
    }
    return output;
}

// Method 3: set, T(n): O(N), S(N): O(N)
vector<int> removeDuplicate3(vector<int> &input, int n)
{
    set<int> s;
    vector<int> output;
    for (auto i : input)
    {
        // if element isn't present in set insert it in both output & set
        if (s.find(i) == s.end())
        {
            s.insert(i);
            output.push_back(i);
        }
    }
    return output;
}

int main()
{
    int n;
    cin >> n;
    vector<int> input(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }
    vector<int> output = removeDuplicate2(input, n);
    for (int i = 0; i < output.size(); i++)
    {
        cout << output[i] << " ";
    }
    cout << endl;
    int a = removeDuplicate1(input, n);
    for (int i = 0; i < a; i++)
    {
        cout << input[i] << " ";
    }
    cout << endl;
    vector<int> output2 = removeDuplicate3(input, n);
    for (auto i : output2)
    {
        cout << i << " ";
    }
    return 0;
}