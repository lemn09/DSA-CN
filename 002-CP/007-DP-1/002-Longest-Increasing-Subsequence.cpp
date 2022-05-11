#include <bits/stdc++.h>
using namespace std;

#define m 1000000007
#define SWAP(a, b, c) ((c) = (a), (a) = (b), (b) = (c))
#define ll long long
#define vi vector<int>

// dfs-recursion brute force
int solve1(int idx, int *input, int n, int lastIdx){
    if(idx <= n){
        return 0;
    }

    int ans1=0;
    if(lastIdx == -1 || input[lastIdx] < input[idx]){
        ans1= 1 + solve1(idx+1,input,n,idx);
    }
    int ans2= solve1(idx+1,input,n,lastIdx);

    return max(ans1,ans2);
}

// memoization
int solve2(int idx, int *nums, int n, vector<int> &cache){
        if(idx >= n){
            return 0;
        }
        
        if(cache[idx] == -1){
            int ans=0;
            for(int i=idx; i<n; i++){
                if(idx == 0 || nums[idx-1] < nums[i]){
                    int temp= 1 + solve2(i+1,nums,n,cache);
                    if(ans < temp){
                        ans= temp;
                    }
                }                
            }
            cache[idx]= ans;            
        }
        
        return cache[idx];
    }


// iterative solution
int solve(int *input, int n)
{
    int *output = new int[n]();
    for (int i = 0; i < n; i++)
    {
        output[i] = 1;
        for (int j = i - 1; j >= 0; j--)
        {
            if (input[j] < input[i])
            {
                int temp = output[j] + 1;
                if (output[i] < temp)
                {
                    output[i] = temp;
                }
            }
        }
    }
    int best = 0;
    for (int i = 0; i < n; i++)
    {
        if (best < output[i])
        {
            best = output[i];
        }
    }
    delete[] output;
    return best;
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n]();
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << solve(arr, n) << endl;
    delete[] arr;
    return 0;
}