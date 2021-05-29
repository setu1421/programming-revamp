void letterCombUtil(vector<string> &res, vector<string> letters, string A, int pos, string s)
{
    if(pos == A.length())
    {
        res.push_back(s);
        return;
    }
    // Iterate all the letters for that number in this position and move for next position.
    for(auto c: letters[A[pos] - '0'])
    {
        s += c;
        letterCombUtil(res, letters, A, pos + 1, s);
        s.pop_back();
    }
}

vector<string> Solution::letterCombinations(string A) {
    vector<string> res;
    vector<string> letters = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    letterCombUtil(res, letters, A, 0, "");
    sort(res.begin(), res.end());
    
    return res;
}

// Iterative Version using queue.
vector<string> Solution::letterCombinations(string A) {
    vector<string> res;
    vector<string> letters = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
   
    queue<string> q;
    q.push("");
    
    for(int i = 0; i < A.length(); i++)
    {
        string digitVal = letters[A[i] - '0'];
        
        while(!q.empty() && q.front().length() == i)
        {
            string s = q.front();
            q.pop();
            
            for(int j = 0; j < digitVal.length(); j++)
            {
                q.push(s + digitVal[j]);
            }
        }
    }
    
    while(!q.empty())
    {
        res.push_back(q.front());
        q.pop();
    }
    
    sort(res.begin(), res.end());
    
    return res;
}

