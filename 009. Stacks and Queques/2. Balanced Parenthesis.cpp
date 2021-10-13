bool isBalanced(string expression)
{
    // Write your code here
	stack<char> s1;
    bool ans= 1;

    for(int i=0; i<expression.size(); i++){
		if(expression[i] == '('){
            s1.push(expression[i]);
        }else if(expression[i] == ')' ){
            if(s1.empty()){
                return false;
            }
            char ch= s1.top();
            if(ch == '('){
                s1.pop();
            }else{
                return false;
            }
        }
    }

    return s1.empty();
}
