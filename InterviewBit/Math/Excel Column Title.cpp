string Solution::convertToTitle(int A) {
    string ans = "";
    
    while(A > 0)
    {
        int rem = A % 26;
        // Tricky case when the remainder is zero
        // when u get a%26==0,instead of use 0,use it as 26,and decrease the num by 26,like a=a-26;
        // For example: 52
        if(rem == 0)
        {
            ans += 'Z';
            A -= 26;
        } else
        {
            ans += 'A' + rem - 1;
        }
        
        
        
        A /= 26;
    }
    
    reverse(ans.begin(), ans.end());
    
    return ans;
}
