string Solution::longestPalindrome(string A) {
    int n = A.length();
    
    if(n == 0) return "";
    
    string best_str = "";
    int best_len = 0;
    int best_start = INT_MAX;
    
    for(int mid = 0; mid < n; mid++)
    {
        for(int x = 0; mid - x >= 0 && mid + x < n; x++)
        {
            if(A[mid - x] != A[mid + x])
            {
                break;
            }
            
            int len = 2 * x + 1;
            
            if(len > best_len)
            {
                best_len = len;
                best_str = A.substr(mid - x, len);
                best_start = mid - x;
            } else if(len == best_len && mid - x < best_start)
            {
                best_start = mid - x;
                best_str = A.substr(mid - x, len);
            }
        }
    }
    
    for(int mid = 0; mid < n; mid++)
    {
        for(int x = 1; mid - x + 1 >= 0 && mid + x < n; x++)
        {
            if(A[mid - x + 1] != A[mid + x])
            {
                break;
            }
            
            int len = 2 * x;
            
            if(len > best_len)
            {
                best_len = len;
                best_str = A.substr(mid - x + 1, len);
                best_start = mid - x + 1;
            } else if(len == best_len && mid - x + 1 < best_start)
            {
                best_start = mid - x + 1;
                best_str = A.substr(mid - x + 1, len);
            }
        }
    }
    
    return best_str;
}
