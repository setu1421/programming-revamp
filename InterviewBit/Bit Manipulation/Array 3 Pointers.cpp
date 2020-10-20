int Solution::minimize(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
    int lenA = A.size(), lenB = B.size(), lenC = C.size();
    int i = 0, j = 0, k = 0, minDiff = INT_MAX;
    
    while(i < lenA && j < lenB && k < lenC)
    {
        int diffAB = abs(A[i] - B[j]);
        int diffBC = abs(B[j] - C[k]);
        int diffCA = abs(C[k] - A[i]);
        minDiff = min(minDiff, max(diffAB, max(diffBC, diffCA)));
        
        // if A[i] is the smallest one and we need to decrease the difference in all combination,
        // so, we should pick the next greater A[i]
        if(A[i] <= B[j] && A[i] <= C[k])
        {
            i++;
        } // if B[j] is the smallest one and we need to decrease the difference in all combination,
        // so, we should pick the next greater B[j]
        else if(B[j] <= A[i] && B[j] <= C[k])
        {
            j++;
        } else
        {
            k++;
        }
    }
    
    return minDiff;
}
