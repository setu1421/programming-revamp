// https://www.youtube.com/watch?v=DzxYFza8Xts
/*
 Suppoer the number is CZB
 Number = s0 + s1 * 26 + s2 * (26 ^ 2) // s0 = B, s1 = Z, s2 = C
 
 Now, if we take reminder by 26, we can get two types of value. One is (1 - 25) and another is 0 (Z)
 Now, we have to divide by 26 to take s1 in the next step.
 Dividing by 26
 
 Number = s1 + s2 * 26 // (s0/26 will be 0)
 
 if we take reminder, then we will get s1. Now s1 is Z, so the remainder will be 0. If we divide by 26, then s1 will not be 0 rather it will be 1. So,
 to remove s1, we have to subtract 26 from the number and then divide by 26. (This is a special case)
 
 Number = s2;
 
 Final Reverse String = s2s1s0
 
*/
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
