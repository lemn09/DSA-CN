vector<long long> getProductArray(int arr[], int n)
{
    // Write your code here.
    vector<long long> res;
    for (int i = 0; i < n; i++)
    {
        long long pro = 1;
        for (int j = 0; j < n; j++)
        {
            if (j != i)
            {
                pro *= arr[j];
            }
        }
        (n == 1) ? res.push_back(0) : res.push_back(pro);
    }
    return res;
}
