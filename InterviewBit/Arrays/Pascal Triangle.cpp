vector<vector<int> > Solution::solve(int A) {
    vector<vector<int> > result(A);
    
    for(int line = 0; line < A; line++)
    {
        result[line].resize(line + 1);
        
        for(int i = 0; i <= line; i++)
        {
            if(i == 0 || i == line)
            {
                result[line][i] = 1;
            }else
            {
                result[line][i] = result[line - 1][i] + result[line - 1][i - 1];
            }
        }
    }
    
    return result;
}
