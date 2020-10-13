int Solution::solve(string A) {
    stack<char>st;
    int n = A.length();
    
    st.push(A[0]);
    
    for(int i = 1; i < n; i++)
    {
        if(!st.empty() && st.top() == '(' && A[i] == ')')
        {
            st.pop();
        } else 
        {
            st.push(A[i]);
        }
    }
    
    return st.size();
}
