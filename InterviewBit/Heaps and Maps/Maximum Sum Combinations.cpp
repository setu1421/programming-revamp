// Duplicate problem of N Max pair combinations.

vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) {
    vector<int> res;
    priority_queue<pair<int, pair<int,int> > > pq;
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    for(int i = 0; i < B.size(); i++)
    {
        pq.push(make_pair(A[0] + B[i], make_pair(0, i)));
    }
    
    while(C > 0)
    {
        pair<int, pair<int,int> > top = pq.top();
        pq.pop();
        
        int sum = top.first;
        pair<int, int> index = top.second;
        int i = index.first, j = index.second;
        
        res.push_back(sum);
        pq.push(make_pair(A[i + 1] + B[j], make_pair(i + 1, j)));
        
        C--;
    }
    
    return res;
}
