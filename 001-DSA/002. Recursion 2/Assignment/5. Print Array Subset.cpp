#include<cmath>

void print(int *input, int size, int *output){
    print(input,size-1,output);
    output[]
}

void printSubsetsOfArray(int input[], int size) {
	// Write your code here
	int len= pow(2,input.length());
    int *out= new int[len];
    print(input,size,out);
    delete []out;
    return;
}

//more concise approach
void printSubsetsOfArray(int input[], int size, string output="") {
	// Write your code here
    if(size == 0){
        cout<<output<<endl;
        return;
    }

    printSubsetsOfArray(input+1, size-1, output);
    output= output + to_string(input[0]) + ' ';
    printSubsetsOfArray(input+1, size-1, output);

}
