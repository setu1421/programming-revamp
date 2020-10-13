// https://leetcode.com/problems/multiply-strings/discuss/17605/Easiest-JAVA-Solution-with-Graph-Explanation
string Solution::multiply(string A, string B) {
    int m = A.length(), n = B.length();
    string ans(m + n, '0');
    
    for(int i = m - 1; i >= 0; i--)
    {
        for(int j = n - 1; j >= 0; j--)
        {
            int sum = (A[i] - '0') * (B[j] - '0') + (ans[i + j + 1] - '0');
            ans[i + j + 1] = (sum % 10) + '0'; // sum
            ans[i + j] = ((ans[i + j] - '0') + (sum / 10)) + '0'; // carry
        }
    }
    
    for(int i = 0; i < m + n; i++){
        if(ans[i] !='0') 
        {
            return ans.substr(i);
        }
    }
        
    return "0";

}
