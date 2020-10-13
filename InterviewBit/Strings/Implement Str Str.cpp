// Time complexity: O(mn) -- Brute Force Approach
// m = length of text A, n = length of pattern B
int Solution::strStr(const string A, const string B) {
    int lenA = strlen(A.c_str());
    int lenB = strlen(B.c_str());
    
    if(lenA == 0 || lenB == 0 || lenA < lenB)
    {
        return -1;
    }
    
    int needle_start = B[0];
    
    for(int i = 0; i < lenA; i++)
    {
        if(A[i] == needle_start)
        {
            int j = i + 1, k = 1;
            
            while(j < lenA && k < lenB && A[j] == B[k])
            {
                j++;
                k++;
            }
            
            if(k == lenB)
            {
                return i;
            }
        }
    }
    
    return -1;
}

// Best Approach: Using KMP
// Time Complexity: O(m + n)
// https://www.youtube.com/watch?v=GTJr8OvyEVQ
void preComputeLPS(int *lps, string pattern, int len)
{
    int index = 0;
    
    for(int i = 1; i < len;)
    {
        if(pattern[i] == pattern[index])
        {
            lps[i] = index + 1;
            i++;
            index++;
        } else 
        {
            if(index != 0)
            {
                index = lps[index - 1];
            } else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

int Solution::strStr(const string A, const string B) {
    int lenText = strlen(A.c_str());
    int lenPattern = strlen(B.c_str());
    
    if(lenText == 0 || lenPattern == 0 || lenText < lenPattern)
    {
        return -1;
    }
    
    int lps[lenPattern] = {0};
    
    preComputeLPS(lps, B, lenPattern);
    
    int i = 0, j = 0;
    
    while(i < lenText && j < lenPattern)
    {
        if(A[i] == B[j])
        {
            i++;
            j++;
        } else
        {
            if(j != 0)
            {
                j = lps[j - 1];
            } else
            {
                i++;
            }
        }
    }
    
    if(j == lenPattern)
    {
        return (i - lenPattern);
    } else
    {
        return -1;
    }
}
