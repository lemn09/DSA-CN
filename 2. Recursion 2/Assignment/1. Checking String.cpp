#include<string.h>
bool checkAB1(char input[]) {
	// Write your code here

    if(input[0] == '\0')
    {
        return true;
    }


    if(input[0] == 'a' && input[1] == 'b')
    {
        if(input[2] != 'b')
        {
            return false;
        }

        else
        {
            int smallOutput1 = checkAB1(input + 3);
            return smallOutput1;
        }
    }

    if(input[0] == 'b' && input[1] == 'a')
    {
        return false;

    }

    else
    {
        int smallOutput2 = checkAB1(input + 2);
        return smallOutput2;
    }
}

 bool checkAB(char input[])
 {

     if(input[0] == 'b')
     {
         return false;
     }

     bool output = checkAB1(input);

     return output;
 }



/*#include<bits/stdc++.h>
using namespace std;
bool check(string s)
{
    if(s.empty())
        return true;
    if(s[0] == 'a'){
        if(s.substr(1,2) == "bb")
    		return check(s.substr(3));
        if(s[1]== 'a')
            return check(s.substr(2));
        return false;
    }
    if(s[0] == 'b'){
        if(s[1] == 'b')
            return check(s.substr(2));
        return false;
    }
}

bool checkAB(char input[]) {
	// Write your code here
	if(input[0] !='a')
        return false;
    string str= input;
    return check(str);
}*/



