#include <iostream>
#include <string>
using namespace std;

string code[]= {"", "", "abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
void print(int num, string output)
{
	if(num == 0){
        cout<<output<<endl;
        return;
    }
    string smallOutput= code[num%10];
    for(int i=0; i<smallOutput.length(); i++){
        print(num/10,smallOutput[i] + output);
    }

}

void printKeypad(int num){
    /*
    Given an integer number print all the possible combinations of the keypad. You do not need to return anything just print them.
    */
    string output="";
    print(num,output);
}
