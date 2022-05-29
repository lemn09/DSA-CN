#include<queue>
void reverseQueue(queue<int> &input) {
	// Write your code here
    if(input.empty() || input.size() == 1){
        return;
    }

    int temp= input.front();
    input.pop();
	reverseQueue(input);
    input.push(temp);
}
