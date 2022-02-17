#include<iostream>
#include<vector>
using namespace std;

// recursion: brute force, T(N): O(2^N)
int fib(int n){
    if(n<=1){
        return n;
    }
    return fib(n-1) + fib(n-2);
}

// memoization, T(N): O(N)
int fib2(int n, int *ans){
    if(n <= 1){
        return n;
    }

    if(ans[n] == 0){
        ans[n]= fib2(n-1, ans) + fib2(n-2, ans);
    }
    return ans[n];
}

// Dynamic Programming, T(N): O(N)
int fib3(int n){

    int *arr= new int[n+1]();

    arr[0]= 0;
    arr[1]= 1;

    for(int i=2; i<=n; i++){
        arr[i]= arr[i-1] + arr[n-2];
    }

    int ans= arr[n];
    delete []arr;
    return ans;
}

int main(){
    int *arr=  new int[8]();
    cout<<fib(7)<<endl;
    cout<<fib2(7, arr)<< endl;
    cout<<fib3(7)<<endl; 
    delete []arr;
}