void Solution::setZeroes(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int m = A.size();
    int n = A[0].size();
    
    // variables to check if there are any 0 in first row and column 
    bool rowFlag = false, columnFlag = false;
    
    // updating the first row and col if 0 is encountered 
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i == 0 && A[0][j] == 0)
            {
                rowFlag = true;
            }
            
            if(j == 0 && A[i][0] == 0)
            {
                columnFlag = true;
            }
            
            if(A[i][j] == 0)
            {
                A[0][j] = 0;
                A[i][0] = 0;
            }
        }
    }
    
    // Modify the input matrix A using the 
    // first row and first column of Matrix A 
    
    for(int i = 1; i < m; i++)
    {
        for(int j = 1; j < n; j++)
        {
            if(A[0][j] == 0 || A[i][0] == 0)
            {
                A[i][j] = 0;
            }
        }
    }
    
    
    // modify first row if there was any 0
    if(rowFlag == true)
    {
        for(int j = 0; j < n; j++)
        {
            A[0][j] = 0;
        }
    }
    
    // modify first col if there was any 0
    if(columnFlag == true)
    {
        for(int i = 0; i < m; i++)
        {
            A[i][0] = 0;
        }
    }
    
    
    
}
