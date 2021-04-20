vector<vector<int> > Solution::diagonal(vector<vector<int> > &A) {
    int n = A.size();
    
    vector<vector<int> > result;
    
    int startrow, startcol, array_counter = 0;
    
    // Print the diagonals with first row
    for(int col = 0; col < n; col++)
    {
        result.push_back(vector<int>());
        
        startrow = 0, startcol = col;
        
        while(startrow < n && startcol >= 0)
        {
            result[array_counter].push_back(A[startrow][startcol]);
            
            startrow++;
            startcol--;
        }
        
        array_counter++;
    }
    
    // Print the diagonals with other rows
    for(int row = 1; row < n; row++)
    {
        result.push_back(vector<int>());
        
        startrow = row, startcol = n - 1;
        
        while(startrow < n && startcol >= 0)
        {
            result[array_counter].push_back(A[startrow][startcol]);
            
            startrow++;
            startcol--;
        }
        
        array_counter++;
    }
    
    return result;
}


// Another approach:

// Function to print diagonals
vector<vector<int> > Solution::diagonal(vector<vector<int> > &A) {
{
 
    int n = A.size();
 
    vector<vector<int> > result(2 * n - 1);
 
    // Push each element in the result vector
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            result[i + j].push_back(A[i][j]);
   

    return result;
}
