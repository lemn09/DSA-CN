#include<stack>

int* stockSpan(int *arr, int size)  {
	// Write your code here

    stack<int> s;
    int *ans= new int[size]();
    ans[i]=1;
    s.push(0);
    for(int i=1; i<size; i++){
        if(arr[i] > arr[s.top()]){
            s.pop();
            s.push(i);
            ans[i]= i;
        }else{
            arr[i]= i - s.top();
            s.push(i);
        }
    }

    return ans;
}
