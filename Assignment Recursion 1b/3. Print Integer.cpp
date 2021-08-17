#include<cstring>
void removeX(char input[]) {
    // Write your code here
    if(input[0] == '\0')
        return;
	if(input[0] == 'x')
    {
        for(int i=0; i<strlen(input); i++)
            input[i]= input[i+1];
    	removeX(input);
    }
    else removeX(input+1);
}
