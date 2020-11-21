// https://www.youtube.com/watch?v=rJ9NFK9s_mI
int Solution::isValidSudoku(const vector<string> &A) {
    
    unordered_map<string, int>mp;
    
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            // Check in the row, column and box
            if(A[i][j] != '.')
            {
                string rowHashKey = "row" + to_string(i) + A[i][j];
                string colHashKey = "col" + to_string(j) + A[i][j];
                string boxHashKey = "box" + to_string(((i / 3) * 3) + (j / 3)) + A[i][j];
                
                if(mp.find(rowHashKey) != mp.end() || mp.find(colHashKey) != mp.end()
                   || mp.find(boxHashKey) != mp.end())
                {
                    return 0;   
                }
                
                mp[rowHashKey] = 1;
                mp[colHashKey] = 1;
                mp[boxHashKey] = 1;
            }
        }
    }
    
    return 1;
}
