#include<stack>

int countBracketReversals(string input) {
	// Write your code here
    if(input.empty()){
        return -1;
    }
    stack<char> s;

    for(int i=0; i<input.length(); i++){
        if(input[i]!='}'){
            s.push(input[i]);
        }else{
            if(s.empty()){
                s.push(input[i]);
            }else if(s.top() == '{'){
                s.pop();
            }else{
                s.push(input[i]);
            }
        }
    }

    int count=0;
    while(s.size() > 1){
    	char temp= s.top();
        s.pop();
        if(temp == s.top()){
            count++;
            s.pop();
        }else{
            count+=2;
            s.pop();
        }
    }

    if(!s.empty()){
        count= -1;
    }

    return count;
}
