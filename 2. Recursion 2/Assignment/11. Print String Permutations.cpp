#include <iostream>
#include <string>
using namespace std;

void print(string input, string output){
    if(input.empty()){
    	cout<<output<<endl;
        return;
    }

    for(int i=0; i<input.length(); i++){
        char ch= input[i];
        string lpart= input.substr(0,i);
        string rpart= input.substr(i+1);
        string ninput= lpart+rpart;
        print(ninput,output+ch);
    }
}

void printPermutations(string input){
    print(input,"");
}
