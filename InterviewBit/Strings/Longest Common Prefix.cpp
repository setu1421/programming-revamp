// Time Complexity: min(length of all strings) * no of strings

string Solution::longestCommonPrefix(vector<string> &A) {
    int n = A.size();
    int minN = INT_MAX;

    for(int i = 0; i < n; i++)
    {
        int len = strlen(A[i].c_str());
        minN = min(minN, len);
    }
    
    for(int i = 0; i < minN; i++)
    {
        char c = A[0][i];
        
        for(int j = 1; j < n; j++)
        {
            if(c != A[j][i])
            {
                return A[0].substr(0,  i);
            }
        }
    }
    
    return A[0].substr(0, minN);
}

// Another Approach: Using Binary Search on the small array.
// Time Complexity: log(min(length of all strings)) * no of strings

string Solution::longestCommonPrefix(vector<string> &A) {
    int n = A.size();
    int minN = INT_MAX;

    for(int i = 0; i < n; i++)
    {
        int len = strlen(A[i].c_str());
        minN = min(minN, len);
    }
    
    int low = 0, high = minN - 1;
    
    while(low <= high)
    {
        int mid = low + (high - low) / 2;
        char c = A[0][mid];
        bool notMatched = false;
        
        for(int j = 1; j < n; j++)
        {
            if(c != A[j][mid])
            {
                notMatched = true;
                high = mid - 1;
                break;
            }
        }
        
        if(!notMatched)
        {
            low = mid + 1;
        }
    }
    
    return A[0].substr(0, high + 1);
}

