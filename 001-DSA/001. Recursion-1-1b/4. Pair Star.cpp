// Change in the given string itself. So no need to return or print the changed string.
#include<cstring>
using namespace std;
void pairStar(char input[]) {
    // Write your code here
    if(input[0] == '\0') return;
	if(input[0] == input[1])
    {
        for(int i=strlen(input); i>=0; i--)
            input[i+1]=input[i];
      //  input[strlen(input) + 1]='\0';
    	input[1]= '*';
        //cout<<input<<endl;
        pairStar(input+2);
    }
    pairStar(input+1);
}
