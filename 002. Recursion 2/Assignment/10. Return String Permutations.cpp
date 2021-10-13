#include <string>
using namespace std;

int returnPermutations(string input, string output[]){
    if(input[0] == '\0'){
        output[0]= "";
        return 1;
    }

    int k=0;
    string newout[5000];
    for(int i=0; i<input.length(); i++){
        char ch= input[i];
        int rsize= returnPermutations(input.substr(0,i) + input.substr(i+1),newout);

        for(int j=0; j<rsize; j++){
            output[k++]= ch + newout[j];
        }
    }

    return k;
}
