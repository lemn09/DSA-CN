#include <iostream>
using namespace std;

bool check(char *input, int si, int ei){
    if(si >= ei){
        return true;
    }
    if(input[si] != input[ei]){
        return false;
    }
    return check(input, si+1, ei-1);
}

bool checkPalindrome(char input[]) {
    // Write your code here
    int n=0;
    for(int i=0; input[i]; i++,n++);
	return check(input,0,n-1);
}



int main() {
    char input[50];
    cin >> input;
    
    if(checkPalindrome(input)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}
