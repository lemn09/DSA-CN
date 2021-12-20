#include<iostream>
#include<climits>
using namespace std;

//Method 1: Brute force recursion
int minCostPath(int **input, int m, int n, int row=0, int col=0){
   // cout<<row<<" "<<col<<endl;
    
    if(row+1==m && col+1==n){
        return input[row][col];
    }
    
    int x=INT_MAX, y= INT_MAX, z= INT_MAX;
    if(row+1 < m && col+1 < n){
        x= minCostPath(input, m, n, row+1, col+1);			// diagonal
    	y= minCostPath(input, m, n, row+1, col);			// down
        z= minCostPath(input, m,n, row, col+1);				// right
    }else if(row+1 < m){
        return input[row][col] + minCostPath(input, m, n,row+1, col);
    }else{
        return input[row][col] +  minCostPath(input, m, n, row, col+1);
    }
    
	int minPath= min(x, min(y,z));
    return minPath+ input[row][col];
}

//Method 2: Memoization
int minCostPath(int **input, int m, int n, int **arr, int row=0, int col=0){
    if(row+1 == m && col+1 == n){
        return input[row][col];
    }
    if(row>= m || col>=n){
        return INT_MAX;
    }

    if(arr[row][col] == 0){
		int x= minCostPath(input, m, n, arr, row+1, col+1);
        int y= minCostPath(input, m, n, arr, row, col+1);
        int z= minCostPath(input, m, n, arr, row+1, col);
        arr[row][col]= input[row][col] +  min(x, min(y,z));
    }

    return arr[row][col];
}

//method 3 dp
int minCostPath2(int **input, int m, int n){
    int **arr= new int*[m];
    for(int i=0; i<m; i++){
        arr[i]= new int[n]();
    }

    // destination index/ last index
    arr[m-1][n-1]= input[m-1][n-1];

    // filling last row (right to left)
    for(int i=n-2; i>=0; i--){
        arr[m-1][i]= input[m-1][i] + arr[m-1][i+1];
    }

    //filling last col (bottom to top)
    for(int i=m-2; i>=0; i--){
        arr[i][n-1]= input[i][n-1] + arr[i+1][n-1];
    }

    // filling rest of the output matrix
    for(int i= m-2; i>=0; i--){
        for(int j= n-2; j>=0; j--){
            arr[i][j]= input[i][j] + min(arr[i][j+1], min(arr[i+1][j] , arr[i+1][j+1]));
        }
    }

    int ans= arr[0][0];
    for(int i=0; i<m; i++){
        delete []arr[i];
    }
    delete []arr;
    return ans;
}

int main()
{
	int **arr, n, m;
	cin >> n >> m;
	arr = new int *[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[m];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}
	cout << minCostPath2(arr, n, m) << endl;

    for(int i=0; i<n; i++){
        delete []arr[i];
    }

    delete []arr;
    return 0;
}