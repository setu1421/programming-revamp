void computeLPS(string A, int n, int *lps)
{
    int index = 0;
    for(int i = 1; i < n;)
    {
        if(A[index] == A[i])
        {
            lps[i] = index + 1;
            index++;
            i++;
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

int Solution::solve(string A) {
    string rev_str = A;
    reverse(rev_str.begin(), rev_str.end());
    string concat_str = rev_str + "$" + A;
    
    int n = concat_str.length();
    int lps[n + 1] = {0};
    
    computeLPS(concat_str, n, lps);
    
    int matched_palindrome_count = lps[n - 1];
    
    return A.length() - matched_palindrome_count;
}

/*
Example: Suppose A = “efaba”
Lets form another string B = reverse(A) + “$” + A = “abafe$efaba”
Compute LPS Array
So last value of lps array will be 3 which implie(“aba” is a palindrome)
So we need len(A)-3 appends i.e 2
*/
