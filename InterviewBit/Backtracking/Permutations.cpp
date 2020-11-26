// https://www.youtube.com/watch?v=GuTPwotSdYw
void permuteUtil(vector<vector<int> > &res, vector<int> &A, int l, int r)
{
    if(l == r)
    {
        res.push_back(A);
        return;
    }
    
    for(int i = l; i <= r; i++)
    {
        swap(A[l], A[i]);
        permuteUtil(res, A, l + 1, r);
        swap(A[l], A[i]);
    }
}

vector<vector<int> > Solution::permute(vector<int> &A) {
    vector<vector<int> > res;
    
    permuteUtil(res, A, 0, A.size() - 1);
    
    return res;
}
