// https://www.youtube.com/watch?v=nMaKzLWceFg&t=2111s

string Solution::minWindow(string A, string B) {
    int n = A.length(), m = B.length();
   
    if(m == 0 || m > n)
    {
        return "";
    }
 
    unordered_map<char, int>mp;
    // Save the sequence into map.
    for(int i = 0; i < m; i++)
    {
        mp[B[i]]++;
    }
 
    int i = 0, j = 0, min_window = INT_MAX, count = 0, window_start = 0;
 
    while(j < n)
    {
		// If the character of the sequence is found in the map. 
        if(mp.find(A[j]) != mp.end())
        {
			// Decrement the count in the map for that character.
            mp[A[j]]--;
            // If the character is part of the matched sequence, then increment count.
			// For example: A -> AAABC B-> ABC, so we won't take increment count for A after taking one A.
            if(mp[A[j]] >= 0)
            {
                count++;
            }
            // if we have matched all the characters with same count.
            while(count == m)
            {
                int curr_len = j - i + 1;
                
                if(min_window > curr_len)
                {
                    min_window = curr_len;
                    window_start = i;
                }
                // if the first character of the current window is of matched sequence,
				// then increment the character count in the map as we will be sliding the window to next character.
                if(mp.find(A[i]) != mp.end())
                {
                    mp[A[i]]++;
					// Decrement the count as we are removing a character from the window which was counted before.
                    if(mp[A[i]] > 0)
                    {
                        count--;
                    }
                }
                // Shrinking the window from left.
                i++;
            }
        }
        
        j++;
 
    }
    
    if(min_window == INT_MAX)
    {
        return "";
    } else
    {
       return A.substr(window_start, min_window); 
    }
}