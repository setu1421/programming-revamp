int Solution::lengthOfLongestSubstring(string A) {
    int n = A.length(), max_len = 0;
    
    unordered_map<char, int>mp;
    
    int i = 0, j = 0;
    
    while(i < n && j < n)
    {
		// If the character is not seen before, then hash it with the index and updated the max_len.
        if(mp.find(A[j]) == mp.end())
        {
            mp[A[j]] = j;
            max_len = max(max_len, j - i + 1);
            j++;
        } // If the character is seen before, then we go into the next window from where duplicate not present.
		else
        {
            int temp = mp[A[j]] + 1;
			// erase all the keys of the previous window.
            for(int k = i; k < temp; k++)
            {
                mp.erase(A[k]);
            }
            // next window start will be the index after the duplicate character.
            i = temp;
        }
    }
    
    return max_len;
}

// Better Approach: Without erasing the keys.
int Solution::lengthOfLongestSubstring(string A)
{
    int n = A.size();
    int i = -1, j = 0;
    int max_len = 1;
    unordered_map<char,int> map;
    
    while(j < n)
    {
		// If we find the same character, then we need to decrease the window to the maximum index to get window with unique characters.
		// For example: abcac. when we get c character, i will be at 0, mp[c] is 2, so we will take 2 to get window with unique characters.
        if(map.find(A[j]) != map.end())
        {
            i = max(i, map[A[j]]);
        }

        max_len = max(max_len, j - i);
        map[A[j]] = j;
        j++;
    }

    return max_len;
}
