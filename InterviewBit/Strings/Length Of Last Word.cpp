int Solution::lengthOfLastWord(const string A) {
    int n = strlen(A.c_str());
    
    int count = 0;
    bool isEndSpaces = true;
    
    for(int i = n - 1; i >= 0; i--)
    {
        if(A[i] != ' ')
        {
            isEndSpaces = false;
            count++;
        } else if(!isEndSpaces)
        {
            break;
        }
    }
    
    return count;
}
