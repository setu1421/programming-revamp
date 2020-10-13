//https://www.geeksforgeeks.org/converting-roman-numerals-decimal-lying-1-3999/#:~:text=Algorithm%20to%20convert%20Roman%20Numerals%20to%20Integer%20Number%3A&text=Take%20symbol%20one%20by%20one,symbol%20to%20the%20running%20total.

int getRomanValue(char ch)
{
    if(ch == 'I') return 1;
    if(ch == 'V') return 5;
    if(ch == 'X') return 10;
    if(ch == 'L') return 50;
    if(ch == 'C') return 100;
    if(ch == 'D') return 500;
    if(ch == 'M') return 1000;
}

int Solution::romanToInt(string A) {
    int n = A.length();
    int res = 0;
    
    for(int i = 0; i < n; i++)
    {
        int curr = getRomanValue(A[i]);
        
        if(i + 1 < n)
        {
            int next = getRomanValue(A[i + 1]);
            // Check whether IV, IX etc. present or not.
			// In that case, we have to add V and subtract I
            if(curr >= next)
            {
                res += curr;
            } else
            {
                res += (next - curr);
                i++;
            }
        } else
        {
            res += curr;
        }
    }
    
    return res;
}
