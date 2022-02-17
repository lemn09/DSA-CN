// memoization
int helper(int n, vector<int> &out)
{
    if (n <= 3)
    {
        return n;
    }

    if (out[n] == 0)
    {
        int ans = INT_MAX;
        for (int i = 1; i * i <= n; i++)
        {
            int temp = 1 + helper(n - (i * i), out);
            if (temp < ans)
            {
                ans = temp;
            }
        }
        out[n] = ans;
    }

    return out[n];
}

int minCount(int n)
{
    // Write your code here
    vector<int> out(n + 1, 0);
    return helper(n, out);
}

// iterative solution
int minCount(int n)
{
    // Write your code here
    vector<int> output(n + 1, 0);
    for (int i = 0; i <= 3; i++)
    {
        output[i] = i;
    }

    for (int i = 4; i <= n; i++)
    {
        int ans = INT_MAX;
        for (int j = 1; j <= sqrt(i); j++)
        {
            int temp = 1 + output[i - (j * j)];
            if (temp < ans)
            {
                ans = temp;
            }
        }
        output[i] = ans;
    }

    return output[n];
}