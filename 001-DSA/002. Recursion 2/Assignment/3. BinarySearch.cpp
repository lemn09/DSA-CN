// input - input array
// size - length of input array
// element - value to be searched
int bs(int input[], int si, int ei, int element)
{
	if(si>ei)
        return -1;
    int mid=(si+ei)/2;
    if(input[mid] == element)
        return mid;
    else if(input[mid] < element)
        return bs(input,mid+1,ei,element);
    else
        return bs(input,si,mid-1,element);
}

int binarySearch(int input[], int size, int element) {
    // Write your code here
	if( size == 0)
        return -1;
    return bs(input, 0,size-1,element);
}
