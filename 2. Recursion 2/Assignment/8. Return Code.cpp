#include <string.h>
using namespace std;

int getCodes(string input, string output[10000]) {
    if(input[0] == '\0'){
    	output[0]= "";
    	return 1;
    }
    int first= input[0] - 48;
    char firstchar= first + 'a' - 1;
    char secondchar= '\0';
    string result1[500],result2[500];
    int size1= getCodes(input.substr(1),result1);
    int size2=0;
    if(input[1]!='\0'){
        int second= first*10 + input[1] - 48;
        if(second>=10 && second<=26){
            secondchar= second + 'a' - 1;
            size2= getCodes(input.substr(2),result2);
        }
    }

    int k=0;
    for(int i=0; i<size1; i++){
        output[k]= firstchar + result1[i];
    	k++;
    }
	for(int i=0; i<size2; i++){
        output[k]= secondchar + result2[i];
    	k++;
    }
    return k;
}

