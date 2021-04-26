string Solution::findDigitsInBinary(int A) {
    vector<int>ans;
    string sol = "";
    
    if(A == 0)
       return to_string(0);
    if(A == 1)
        return to_string(1);
    
    while(A > 0)
    {
        if(A%2==0)
        {
            ans.push_back(0);
        }
        else
        {
            ans.push_back(1);
        }
        A=A/2;
    }
      
    for(int i = ans.size() - 1;i >= 0;i--)
    {
        sol += to_string(ans[i]);
    }
    
    return sol;
}
