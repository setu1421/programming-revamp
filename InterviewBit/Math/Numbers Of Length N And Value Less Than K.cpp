// https://www.youtube.com/watch?v=MT8zeLak_bI
int noOfDigits(int C)
{
    int count = 0;
    
    while(C > 0)
    {
        count++;
        C /= 10;
    }
    
    return count;
}

void splitDigitsToArray(vector<int>&temp, int C, int d_C)
{
    for(int i = d_C - 1; i >= 0; i--)
    {
        temp[i] = C % 10;
        C /= 10;
    }
}

bool digitPresent(vector<int>&A, int digit, int n)
{
    for(int i = 0; i < n; i++)
    {
        if(A[i] == digit)
        {
            return true;
        }
    }
    
    return false;
}


int Solution::solve(vector<int> &A, int B, int C) {
    int n = A.size();
    int count, ans = 0;
    
    // Case 0: When array is empty
    if(n == 0)
    {
        return 0;
    }
    
    int d_C = noOfDigits(C);
    
    // Case 1: When B is greater than count of digits in C
    if(B > d_C)
    {
        return 0;
    }
    // Case 2: When B is less than count of digits in C
    if(B < d_C)
    {
        
        // If 0 present, then we should ignore 0 in the first place
        if(A[0] == 0)
        {
            ans = (n - 1) * pow(n, B - 1);
        } else
        {
            ans = pow(n, B);
        }
        
        // If we need to consider number of having one digit, then we should consider 0
        if(B == 1 && A[0] == 0)
        {
            ans++;
        }
        
        return ans;
    }
    
    // Case 3: When B is equal to count of digits in C
    // If only one digit needs to consider
    if(B == 1)
    {
        count = 0;
        
        for(int i = 0; i < n; i++)
        {
            if(A[i] < C)
            {
                count++;
            }
        }
        
        return count;
    } else 
    {
        // Split the digits
        vector<int>temp(B);
        splitDigitsToArray(temp, C, d_C);
        
        // Calculate counts less than the first digit of C
        // Let's say B = 3 and A = {0, 1, 2, 3, 4} and C = 223
        // So, we will at first count upto 144
        int j = 0, count = 0, flag = false;
        
        for(int i = 0; i < n; i++)
        {
            if(A[i] == 0)
            {
                continue;
            } else if(A[i] >= temp[j])
            {
                break;
            } else
            {
                count++;
            }
        }
        
        ans += count * pow(n, B - 1);
        
        // Now, we have to add the extra counts 145 to 222
        
        // First to check if the first digit of C is present or not. 
        // If not, then no need to check for next digits
        flag = digitPresent(A, temp[j], n);
        
        if(!flag)
        {
            return ans;
        } else
        {
            j++;
            
            while(flag && j <= B - 1)
            {
                count = 0; flag = false;
                for(int i = 0; i < n; i++)
                {
                    if(A[i] < temp[j])
                    {
                        count++;
                    } else if(A[i] == temp[j])
                    {
                        flag = true;
                    } else
                    {
                        break;
                    }
                }
                
                ans += (count * pow(n, B - j - 1));
                j++;
            }
            
            return ans;
        }
    }
}
