#include<bits/stdc++.h>
using namespace std;

#define M 1000000007
#define ll long long
#define vi vector<int>

// T(n): O(logb)
ll returnPow(ll a, ll b){
    ll res=1;
    while(b){
        res*= (b&1)*a;
        a*=a;
        b >>= 1;
    }
    return res;
}

int main(){
    ll a,b;
    cin >> a >> b;
    cout << returnPow(a,b) << endl;
    return 0;
}