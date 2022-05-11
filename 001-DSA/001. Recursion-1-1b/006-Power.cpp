// T(n) : O(logn)

int power(int x, int n) {
    if(n==0){
        return 1;
    }
    // if odd
	if(n&1){
        return x*power(x,n/2)*power(x,n/2);
    }else{
        return power(x,n/2)*power(x,n/2);
    }
}

//T(n) : O(n)
int power(int x, int n){
    if(!n){
        return 1;
    }
    return x*power(x,n-1);
}