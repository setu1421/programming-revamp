vector<vector<int> > Solution::generateMatrix(int A) {
    vector<vector<int> > result(A, vector<int> (A));
    
    int T = 0, B = A - 1, L = 0, R = A - 1;
    int value = 1;
    while(T <= B && L <= R)
    {
        // Assign value from left to right
        for(int i = L; i <= R; i++)
        {
            result[T][i] = value;
            value++;
        }
        
        T++;
        
        // Assign values from top to bottom
        for(int i = T; i <= B; i++)
        {
            result[i][R] = value;
            value++;
        }
        
        R--;
        
        // Assign values from right to left
        for(int i = R; i >= L; i--)
        {
            result[B][i] = value;
            value++;
        }
        
        B--;
        
        // Assign values from bottom to top
        for(int i = B; i >= T; i--)
        {
            result[i][L] = value;
            value++;
        }
        
        L++;
    }
    
    return result;
    
}
