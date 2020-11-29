int Solution::solve(vector<int> &A, int B) {
    priority_queue<int> pq;
    
    for(int i = 0; i < A.size(); i++)
    {
        pq.push(A[i]);
    }
    
    int sum = 0;
    
    while(B > 0)
    {
        int top = pq.top();
        pq.pop();
        
        sum += top;
        top--;
        if(top > 0)
        {
            pq.push(top);
        }
        
        B--;
    }
    
    return sum;
}
