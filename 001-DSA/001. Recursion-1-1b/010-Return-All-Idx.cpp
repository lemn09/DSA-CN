
// method-1
int allIndexes(int input[], int size, int x, int output[], int si=0, int li=0) {
	if(size == 0){
        return li;
    }
    if(input[si] == x){
        output[li]= si;
        return allIndexes(input, size-1, x, output, si+1, li+1);
    }
    return allIndexes(input, size-1, x, output, si+1, li);
}


//method 2
int allIndexes2(int input[], int size, int x, int output[]) {
	if(size == 0)
        return 0;
	int ans= allIndexes2(input,size-1,x,output);
	if(input[size-1] == x)
        output[ans++]= size-1;
    return ans;
}

#include<iostream>
using namespace std;


int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    int x;
    
    cin >> x;
    
    int *output = new int[n];
    
    int size = allIndexes(input, n, x, output);
    for(int i = 0; i < size; i++) {
        cout << output[i] << " ";
    }
    
    delete [] input;
    
    delete [] output;
    

}

