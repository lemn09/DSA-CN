// brute force
int product(vector<int> &arr)
{
    int pro = 1;
    for (int i = 0; i < arr.size(); i++)
    {
        pro *= arr[i];
    }
    return pro;
}

int maximumProduct(vector<int> &arr, int n)
{
    // Write your code here
    int ans = INT_MIN;
    for (int i = 0; i < n; i++)
    {

        int curr = arr[i];
        vector<int> sub;
        for (int j = i; j < n; j++)
        {
            sub.push_back(arr[j]);
            int res = product(sub);
            //             	cout<<res<<endl;
            ans = max(ans, res);
        }
    }
    return ans;
}

// optimal solution: O(1)
#include <algorithm>

int maximumProduct(vector<int> &arr, int n)
{

    int ans = INT_MIN;

    int productFromFront = 1, productFromBack = 1;

    for (int i = 0; i < n; i++)
    {
        productFromFront = productFromFront * arr[i];
        productFromBack = productFromBack * arr[n - i - 1];

        // Store the maximum of ans, productFromFront and productFromBack in the ans variable.
        ans = max({ans, productFromFront, productFromBack});

        // If any of the products become 0, make them 1 again.
        if (productFromFront == 0)
        {
            productFromFront = 1;
        }
        if (productFromBack == 0)
        {
            productFromBack = 1;
        }
    }

    return ans;
}