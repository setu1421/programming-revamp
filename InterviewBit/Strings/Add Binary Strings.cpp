string Solution::addBinary(string A, string B) {
    int m = A.length();
    int n = B.length();

    int i = m - 1, j = n - 1, carry = 0;
    string res = "";
    
    while(i >= 0 || j >= 0)
    {
        int s1 = (i >= 0) ? A[i] - '0' : 0;
        int s2 = (j >= 0) ? B[j] - '0' : 0;
        int sum = s1 + s2 + carry;
        // Sum = (a + b + c) % 2
        // Carry = (a + b + c ) / 2
        carry = sum / 2;
        res += (sum % 2) + '0';
        i--;
        j--;
    }
    
    if(carry == 1)
    {
        res += carry + '0';
    }
    
    reverse(res.begin(), res.end());
    
    return res;
}
