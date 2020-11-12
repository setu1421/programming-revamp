int Solution::evalRPN(vector<string> &A) {
    int n = A.size();
    stack<int>st;
    
    for(int i = 0; i < n; i++)
    {
        if(A[i] == "+" || A[i] == "-" || A[i] == "*" ||A[i] == "/")
        {
            int x = st.top();
            st.pop();
            int y = st.top();
            st.pop();
            //https://stackoverflow.com/questions/4535825/error-switch-quantity-not-an-integer
            switch(A[i][0])
            {
                case '+': st.push(y + x); break;
                case '-': st.push(y - x); break;
                case '*': st.push(y * x); break;
                case '/': st.push(y / x); break;
            }
        } else
        {
            st.push(stoi(A[i]));
        }
    }
    
    return st.top();
}
