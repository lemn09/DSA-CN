#include<stack>

bool checkRedundantBrackets(string expression) {
	stack<char> s;
    for(int i=0; i<expression.length() ; i++){
        if(expression[i] != ')'){
            s.push(expression[i]);
        } else {
            int count=0;
            while(s.top() != '('){
                count++;
                s.pop();
            }
            if(count<=1){
                return true;
            }
            s.pop();
        }
    }
    return false;
}
