/*
	Do check
	a) If your code responds correctly to the signs.
	+7 -----> 7
	-7 -----> -7
	-+7 -----> 0

	b) Check for other characters
	m7 -----> 0
	7m -----> 7
	"7 ----> 0
	7; -----> 7

	c) Do check for the leading whitespaces, ignore them and store the number, after storing a number, if a whitespace (or any other character) is encountered, then stop storing further.

	d) Check the overflow condition
	12345678918 -----> 2147483647
	-12345678918 -----> -2147483648
*/

bool isNumber(char ch)
{
    if(ch >= '0' && ch <= '9')
    {
        return true;
    } else 
    {
        return false;
    }
}

int Solution::atoi(const string A) {
    int n = A.length();
    
    // Ignore any whitespace before the number
    int i  = 0;
    while(i < n && A[i] == ' ')
    {
        i++;
    }
    
    // Check if there is any sign present for the number
    bool isPositive = true;
    if(A[i] == '+')
    {
        i++;
    } else if(A[i] == '-')
    {
        isPositive = false;
        i++;
    }
    
    // Check whether the first character is a number or not
    if(!isNumber(A[i]))
    {
        return 0;
    } else
    {
        long long ans = 0;
        
        // Find the number till we don't get any non numeric character
        while(i < n && isNumber(A[i]))
        {
            ans = ans * 10 + (A[i] - '0');
            // Check if the answer is greater than INT_MAX
            if(ans > INT_MAX)
            {
                return (isPositive) ? INT_MAX : INT_MIN;
            }
            
            i++;
        }
        
        return (isPositive) ? ans : ans * (-1);
    }
    
    return 0;
}
