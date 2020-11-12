string Solution::simplifyPath(string A) {
    int n = A.length();
    stack<string>st;
    
    for(int i = 0; i < n; i++)
    {
		// If the current character is '/' then ignore.
        if(A[i] == '/')
        {
            continue;
        }
        // If the current character is '.', then check whether if next character is dot or not.
		// If yes, then pop from stack to go to the parent directory
        if(A[i] == '.')
        {
            if(i + 1 < n && A[i + 1] == '.')
            {
                if(!st.empty())
                {
                    st.pop();
                }
                i++;
            }
        } else
        {
			// Build the directory name and add to stack.
            string temp = "";
            while(i < n && A[i] != '/')
            {
                temp += A[i];
                i++;
            }
            
            st.push(temp);
        }
    }
    
	// Need to reverse the stack to avoid TLE
	// ans = st.top() + ans will throw TLE. So to contact like ans += st.top(), reversing the stack.
    stack<string>reverse_st;
    while(!st.empty())
    {
        reverse_st.push(st.top());
        st.pop();
    }
    
    
    string ans = "";
    
    while(!reverse_st.empty())
    {
        ans += '/' + reverse_st.top();
        reverse_st.pop();
    }
    
    return (ans == "" ? "/" : ans);
}
