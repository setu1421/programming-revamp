int Solution::solve(string A) {
    int n = A.length();
    stack<char>st;
    
    for(int i = 0; i < n; i++)
    {
        if(A[i] == '(')
        {
            st.push(A[i]);
        } else
        {
            if(!st.empty() && st.top() == '(')
            {
                st.pop();
            } else
            {
                return 0;
            }
        }
    }
    
    if(st.size() > 0)
    {
        return 0;
    } else
    {
        return 1;
    }
}
