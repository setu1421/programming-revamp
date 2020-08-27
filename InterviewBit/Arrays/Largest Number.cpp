bool mycompare(string a, string b)
{
    return (a + b) > (b + a);
}

string Solution::largestNumber(const vector<int> &A) {
    vector<string>v;
    string result;
    
    for(int i = 0; i < A.size(); i++)
    {
        v.push_back(to_string(A[i]));
    }
    
    sort(v.begin(), v.end(), mycompare);
    
    bool firstNonZeroFound = false;
    for(int i = 0; i < v.size(); i++)
    {
        if(stoi(v[i]) == 0 && !firstNonZeroFound)
        {
            continue;
        } else
        {
            firstNonZeroFound = true;
        }
        
        result += v[i];
    }
    
    if(result == "")
    {
        result = "0";
    }
    
    return result;
}
