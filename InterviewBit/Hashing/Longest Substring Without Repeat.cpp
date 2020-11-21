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
