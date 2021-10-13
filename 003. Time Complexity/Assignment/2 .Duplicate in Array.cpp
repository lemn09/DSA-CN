int findDuplicate(int *arr, int n)
{
    //Write your code here
    int sum= ((n-2)*(n-1))/2;
    int asum=0;
    for(int i=0; i<n; i++){
        asum+=arr[i];
    }
    return asum-sum;
}
