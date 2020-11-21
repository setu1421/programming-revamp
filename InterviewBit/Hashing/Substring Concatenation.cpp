// https://www.youtube.com/watch?v=Mv5UNKdKwz4

void spliceWords(unordered_map<string, int>&mp, string str, int len)
{
    int n = str.length(), i = 0;
    
    while(i <= n - len)
    {
        string temp = str.substr(i, len);
        mp[temp]++;
        i = i + len;
    }
}


bool checkIfAllWordsFound(unordered_map<string, int> word_mp, unordered_map<string, int> word_sub_mp)
{
    if(word_mp.size() != word_sub_mp.size())
    {
        return false;
    }
    
    for(auto word: word_mp)
    {
        if(word_sub_mp.find(word.first) == word_sub_mp.end())
        {
            return false;
        } else if(word_sub_mp[word.first] != word.second)
        {
            return false;
        }
    }
    
    return true;
}


vector<int> Solution::findSubstring(string A, const vector<string> &B) {
    int n = A.length();
    int words = B.size();
    
    vector<int>res;
    
    if(n == 0 || words == 0)
    {
        return res;
    }
    
    unordered_map<string, int>word_mp;
    // Hash the words to be matched.
    for(int i = 0; i < words; i++)
    {
        word_mp[B[i]]++;
    }
    // Calculated the total length to be matched.
    int word_len = B[0].length();
    int t_len = words * word_len;
    int i = 0;
    // Take substring of total length and match if all the words present or not in that substring
    while(i <= n - t_len)
    {
        string temp = A.substr(i, t_len);
        unordered_map<string, int>word_sub_mp;
        // splice the words present in the substring
        spliceWords(word_sub_mp, temp, word_len);
		// check if all the words found in the substring or not.
        if(checkIfAllWordsFound(word_mp, word_sub_mp))
        {
            res.push_back(i);
        }
    
        i++;
    }
    
  return res;  
}
