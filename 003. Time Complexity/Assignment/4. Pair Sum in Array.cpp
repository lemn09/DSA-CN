int pairSum(int *arr, int n, int num)
{
	//Write your code here
	int ans=0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(arr[i] + arr[j] == num){
                ans++;
            }
        }
    }
    return ans;
}
