#include <iostream>
#include <cstring>
using namespace std;

int editDistance(string s1, string s2){
    int m= s1.size();
    int n= s2.size();
    int **output= new int*[m+1]();
    for(int i=0; i<=m; i++){
        output[i]= new int[n+1]();
    }

    output[0][0]= 0;
    // filling base case
    // when size of one of the strings is zero ans is size of the other string
    for(int i=1; i<=n; i++){
        output[0][i]= i;
    }
    for(int i=1; i<=m; i++){
        output[i][0]= i;
    }

    // now iteratively solving the question
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(s1[m-i] == s2[n-j]){
                output[i][j]= output[i-1][j-1];
            }else{
                int a= 1 + output[i-1][j];
                int b= 1 + output[i][j-1];
                int c= 1 + output[i-1][j-1];
                output[i][j]= min(a, min(b,c));
            }
        }
    }

    int result= output[m][n];

    // for(int i=0; i<=m; i++){
    //     delete []output[i];
    // }
    // delete []output;

    return result;
}

int main()
{
	string s1;
	string s2;

	cin >> s1;
	cin >> s2;

	cout << editDistance(s1, s2) << endl;
}