#include <string.h>
using namespace std;

void print(string input, string output){
    if(input[0] == '\0'){
	cout<<output<<endl;
        return;
    }
    int num= input[0] - '0';
    char ch= num + 'a' -1;
    print(input.substr(1),output+ch);
    if(input[1]!='\0'){
        num= num*10 + input[1] - 48;
        ch= num + 'a' -1;
        if(num>=10 && num<=26){
            print(input.substr(2),output+ch);
        }
    }

}

void printAllPossibleCodes(string input) {
    print(input,"");
}
