 bool cmp(const vector<int> v1, const vector<int> v2)
{
    return v1[1] < v2[1];
}
int Solution::solve(vector<vector<int> > &A) {
    int n = A.size();
    
    if(n < 1)
    {
        return 0;
    }
    
    sort(A.begin(), A.end(), cmp);
    int count = 1;
    int y = A[0][1];
    
    for(int i = 1; i < n; i++)
    {
        int p = A[i][0];
        int q = A[i][1];
        // Check if given interval overlap with 
        // previously included interval, if not 
        // then include this interval and update 
        // the end point of last added interval 
        if(p > y)
        {
            count++;
            y = q;
        }
    }
    
    return count;
}
