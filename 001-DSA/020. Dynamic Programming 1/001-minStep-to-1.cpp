// memoization
int countMinStepsHelper(int n, int *arr)
{
    if (n <= 1)
    {
        return 0;
    }

    if (arr[n] == 0)
    {
        int a = countMinStepsHelper(n - 1, arr) + 1;
        int b = INT_MAX, c = INT_MAX;
        if (n % 2 == 0)
        {
            b = 1 + countMinStepsHelper(n / 2, arr);
        }
        if (n % 3 == 0)
        {
            c = 1 + countMinStepsHelper(n / 3, arr);
        }

        arr[n] = min(a, min(b, c));
    }
    return arr[n];
}

int countMinStepsToOne(int n)
{
    // Write your code here
    int *ans = new int[n + 1]();
    int min = countMinStepsHelper(n, ans);
    delete[] ans;
    return min;
}

// dynamic programming: iterative
int countStepsToOne(int n)
{
    // Write your code here
    vector<int> output(n + 1, 0);
    for (int i = 2; i <= n; i++)
    {
        int a = 1 + output[i - 1];
        int b = INT_MAX, c = INT_MAX;
        if (i % 2 == 0)
        {
            b = 1 + output[i / 2];
        }
        if (i % 3 == 0)
        {
            c = 1 + output[i / 3];
        }

        output[i] = min(a, min(b, c));
    }

    return output[n];
}