// yt: kk, calculating x power y using bitwise operator in logn time
#include<bits/stdc++.h>
using namespace std;

#define M 1000000007
#define ll long long
#define vi vector<int>

// T(n): O(logb)
ll returnPow(ll base, ll power){
    ll res=1;
    while(power){
        if(power&1){
            res*=base;
        }
        base*=base;
        power >>= 1;
        cout << res << " " << base << endl;
    }
    return res;
}

int main(){
    ll a,b;
    cin >> a >> b;
    cout << returnPow(a,b) << endl;
    return 0;
}