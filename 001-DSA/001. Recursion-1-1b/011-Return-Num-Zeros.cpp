
int countZeros(int n){
    if(n < 10){
        if(!n){
            return 1;
        }
        return 0;
    }
    int digit= n%10;
    if(!digit){
        return 1 + countZeros(n/10);
    }
    return countZeros(n/10);
}

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    cout << countZeros(n) << endl;
}
