// https://www.youtube.com/watch?v=xouin83ebxE

bool isValidPos(vector<pair<int, int> > &v, int row, int col)
{
    bool isNotUnderAttack = true;
    
    for(auto p: v)
    {
        if(p.first == row || p.second == col || (p.first - p.second == row - col) 
            || (p.first + p.second == row + col))
        {
            isNotUnderAttack = false;
            break;
        }
    }
    
    return isNotUnderAttack;
}

void solveNQueensUtil(vector<vector<string> > &res, vector<pair<int, int> > &v, int n, int row)
{
    if(row == n)
    {
        vector<string> ans;
        
        for(auto p: v)
        {
            string str(n, '.');
            str[p.second] = 'Q';
            ans.push_back(str);
        }
        
        res.push_back(ans);
        
        return;
    }
    
    for(int j = 0; j < n; j++)
    {
        if(isValidPos(v, row, j))
        {
            v.push_back(make_pair(row, j));
            solveNQueensUtil(res, v, n, row + 1);
            v.pop_back();
        }
    }
}

vector<vector<string> > Solution::solveNQueens(int A) {
    vector<vector<string> > res;
    vector<pair<int, int> > v;
    
    solveNQueensUtil(res, v, A, 0);
    
    return res;
}
