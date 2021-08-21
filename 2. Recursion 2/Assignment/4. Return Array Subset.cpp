/***
You need to save all the subsets in the given 2D output array. And return the number of subsets(i.e. number of rows filled in output) from the given function.

In ith row of output array, 1st column contains length of the ith subset. And from 1st column actual subset follows.
For eg. Input : {1, 2}, then output should contain
	{{0}, 		// Length of this subset is 0
	{1, 2},		// Length of this subset is 1
	{1, 1},		// Length of this subset is also 1
	{2, 1, 2}}	// Length of this subset is 2

Don’t print the subsets, just save them in output.
***/

int subset(int input[], int n, int output[][20]) {
    // Write your code here
	if(n == 0){							// if size is 0
        output[0][0] == 0;
        return 1;
    }
    int num= input[0];					// storing the first element of the array because we have to add this element to the answer recieved by recursion
    int smallOutputSize= subset(input+1,n-1,output);	// recursive call
    for(int i=0; i<smallOutputSize; i++){						//copying each row
        output[smallOutputSize+i][0]= output[i][0]+1;			//first element of each row denotes the number of elements to be printed from the row
        for(int j=2; j<=output[i][0]+2; j++){					// copying elements of each row
            output[smallOutputSize + i][j]= output[i][j-1];
        }
        output[smallOutputSize + i][1]=num; 					//adding the first element num to each copied row
    }
    return smallOutputSize*2;									// returning how many rows of output have been created
}
