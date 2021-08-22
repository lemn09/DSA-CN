#define SIZE 10000

void helper(int *input, int size, int si, int *out, int outlen, int k){
    if(si == size){
        if(k == 0){
            for(int i=0; i<outlen; i++){
                cout<<out[i]<<' ';
            }
            cout<<endl;
        }
        return;
    }

    out[outlen++]= input[si];
    helper(input,size,si+1,out,outlen,k-input[si]);
	outlen--;
    helper(input,size,si+1,out,outlen,k);
}

void printSubsetSumToK(int input[], int size, int k) {
    // Write your code here
    int *out= new int[SIZE];
	helper(input,size,0,out,0,k);
}
