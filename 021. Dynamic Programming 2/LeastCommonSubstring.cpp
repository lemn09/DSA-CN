#include<iostream>
using namespace std;

// brute force recursion
// s: original string, l: target string, in which we have to return the longest common substring
int lcs(string s, string l){
    
    //base case
    if(s.empty() || l.empty()){
        return 0;
    }

    //small calculation: comparision of first char
    if(s[0] == l[0]){
        return 1 + lcs(s.substr(1), l.substr(1));
    }
    int a= lcs(s.substr(1), l);
    int b= lcs(s, l.substr(1));
    int c= lcs(s.substr(1), l.substr(1));

    return max(a, max(b,c));
}

//memoization
// here i denotes the curr length of string s, and j current length of string t
int mem_lcs(string s, string t, int **arr, int i, int j){
    // base case
    if(s.empty() || t.empty()){
        return 0;
    }

    
    if( arr[i][j] == -1){
        int ans=0;
        if(s[0] == t[0]){
            ans= 1+mem_lcs(s.substr(1), t.substr(1), arr, i-1, j-1);
        }else{
            int a=mem_lcs(s.substr(1), t, arr, i-1, j);
            int b= mem_lcs(s, t.substr(1), arr, i, j-1);
            int c=mem_lcs(s.substr(1), t.substr(1), arr, i-1, j-1);
            ans= max(a, max(b,c));
        }
        arr[i][j]= ans;
    }

    return arr[i][j];
}

int lcs2(string s, string t){
    int m= s.length();
    int n= t.length();

    int **arr= new int*[m+1];
    for(int i=0; i<=m; i++){
        arr[i]= new int[n+1];
    }
    // intializing array to -1
    for(int i=0; i<=m; i++){
        for(int j=0; j<=n; j++){
            arr[i][j]= -1;
        }
    }

    // result: arr[m][n]
    int result= mem_lcs(s, t, arr, m, n);
    for(int i=0; i<=m; i++){
        delete []arr[i];
    }
    delete []arr;
    return result;
}


// Dynamic Programming
int lcs3(string s, string t){
    int m= s.length();
    int n= t.length();

    // creating 2d array
    int **output= new int*[m+1];
    for(int i=0; i<=m; i++){
        output[i]= new int[n+1];
    }
    // intializing array to -1
    for(int i=0; i<=m; i++){
        for(int j=0; j<=n; j++){
            output[i][j]= -1;
        }
    }

    // dynamic programming
    output[0][0]= 0;

    // in the output array 0th row & col will have value 0
    // initializing first row to zero
    for(int i=0; i<=n; i++){
        output[0][i]= 0;
    }
    // first col
    for(int i=0; i<=m; i++){
        output[i][0]= 0;
    }
    
    // iterative solution
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(s[m-i] == t[n-j]){
                output[i][j]= 1 + output[i-1][j-1];
                continue;
            }
            int a=  output[i-1][j]; // s.substr(1),  t
            int b= output[i][j-1]; // s, t.substr(1);
            int c= output[i-1][j-1]; //s.substr(1), t.substr(1)
            output[i][j]= max(a, max(b,c));            
        }
    }

    int result= output[m][n];
    
    // deleting array
    for(int i=0; i<=m; i++){
        delete []output[i];
    }
    delete []output;
    return result;
}

int main(){
    string a, b;
    cin>>a>>b;
    cout<<lcs(a,b)<<endl;

    cout<<lcs2(a,b)<<endl;
    cout<<lcs3(a,b)<<endl;
    return 0;
}
