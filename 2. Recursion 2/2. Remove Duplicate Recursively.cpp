void removeConsecutiveDuplicates(char *input) {
	if(input[0] == '\0')	return;
    if(input[1] == input[0])
    {
        int i;
        for(i=1; input[i]; i++)
        	input[i]= input[i+1];
    	input[i]='\0';
        return removeConsecutiveDuplicates(input);
    }
    return removeConsecutiveDuplicates(input+1);

}
