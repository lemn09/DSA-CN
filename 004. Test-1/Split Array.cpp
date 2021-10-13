bool check(int *input, int size, int sumFive, int sumThree){
    if(size == 0){
        return (sumFive == sumThree);
    }

    if(input[0]%5 == 0){
        sumFive+=input[0];
    }else if(input[0]%3 == 0){
        sumThree+=input[0];
    }else{
        bool ans1= check(input+1,size-1,sumFive+input[0],sumThree);
        bool ans2= check(input+1,size-1,sumFive, sumThree+input[0]);
        return ans1||ans2;
    }
    return check(input+1,size-1,sumFive, sumThree);
}

bool splitArray(int *input, int size) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    return check(input,size,0,0);
}
