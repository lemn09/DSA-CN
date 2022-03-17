// return first non-repeating char of string
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

// Method 1: Mapping,
// T(N): O(N), S(N): O(1)
char sol(string input)
{
    int arr[255] = {};
    for (auto i : input)
    {
        arr[i]++;
    }
    for (auto i : input)
    {
        if (arr[i] == 1)
        {
            return i;
        }
    }
    // if no unique char is present return the first character
    return input[0];
}

int main()
{
    string input;
    cin >> input;
    cout << "First non-repeating char: " << sol(input) << endl;
    return 0;
}