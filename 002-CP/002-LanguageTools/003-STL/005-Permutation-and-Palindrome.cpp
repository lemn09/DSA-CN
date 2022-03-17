// Codechef, Problem Code: PERMPAL
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string input;
        cin >> input;
        // 1. frequency calculate & store indexes of each occurrence of every char of string
        int count[26]{0};
        vector<vector<int>> position(26);
        for (int i = 0; i < input.length(); i++)
        {
            count[input[i] - 'a']++;
            position[input[i] - 'a'].push_back(i);
        }

        // 2.  palindrome check
        int oddCount = 0;
        char oddChar = 0;
        for (int i = 0; i < 26; i++)
        {
            if (count[i] % 2)
            {
                oddCount++;
                oddChar = i;
            }
        }
        if (oddCount >= 2)
        {
            cout << -1 << endl;
            continue;
        }

        // 3. create output
        int len = input.length();
        int output[len]{-1};
        int si = 0;
        for (int i = 0; i < 26; i++)
        {
            // frequency check
            int currCount = count[i];
            if (currCount % 2 == 0)
            {
                int currLen = position[i].size();
                for (int j = 0; j < currLen; j += 2)
                {
                    output[si] = position[i][j];
                    output[len - si - 1] = position[i][j + 1];
                    // cout<<"output["<<si<<"]= "<<output[si]<<", output["<<len-si-1<<"]= "<<output[len-si-1]<<endl;
                    si++;
                }
            }
        }
        if (oddCount == 1)
        {

            for (int j = 0; j < position[oddChar].size(); j++)
            {

                output[si] = position[oddChar][j];
                // cout<<"output["<<si<<"]= "<<output[si]<<endl;
                si++;
            }
        }

        // 4. print output
        for (auto i : output)
        {
            cout << i + 1 << " ";
        }
        cout << endl;
    }
    return 0;
}