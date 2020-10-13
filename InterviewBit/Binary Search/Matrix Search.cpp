int Solution::searchMatrix(vector<vector<int> > &A, int B) {
    int row = A.size();
    int col = A[0].size();
    
    int low = 0, high = (row * col) - 1;
    
    while(low <= high)
    {
        int mid = low + (high - low) / 2;
        
        int rowIndx = mid / col;
        int colIndx = mid % col;
        
        if(A[rowIndx][colIndx] == B)
        {
            return 1;
        } else if(A[rowIndx][colIndx] > B)
        {
            high = mid - 1;
        } else 
        {
            low = mid + 1;
        }
    }
    
    return 0;
}
