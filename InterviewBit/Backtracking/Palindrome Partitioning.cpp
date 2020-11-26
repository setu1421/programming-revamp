bool checkPalindrome(string str, unordered_map<string, bool> &palindrome_mp)
{
    if(palindrome_mp.find(str) != palindrome_mp.end())
    {
        return palindrome_mp[str];
    }
    
    int i = 0, j = str.length() - 1;
    bool isPalindrome = true;
    
    while(i < j)
    {
        if(str[i] != str[j])
        {
            isPalindrome = false;
            break;
        }
        
        i++;
        j--;
    }
    
    palindrome_mp.insert(make_pair(str, isPalindrome));
    
    return isPalindrome;
}
 
void partitionUtil(unordered_map<string, bool> &palindrome_mp, vector<vector<string> > &res, string A, vector<string> &partitions, int index)
{
    if(index == A.length())
    {
        bool isAllPalindrome = true;
        
        for(string str: partitions)
        {
            if(!checkPalindrome(str, palindrome_mp))
            {
                isAllPalindrome = false;
                break;
            }
        }
        
        if(isAllPalindrome)
        {
            res.push_back(partitions);
        }
        
        return;
    }
    // partition the string at all lengths less than the string length.
	// Suppose, partition the string for one length and then partition the rest of string again with 1 to length of that rest string.
	// Finally, after back track, partition the string again with two length and then partition the rest of string again with 1 to length of that rest string.
	// and so on..
    for(int i = 1; i + index <= A.length(); i++)
    {
        partitions.push_back(A.substr(index, i));
        partitionUtil(palindrome_mp, res, A, partitions, index + i);
        partitions.pop_back();
    }
}
 
vector<vector<string> > Solution::partition(string A) {
   vector<vector<string> > res;
   vector<string>partitions;
   unordered_map<string, bool>palindrome_mp;
   
   partitionUtil(palindrome_mp, res, A, partitions, 0);
   
   
   return res;
}