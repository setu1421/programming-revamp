int Solution::braces(string A) {
    int n = A.length();
    stack<char>st;
    
    for(int i = 0; i < n; i++)
    {
        if(A[i] == ')')
        {
			// if there is no operator between opening and closed brace, then this is redundant
            if(st.top() == '(')
            {
                return 1;
            } else
            {
				// pop the operator and opening brace
                st.pop();
                st.pop();
            }
        } else if(A[i] == '(' || A[i] == '+' || A[i] == '-' || A[i] == '*' || A[i] == '/')
        {
            st.push(A[i]);
        }
    }
    
    return 0;
}
