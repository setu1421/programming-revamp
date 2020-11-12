vector<int> Solution::prevSmaller(vector<int> &A) {
    int n = A.size();
    stack<int>st;
    vector<int>ans;
    
    st.push(A[0]);
    ans.push_back(-1);
    
    for(int i = 1; i < n; i++)
    {
        while(!st.empty() && A[i] <= st.top())
        {
            st.pop();
        }
        
        if(st.empty())
        {
            ans.push_back(-1);
        } else
        {
            ans.push_back(st.top());
        }
        
        st.push(A[i]);
    }
    
    return ans;
}
