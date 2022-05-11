// T(n): O(n), n: no. of digits
int numDigits(int n){
    if(n < 10){
        return 1;
    }
    return 1 + numDigits(n/10);
}