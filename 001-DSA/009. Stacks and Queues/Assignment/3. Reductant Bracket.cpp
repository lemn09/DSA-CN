/*
    Time complexity: O(N) Space complexity: O(N) where N is the length of the   input expression
*/
#include<stack>
bool checkRedundantBrackets(string expression) {
    stack<char> stk;
    string operators = "+-*/";
    for (int i = 0; i < expression.length(); ++i) {
        if (expression[i] == '(' || operators.find(expression[i]) != string::npos) {
            stk.push(expression[i]);
        } else if (expression[i] == ')') {
            // to check for if anything relevant is present between brackets
            bool flag = false;

            while (!stk.empty() && stk.top() != '(') {
                flag = true;
                stk.pop();
            }
            if (!flag) {
                return true;
            }
            if (!stk.empty()) {
                stk.pop();
            }
        }
    }
    return false;
}

