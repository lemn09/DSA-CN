// recursion brute force
#define M 1000000007

int balancedBTs(int n)
{
    if (n <= 1)
    {
        return 1;
    }
    int a = balancedBTs(n - 1);
    int b = balancedBTs(n - 2);
    int ans1 = (int)(((long)(a)*a) % M);
    int ans2 = (int)((2 * (long)(a)*b) % M);
    int ans = (int)(ans1 + ans2) % M;
    return ans;
}

// dynamic programming

int balancedBTs(int n)
{
    // Write your code here
    int *arr = new int[n + 1]();
    arr[0] = 1;
    arr[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        int a = arr[i - 1];
        int b = arr[i - 2];
        int ans1 = (int)(((long)(a)*a) % M);
        int ans2 = (int)((2 * (long)(a)*b) % M);
        int ans = (int)(ans1 + ans2) % M;
        arr[i] = ans;
    }

    int ans = arr[n];
    delete[] arr;
    return ans;
}