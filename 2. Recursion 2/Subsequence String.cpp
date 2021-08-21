#include<iostream>
#include<cmath>
using namespace std;

int sub(string input, string output[])
{
    if(input.empty())
    {
        output[0]="";
        return 1;
    }
    string smallString= input.substr(1);
    int smallOutputSize= sub(smallString,output);
    for(int i=0; i<smallOutputSize; i++)
        output[i + smallOutputSize]= input[0] + output[i];
    return 2*smallOutputSize;
}

int main()
{
    string input;
    cout<<"Enter a string: ";
    cin>>input;
    int len= pow(2, input.size());
    string *output= new string[len];
    int n= sub(input,output);
    cout<<"\nAns:\n";
    for(int i=0; i<n; i++)
        cout<<output[i]<<endl;
    cout<<endl;
    return 0;
}
