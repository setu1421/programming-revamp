vector<int> Solution::slidingMaximum(const vector<int> &A, int B) {
    int n = A.size();
    deque<int>q;
    vector<int>ans;
    // Corner Cases
    if(B == 1) return A;
    if(B > n)
    {
        int max_elem = *max_element(A.begin(), A.end());
        ans.push_back(max_elem);
        return ans;
    }
    
    for(int i = 0; i < n; i++)
    {
        // pop from the back of the queue if the current element is greater than the queue back
        // This is done to keep only the potential max elements
        while(!q.empty() && A[q.back()] <= A[i])
        {
            q.pop_back();
        }
        
        q.push_back(i);
        
        if(i >= B)
        {
            // if max element is going out from sliding window, then pop that from queue.
            if(q.front() == i - B)
            {
                q.pop_front();
            }
        }
        
        // for each sliding window, take the front element of queue which is maximum and 
        // and push it for answer.
        if(i >= B - 1)
        {
            ans.push_back(A[q.front()]);
        }
    }
    
    return ans;
}
