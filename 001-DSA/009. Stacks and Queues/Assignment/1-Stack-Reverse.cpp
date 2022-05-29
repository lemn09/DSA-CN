#include<bits/stdtr1c++.h>
using namespace std;

// Method 1: using recursion
// T(n): O(n*n)
void reverseStack(stack<int> &input, stack<int> &extra) {
    //Write your code here
    if (input.empty() || input.size() == 1) {
        return;
    }

    int temp = input.top();
    input.pop();
    reverseStack(input, extra);
    while (!input.empty()) {
        extra.push(input.top());
        input.pop();
    }

    input.push(temp);
    while (!extra.empty()) {
        input.push(extra.top());
        extra.pop();
    }
}

// Method 2: using 2 extra stacks
// T(n): O(N), S(n): O(N)(not sure for any of space complexity in this program)
void reverseStack(stack<int> &input, stack<int> &extra) {
    //Write your code here
    if (input.empty()) {
        return;
    }

    stack<int> temp;
    while (!input.empty()) {
        extra.push(input.top());
        input.pop();
    }

    while (!extra.empty()) {
        temp.push(extra.top());
        extra.pop();
    }

    while (!temp.empty()) {
        input.push(temp.top());
        temp.pop();
    }
}

// Method 3: using 1 extra queue, and no extra stack
// T(n): O(n), n: size of array
#include<queue>
void reverseStack(stack<int> &input, stack<int> &extra) {
    //Write your code here
    queue<int> temp;
    while (!input.empty()) {
        temp.push(input.top());
        input.pop();
    }
    while (!temp.empty()) {
        input.push(temp.front());
        temp.pop();
    }
}

// Method 4: Using recursion only, no extra stack
// T(n): O(n^2), S(n): O(N)

// this function inserts element at bottom of stack
void insertAtbottom(stack<int> &input, int top) {
    if (input.empty()) {
        input.push(top);
        return;
    }
    int temp = input.top();
    input.pop();
    insertAtbottom(input, top);
    input.push(temp);
}

// no use of extra
void reverseStack(stack<int> &input, stack<int> &extra) {
    //Write your code here
    if (input.empty()) {
        return;
    }
    int top = input.top();
    input.pop();
    reverseStack(input, extra);
    insertAtbottom(input, top);
}
