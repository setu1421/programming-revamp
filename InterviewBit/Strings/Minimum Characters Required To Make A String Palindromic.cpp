// https://www.geeksforgeeks.org/minimum-characters-added-front-make-string-palindrome/
void computeLPS(string str, int n, int *lps)
{
    int index = 0;
    
    for(int i = 1; i < n;)
    {
        if(str[i] == str[index])
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

int Solution::solve(string A) {
    string rev_str = A;
    reverse(rev_str.begin(), rev_str.end());
    string concat_str = A + '$' + rev_str;
    
    int n = concat_str.length();
    int lps[n] = {0};
    computeLPS(concat_str, n, lps);
    
    int matched_palindrome_count = lps[n - 1];
    
    
    return A.length() - matched_palindrome_count;
}
