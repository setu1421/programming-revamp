int Solution::isValid(string A) {
    int n = A.length();
    stack<char>st;
    
    for(int i = 0; i < n; i++)
    {
        if(A[i] == '(' || A[i] == '{' || A[i] == '[')
        {
            st.push(A[i]);
        } else
        {
            if(st.empty())
            {
                return 0;
            } else
            {
                if((A[i] == ')' && st.top() == '(') || (A[i] == '}' && st.top() == '{') || (A[i] == ']' && st.top() == '['))
                {
                    st.pop();
                } else
                {
                    return 0;
                }
            }
        }
    }
    
    return (st.empty() ? 1: 0);
}
