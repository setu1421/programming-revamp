// Time Complexity: O(n)
vector<int> Solution::solve(vector<int> &A) {
    vector<int>ret;
    int n = A.size();
    
    int negIndex = INT_MAX;
    
    for(int i = 0; i < n; i++)
    {
        if(A[i] >= 0)
        {
            negIndex = i - 1;
            break;
        }
    }
    
    // Case 1: All are positive numbers
    if(negIndex == -1)
    {
        for(int i = 0; i < n; i++)
        {
            ret.push_back(pow(A[i], 2));
        }
    } // Case 2: All are negative numbers
    else if (negIndex == INT_MAX)
    {
        for(int i = n - 1; i >= 0; i--)
        {
            ret.push_back(pow(A[i], 2));
        }
    } // Case 3: Array with both positive and negative numbers
    else
    {
        int i = negIndex, j = negIndex + 1;
        
        // Merge Both Part
        while(i >=0 && j < n)
        {
            if(abs(A[i]) < A[j])
            {
                ret.push_back(pow(A[i], 2));
                i--;
            } else
            {
                ret.push_back(pow(A[j], 2));
                j++;
            }
        }
        
        while(i >= 0)
        {
            ret.push_back(pow(A[i], 2));
            i--;
        }
        
        while(j < n)
        {
            ret.push_back(pow(A[j], 2));
            j++;
        }
    }
    
    return ret;
}
