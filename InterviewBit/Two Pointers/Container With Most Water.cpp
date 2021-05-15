int Solution::maxArea(vector<int> &A) {
    int n = A.size();
    int i = 0, j = n - 1, maxArea = 0;
    
    while(i < j)
    {
        int currentArea = min(A[i], A[j]) * (j - i);
        maxArea = max(maxArea, currentArea);
        // if the left height is smaller, then we won't get any other max area using this line.
        // So, move to next line from left and check for max area
        if(A[i] < A[j])
        {
            i++;
        } else
        {
            j--;
        }
    }
    
    return maxArea;
}
