#include<iostream>
using namespace std;

string getString(int d)
{
    if(d == 2)  return "abc";
    if(d == 3)  return "def";
    if(d == 4)  return "ghi";
    if(d == 5)  return "jkl";
    if(d == 6)  return "mno";
    if(d == 7)  return "pqrs";
    if(d == 8)  return "tuv";
    if(d == 9)  return "wxyz";
    return " ";
}

int keypad(int num, string output[])
{
    if(num == 0){
        output[0]= "";
        return 1;
    }

    int lastDigit= num%10;
    int smallNumber= num/10;
    int smallOutput= keypad(smallNumber, output);
    string options= getString(lastDigit);

    for(int i=0; i< options.length()-1; i++){      //making copies of the given 2d string
        for(int j=0; j<smallOutput; j++){
                output[j + (i+1)*smallOutput]= output[j];
        }
    }

    int k=0;    //for output
    for(int i=0; i<options.length(); i++){
        for(int j=0; j<smallOutput; j++,k++){
            output[k]= output[k] + options[i];
        }
    }

    return smallOutput * options.length();
}

int main()
{
    int n;
    cout<<"Enter the number: ";
    cin>>n;
    string output[1000];
    int counter= keypad(n,output);
    for(int i=0; i<counter; i++)
        cout<<output[i]<<endl;
    cout<<endl;
    return 0;
}
