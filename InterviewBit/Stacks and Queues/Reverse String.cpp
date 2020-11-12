string Solution::reverseString(string A) {
    int n = A.length();
    stack<char>st;
    
    for(int i = 0; i < n; i++)
    {
        st.push(A[i]);
    }
    
    string res = "";
    
    while(!st.empty())
    {
        res += st.top();
        st.pop();
    }
    
    return res;
}
