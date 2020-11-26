void maximalStr(string &ans, string &str, int index, int B)
{
    if(B == 0)
    {
        return;
    }
    
    for(int i = index; i < str.length() - 1; i++)
    {
        for(int j = i + 1; j < str.length(); j++)
        {
            swap(str[i], str[j]);
            if(str >= ans)
            {
                ans = str;
            }
            maximalStr(ans, str, index + 1, B - 1);
            swap(str[i], str[j]);
        }
    }
}

string Solution::solve(string A, int B) {
    string ans;
    
    maximalStr(ans, A, 0, B);
    
    return ans;
}
