string divideBy2(string A, int n)
{
    string ans = "";
    int carry = 0;
    
    for(int i = 0; i < n; i++)
    {
        int num = A[i] - '0';
        // Add the carry.
        // For example: 136. Carry will be 1 and next to divide will be 16
        num = num + carry * 10;
        carry = num % 2;
        ans += (num / 2) + '0';
    }
    
    // Remove any zeros from the start. 
    // For example: 16. ans will be "08"
    while(ans.length() > 0 && ans[0] == '0')
    {
        ans.erase(ans.begin());
    }
    
    return ans;
}

int Solution::power(string A) {
    // If string contains only 1 or 0, then return 0
    if(A == "1" || A == "0")
    {
        return 0;
    }
    
    int n = A.length();
    
    while(1)
    {
        // For example: 2, 8, 16 etc. After all divisions, it will come down to 1
        if(n == 1 && A[0] == '1')
        {
            break;
        }
        
        int lastDigit = A[n - 1] - '0';
        if(lastDigit % 2 != 0)
        {
            return 0;
        } else
        {
            A = divideBy2(A, n);
            n = A.length();
        }
    }
    
    return 1;
}
