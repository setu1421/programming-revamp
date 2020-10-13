string Solution::countAndSay(int A) {
    if(A == 1) return "1";
    if(A == 2) return "11";
    
    string res = "11";
    
    for(int i = 3; i <= A; i++)
    {
        int count = 1;
        int len = strlen(res.c_str());
        string temp = "";
        
        for(int j = 1; j < len; j++)
        {
            if(res[j] != res[j - 1])
            {
                temp += count + '0';
                temp += res[j - 1];
                count = 1;
            } else
            {
                count++;
            }
        }
        // Add count for the last character
        temp += count + '0';
        temp += res[len - 1];
        
        res = temp;
    }
    
    return res;
}
