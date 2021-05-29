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
        res.push_back(partitions);
        return;
    }
    // partition the string at all lengths less than the string length.
	// Suppose, partition the string for one length and then partition the rest of string again with 1 to length of that rest string.
	// Finally, after back track, partition the string again with two length and then partition the rest of string again with 1 to length of that rest string.
	// and so on..
    for(int i = 1; i + index <= A.length(); i++)
    {
        string temp = A.substr(index, i);
        if(checkPalindrome(temp, palindrome_mp))
        {
            partitions.push_back(temp);
            partitionUtil(palindrome_mp, res, A, partitions, index + i);
            partitions.pop_back(); 
        }
    }
}
 
vector<vector<string> > Solution::partition(string A) {
   vector<vector<string> > res;
   vector<string>partitions;
   unordered_map<string, bool>palindrome_mp;
   
   partitionUtil(palindrome_mp, res, A, partitions, 0);
   
   
   return res;
}

/*
Here is the number of recursive calls:
T(n) = T(n-1) + T(n-2) + … + T(0) => T(n)=2 * (T(n-2) + T(n-3) + …) = 4 * (T(n-3) + …) = 8 * (T(n-4) + …) = 2^(n-1)
total O(2^n) recursive calls.
For every call we do: 1) check ifPalindrome O(length); 2) create substring O(length)

So, total time complexity will be O(n * 2^n)
/*