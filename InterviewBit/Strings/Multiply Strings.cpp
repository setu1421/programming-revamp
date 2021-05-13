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

/* For input ""99" and "99"
Array will look like below:

Before -> [0, 0, 0, 0]
After -> [0, 0, 8, 1]
=================
Before -> [0, 0, 8, 1]
After -> [0, 8, 9, 1]
=================
Before -> [0, 8, 9, 1]
After -> [0, 17, 0, 1]
=================
Before -> [0, 17, 0, 1]
After -> [9, 8, 0, 1]
=================

 The calculation is from right to left, even though pos[p1] >= 10. it's still Ok, because current p1 will be p2 in next step, the % operation will always get right result in p2 position. finally, the overflow will end at head, but it will not overflow again. For example, 99 * 99 = 9801, 2 digit number multiplication, the result length will not exceed 4 digit.
 */
