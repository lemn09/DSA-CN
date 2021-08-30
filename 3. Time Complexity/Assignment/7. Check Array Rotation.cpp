int arrayRotateCheck(int *input, int size)
{
    //Write your code here
	for(int i=0; i<size-1; i++){
        if(input[i] > input[i+1]){
            return i+1;
        }
    }
    return 0;
}
