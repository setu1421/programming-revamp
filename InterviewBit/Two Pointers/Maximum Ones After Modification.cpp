int Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    int wL = 0, wR = 0, zeroCount = 0, maxSeg = 0;
    
    while(wL < n && wR < n)
    {
        if(zeroCount <= B)
        {
            if(A[wR] == 0)
            {
                zeroCount++;
            }
            wR++;
        }
        
        if(zeroCount > B)
        {
            if(A[wL] == 0)
            {
                zeroCount--;
            }
            
            wL++;
        }
        
        int currSeg = wR - wL;
        
        if((currSeg > maxSeg) && (zeroCount <= B))
        {
            maxSeg = currSeg;
        }
    }
    
    return maxSeg;
}
