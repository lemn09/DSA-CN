// memoization
#include <vector>
long helper(int n, vector<long int> &output)
{
    if (n < 0)
    {
        return 0;
    }

    if (n == 0)
    {
        return 1;
    }
    if (n == 1 || n == 2)
    {
        return n;
    }

    if (output[n] == 0)
    {
        output[n] = helper(n - 1, output) + helper(n - 2, output) + helper(n - 3, output);
    }

    return output[n];
}

long staircase(int n)
{
    // Write your code here
    vector<long int> output(n + 1, 0);
    return helper(n, output);
}

// dynamic programming
long staircase(int n)
{
    // Write your code here
    vector<long int> output(n + 1, 0);
    output[0] = 1;
    output[1] = 1;
    output[2] = 2;
    for (int i = 3; i <= n; i++)
    {
        output[i] = output[i - 1] + output[i - 2] + output[i - 3];
    }

    return output[n];
}